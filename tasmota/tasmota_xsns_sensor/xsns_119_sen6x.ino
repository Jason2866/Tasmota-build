/*
  xsns_119_sen6x.ino - SEN6X environmental sensor node support for Tasmota

  SPDX-FileCopyrightText: 2026 Theo Arends

  SPDX-License-Identifier: GPL-3.0-only
*/

#ifdef USE_I2C
#ifdef USE_SEN6X
/*********************************************************************************************\
 * SEN6X - Humidity, Temperature, Particulates (PM) and 
 *         Gas (CO2 CarbonDioxide / VOC Volatile Organic Compounds / NOx Nitrous Oxides / HCHO Formaldehyde)
 *
 * Different SEN6x products use different I2C function for `ReadMeasuredValue` hence this driver
 *  currently only supports product SEN66 on either I2C bus1 or bus2
 * Product  Supported  PM     RH&T   CO2    VOC/NOx  HCHO   Notes
 * -------  ---------  -----  -----  -----  -------  -----  -------------------------
 * SEN62       -       SPS6x  SHT4x  -      -        -
 * SEN63C      -       SPS6x  SHT4x  STCC4  -        -      Used in Ikea ALPSTUGA
 * SEN65       -       SPS6x  SHT4x  -      SGP41    -
 * SEN66      Yes      SPS6x  SHT4x  SCD4x  SGP41    -      Uses better CO2 sensor
 * SEN68       -       SPS6x  SHT4x  -      SGP41    SFA40
 * SEN69C      -       SPS6x  SHT4x  STCC4  SGP41    SFA40
 *
 * I2C Address: 0x6B
\*********************************************************************************************/

#define XSNS_119                         119
#define XI2C_97                          97    // See I2CDEVICES.md

#include <SensirionI2cSen66.h>

#define SEN6X_STATE_READ_MEASUREMENT     0
#define SEN6X_STATE_START_MEASUREMENT    2     // Wait at least 1s after start measurement
#define SEN6X_STATE_CLEAN_FAN_WAIT       11    // Wait at least 10s after the start of the fan before starting a measurement
#define SEN6X_STATE_SHT_HEATER_WAIT      21    // Wait at least 20s after the activation of the heater before starting a new measurement to get coherent temperature values

SensirionI2cSen66 *sen6x = nullptr;

struct SEN6XDATA_s {
  float massConcentrationPm1p0;
  float massConcentrationPm2p5;
  float massConcentrationPm4p0;
  float massConcentrationPm10p0;
  float ambientHumidity;
  float ambientTemperature;
  float vocIndex;
  float noxIndex;
  uint16_t co2;
  uint8_t state;
  uint8_t major;
  uint8_t minor;
  char name[6];
} *SEN6XDATA = nullptr;

/********************************************************************************************/

uint32_t ParseIntParameters(uint32_t count, int *params) {
  // Destroys XdrvMailbox.data
  char *p;
  uint32_t i = 0;
  for (char *str = strtok_r(XdrvMailbox.data, ", ", &p); str && i < count; str = strtok_r(nullptr, ", ", &p), i++) {
    params[i] = strtol(str, nullptr, 0);
  }
  return i;
}

void Sen6xStopStartMeasurement(void) {
  // Stop measurement and restart after 1 second
  sen6x->stopMeasurement();                                      // Performs internal delay(1000)
  SEN6XDATA->state = SEN6X_STATE_START_MEASUREMENT;
}

bool Sen6xError(const char* func, int error) {
  bool result = (error != 0);
  if (result) {
    AddLog(LOG_LEVEL_DEBUG, PSTR("S6X: %s error %d"), func, error);
  }
  return result;
}

bool CmndSen6xError(int error) {
  bool result = (error != 0);
  if (result) {
    ResponseCmnd();
    ResponseAppend_P(PSTR("{\"Error\":%d}"), error);
  }
  return result;
}

/********************************************************************************************/

void Sen6xInit(void) {
  for (uint32_t bus = 0; bus < 2; bus++) {
    if (!I2cSetDevice(SEN66_I2C_ADDR_6B, bus)) { 
      Sen6xError("Scan", 1);
      continue;
    }
    sen6x = new SensirionI2cSen66();
    sen6x->begin(I2cGetWire(bus), SEN66_I2C_ADDR_6B);

    if (Sen6xError("Reset", sen6x->deviceReset())) {   // Performs delay(1200) if no error
      continue;
    }

    uint8_t major;
    uint8_t minor;
    if (Sen6xError("Version", sen6x->getVersion(major, minor))) {
      continue;
    }

    int8_t serial_number[32] = { 0 };
    if (Sen6xError("Serialnumber", sen6x->getSerialNumber(serial_number, sizeof(serial_number)))) {
      continue;
    }

    int8_t product_name[32] = { 0 };
    if (Sen6xError("Productname", sen6x->getProductName(product_name, sizeof(product_name)))) {
      continue;
    }

    // TBD detect correct SEN66 device based on serialnumber/productname/version before continuing.

    SEN6XDATA = (SEN6XDATA_s *)calloc(1, sizeof(struct SEN6XDATA_s));
    SEN6XDATA->major = major;
    SEN6XDATA->minor = minor;
    SEN6XDATA->state = SEN6X_STATE_START_MEASUREMENT;
    strlcpy(SEN6XDATA->name, (char*)product_name, sizeof(SEN6XDATA->name));

    I2cSetActiveFound(SEN66_I2C_ADDR_6B, SEN6XDATA->name, bus);

    AddLog(LOG_LEVEL_DEBUG, PSTR("S6X: %s serialnumber %s v%d.%d"), product_name, serial_number, major, minor);
    return;
  }
}

void Sen6xUpdate(void) {
  int error = 0;
  switch (SEN6XDATA->state) { 
    case SEN6X_STATE_READ_MEASUREMENT:
      {
        error = sen6x->readMeasuredValues(
          SEN6XDATA->massConcentrationPm1p0,    // Mass concentration in μg/m³ for particles smaller than 1.0 μm.
          SEN6XDATA->massConcentrationPm2p5,    // Mass concentration in μg/m³ for particles smaller than 2.5 μm.
          SEN6XDATA->massConcentrationPm4p0,    // Mass concentration in μg/m³ for particles smaller than 4.0 μm.
          SEN6XDATA->massConcentrationPm10p0,   // Mass concentration in μg/m³ for particles smaller than 10.0 μm.
          SEN6XDATA->ambientHumidity,           // Measured humidity in %RH.
          SEN6XDATA->ambientTemperature,        // Measured temperature in degrees celsius.
          SEN6XDATA->vocIndex,                  // Measured VOC Index between 0 and 500.
          SEN6XDATA->noxIndex,                  // Measured NOx Index between 0 and 500.
          SEN6XDATA->co2);                      // Measured CO2 concentration in ppm.
        if (error) {
          AddLog(LOG_LEVEL_DEBUG, PSTR("S6X: Error %d retrieve readings"), error);
        }
      }
      break;
    case SEN6X_STATE_START_MEASUREMENT -1:
      {
        error = sen6x->startContinuousMeasurement();
        if (error != 0) {
          AddLog(LOG_LEVEL_DEBUG, PSTR("S6X: Error %d start measurement"), error);
          SEN6XDATA->state = SEN6X_STATE_START_MEASUREMENT +2;
        }
      }
      break;
  }
  if (SEN6XDATA->state) {
    SEN6XDATA->state--;
  }
}

/*********************************************************************************************\
 * Commands
\*********************************************************************************************/

const char kSen6xCommands[] PROGMEM = "Sen6x|"  // Prefix
  "|Alt|Pres|TempOff|TempAcc|"
  "Cal|Clean|Heat|"
  "VocState|VocTune|NoxTune";

void (* const Sen6xCommand[])(void) PROGMEM = {
  &CmndSen6xState, &CmndSen6xAltitude, &CmndSen6xPressure, &CmndSen6xTemperatureOffset, CmndSen6xTemperatureAcceleration,
  &CmndSen6xCo2SelfCalibration, &CmndSen6xFanClean, &CmndSen6xSHTHeater,
  &CmndSen6xVocState, &CmndSen6xVocAlgorithmTuningParams, &CmndSen6xNoxAlgorithmTuningParams };

void CmndSen6xState(void) {
  Sen6xStopStartMeasurement();                                   // Stop measurement and restart after 1 second

  int8_t productname[32] = { 0 };
  sen6x->getProductName(productname, sizeof(productname));       // No need to stop
  int8_t serial_number[32] = { 0 };
  sen6x->getSerialNumber(serial_number, sizeof(serial_number));  // No need to stop
  SEN66DeviceStatus status;
  sen6x->readDeviceStatus(status);                               // No need to stop

  uint16_t pressure;
  sen6x->getAmbientPressure(pressure);                           // No need to stop
  uint16_t altitude;
  sen6x->getSensorAltitude(altitude);                            // Only in idle mode (stopped measurement)
  uint8_t padding;
  bool calstatus;
  sen6x->getCo2SensorAutomaticSelfCalibration(padding, calstatus);  // Only in idle mode (stopped measurement)

  int16_t voc_io;
  int16_t voc_ltoh;
  int16_t voc_ltgh;
  int16_t voc_gmdm;
  int16_t voc_si;
  int16_t voc_gf;
  sen6x->getVocAlgorithmTuningParameters(voc_io, voc_ltoh, voc_ltgh, voc_gmdm, voc_si, voc_gf);  // Only in idle mode (stopped measurement)

  int16_t nox_io;
  int16_t nox_ltoh;
  int16_t nox_ltgh;
  int16_t nox_gmdm;
  int16_t nox_si;
  int16_t nox_gf;
  sen6x->getNoxAlgorithmTuningParameters(nox_io, nox_ltoh, nox_ltgh, nox_gmdm, nox_si, nox_gf);  // Only in idle mode (stopped measurement)

  Response_P(PSTR("{\"SEN6x\":{\"Name\":\"%s\",\"Serial\":\"%s\",\"Version\":\"%d.%d\",\"Status\":%04X,"
                   "\"CO2\":{\"Altitude\":%d,\"Pressure\":%d,\"AutoCal\":%d},"
                   "\"VOC\":{\"IdxOffset\":%d,\"LearningTime\":{\"Offset\":%d,\"Gain\":%d},\"GatingMaxDur\":%d,\"StdInit\":%d,\"GainFctr\":%d},"
                   "\"NOx\":{\"IdxOffset\":%d,\"LearningTimeOffset\":%d,\"GatingMaxDur\":%d,\"GainFctr\":%d}}}"),
                   productname, serial_number, SEN6XDATA->major, SEN6XDATA->minor, status,
                   altitude, pressure, calstatus,
                   voc_io, voc_ltoh, voc_ltgh, voc_gmdm, voc_si, voc_gf,
                   nox_io, nox_ltoh, nox_gmdm, nox_gf);
}

void CmndSen6xAltitude(void) {
  // Sen6xAlt    - The sensor altitude can be used for pressure compensation in the CO₂ sensor.
  // Sen6xAlt <0..3000> - meter
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3000)) {
    Sen6xStopStartMeasurement();
    if (CmndSen6xError(sen6x->setSensorAltitude(XdrvMailbox.payload))) {
      return;
    }
  }
  CmndSen6xState();
}

void CmndSen6xPressure(void) {
  // Sen6xPres   - Setting an ambient pressure overrides any pressure compensation
  //               based on a previously set sensor altitude.
  // Sen6xPres <700..1200> - hPa
  if ((XdrvMailbox.payload >= 700) && (XdrvMailbox.payload <= 1200)) {
    if (CmndSen6xError(sen6x->setAmbientPressure(XdrvMailbox.payload))) {
      return;
    }
  }
  CmndSen6xState();
}

void CmndSen6xTemperatureOffset(void) {
  // Sen6xTempOff     - This command allows to compensate temperature effects of the design-in at
  //                    customer side by applying custom temperature offsets to the ambient temperature.
  // Sen6xTempOff <+/-offset>,<+/-slope>,<time_constant>,<slot>
  // Sen6xTempOff <+/-offset>,<+/-slope>,<time_constant>,<0..4>
  int value[4] = { 0 };
  if (4 == ParseIntParameters(4, value)) {
    Sen6xStopStartMeasurement();
    if (!CmndSen6xError(sen6x->setTemperatureOffsetParameters(value[0], value[1], value[2], value[3]))) {
      ResponseCmndDone();
    }
  }
}

void CmndSen6xTemperatureAcceleration(void) {
  // Sen6xTempAcc     - This command allows to set custom temperature acceleration parameters of
  //                    the RH/T engine
  // Sen6xTempAcc <k>,<p>,<t1>,<t2>
  uint32_t value[4] = { 0 };
  if (4 == ParseParameters(4, value)) {
    Sen6xStopStartMeasurement();
    if (!CmndSen6xError(sen6x->setTemperatureAccelerationParameters(value[0], value[1], value[2], value[3]))) {
      ResponseCmndDone();
    }
  }
}

void CmndSen6xCo2SelfCalibration(void) {
  // Sen6xCal          - Show current Co2 auto self calibration state
  // Sen6xCal 0        - Turn Co2 auto self calibration OFF
  // Sen6xCal 1        - Turn Co2 auto self calibration ON
  // Sen6xCal 444      - Re-calibrate Co2 sensor with target_value, correction_value
  if (XdrvMailbox.payload > 350) {
    Sen6xStopStartMeasurement();
    delay(400);                        // Wait at least 1400ms
    uint16_t reference = XdrvMailbox.payload;
    uint16_t correction;
    if (!CmndSen6xError(sen6x->performForcedCo2Recalibration(reference, correction))) {
      ResponseCmndNumber(correction);  // FRC = return_value - 0x8000. If the recalibration has failed this returned value is 0xFFFF.
    }
    return;
  }
  else if ((0 == XdrvMailbox.payload) || (1 == XdrvMailbox.payload)) {
    Sen6xStopStartMeasurement();
    if (CmndSen6xError(sen6x->setCo2SensorAutomaticSelfCalibration(XdrvMailbox.payload))) {
      return;
    }
  }
/*
  else if (2 == XdrvMailbox.payload) {
    Sen6xStopStartMeasurement();
    if (CmndSen6xError(sen63->sensorFactoryReset())) {  // Implemented for STCC2 in SEN63C
      return;
    }
  }
*/
  CmndSen6xState();
}

void CmndSen6xVocAlgorithmTuningParams(void) {
  // Sen6xVocTune                      - Show the parameters to customize the VOC algorithm
  // Sen6xVocTune 100,12,12,180,50,230 - Default values
  // Sen6xVocTune <index_offset>,<learning_time_offset_hours>,<learning_time_gain_hours>,<gating_max_duration_minutes>,<std_initial>,<gain_factor>
  // Sen6xVocTune <1..250>,<1..1000>,<1..1000>,<0..3000>,<10..5000>,<1..1000>
  int value[6] = { 0 };
  if (6 == ParseIntParameters(6, value)) {
    Sen6xStopStartMeasurement();
    if (CmndSen6xError(sen6x->setVocAlgorithmTuningParameters(value[0], value[1], value[2], value[3], value[4], value[5]))) {
      return;
    }
  }
  CmndSen6xState();
}

void CmndSen6xNoxAlgorithmTuningParams(void) {
  // Sen6xNoxTune               - Show the parameters to customize the NOx algorithm
  // Sen6xNoxTune 1,12,720,230  - Default values
  // Sen6xNoxTune <index_offset>,<learning_time_offset_hours>,<gating_max_duration_minutes>,<gain_factor>
  // Sen6xNoxTune <1..250>,<1..1000>,<0..3000>,<1..1000>
  int value[4] = { 0 };
  if (4 == ParseIntParameters(4, value)) {
    Sen6xStopStartMeasurement();
    uint16_t ltgh = 12;  // This parameter has no impact for NOx and must always be set to 12 hours
    uint16_t si = 50;    // This parameter has no impact for NOx and must always be set to 50
    if (CmndSen6xError(sen6x->setNoxAlgorithmTuningParameters(value[0], value[1], ltgh, value[2], si, value[3]))) {
      return;
    }
  }
  CmndSen6xState();
}

void CmndSen6xFanClean(void) {
  // Sen6xClean   - This command triggers fan cleaning. The fan is set to the maximum speed
  //                for 10 seconds and then automatically stopped.
  Sen6xStopStartMeasurement();
  if (CmndSen6xError(sen6x->startFanCleaning())) {
    return;
  }
  SEN6XDATA->state = SEN6X_STATE_CLEAN_FAN_WAIT;
  ResponseCmndDone();
}

void CmndSen6xSHTHeater(void) {
  // Sen6xHeat    - This command activates the SHT sensor heater with 200mW for 1s.
  //                The heater is then automatically deactivated again.
  Sen6xStopStartMeasurement();
  if (CmndSen6xError(sen6x->activateShtHeater())) {
    return;
  }
  SEN6XDATA->state = SEN6X_STATE_SHT_HEATER_WAIT;
  ResponseCmndDone();
}

void CmndSen6xVocState(void) {
  uint8_t voc_state[12];
  if (1 == XdrvMailbox.payload) {
    // TBD - Restore voc_state after a restart/power cycle - needs filesystem
/*
    Sen6xStopStartMeasurement();
    if (CmndSen6xError(sen6x->setVocAlgorithmState(voc_state, sizeof(voc_state)))) {
      return;
    }
*/
  } else {
    if (CmndSen6xError(sen6x->getVocAlgorithmState(voc_state, sizeof(voc_state)))) {
      return;
    }
    AddLog(LOG_LEVEL_DEBUG, PSTR("S6X: State %12_H"), voc_state);
    // TBD - Save voc_state for use after a restart/power cycle - needs filesystem
  }
  ResponseCmndDone();
}

/*********************************************************************************************\
 * Presentation
\*********************************************************************************************/

void Sen6xShow(bool json) {
  float temperature = 0;
  float humidity = 0;
  float abs_humidity = 0;
  bool ahum_available = (!isnan(SEN6XDATA->ambientTemperature) && !isnan(SEN6XDATA->ambientHumidity) && (SEN6XDATA->ambientHumidity > 0));
  if (ahum_available) {
    temperature = ConvertTemp(SEN6XDATA->ambientTemperature);
    humidity = ConvertHumidity(SEN6XDATA->ambientHumidity);
    abs_humidity = CalcTempHumToAbsHum(SEN6XDATA->ambientTemperature, SEN6XDATA->ambientHumidity);
  }

  if (json) {
    ResponseAppend_P(PSTR(",\"%s\":{\"PM1\":%1_f,\"PM2.5\":%1_f,\"PM4\":%1_f,\"PM10\":%1_f,\"" D_JSON_CO2 "\":%d,"),
      SEN6XDATA->name,
      &SEN6XDATA->massConcentrationPm1p0, &SEN6XDATA->massConcentrationPm2p5, &SEN6XDATA->massConcentrationPm4p0, &SEN6XDATA->massConcentrationPm10p0,
      SEN6XDATA->co2);
    if (!isnan(SEN6XDATA->noxIndex)) {
      ResponseAppend_P(PSTR("\"NOx\":%0_f,"), &SEN6XDATA->noxIndex);
    }
    if (!isnan(SEN6XDATA->vocIndex)) {
      ResponseAppend_P(PSTR("\"VOC\":%0_f,"), &SEN6XDATA->vocIndex);
    }
    if (ahum_available) {
      ResponseAppendTHD(temperature, humidity);
      ResponseAppend_P(PSTR(",\"" D_JSON_AHUM "\":%4_f"), &abs_humidity);
    }
    ResponseJsonEnd();
#ifdef USE_WEBSERVER
  } else {
    WSContentSend_PD(HTTP_SNS_F_ENVIRONMENTAL_CONCENTRATION, SEN6XDATA->name, "1", &SEN6XDATA->massConcentrationPm1p0);
    WSContentSend_PD(HTTP_SNS_F_ENVIRONMENTAL_CONCENTRATION, SEN6XDATA->name, "2.5", &SEN6XDATA->massConcentrationPm2p5);
    WSContentSend_PD(HTTP_SNS_F_ENVIRONMENTAL_CONCENTRATION, SEN6XDATA->name, "4", &SEN6XDATA->massConcentrationPm4p0);
    WSContentSend_PD(HTTP_SNS_F_ENVIRONMENTAL_CONCENTRATION, SEN6XDATA->name, "10", &SEN6XDATA->massConcentrationPm10p0);
    WSContentSend_PD(HTTP_SNS_CO2, SEN6XDATA->name, SEN6XDATA->co2);
    if (!isnan(SEN6XDATA->noxIndex)) {
      WSContentSend_PD(HTTP_SNS_F_NOX, SEN6XDATA->name, 0, &SEN6XDATA->noxIndex);
    }
    if (!isnan(SEN6XDATA->vocIndex)) {
      WSContentSend_PD(HTTP_SNS_F_VOC, SEN6XDATA->name, 0, &SEN6XDATA->vocIndex);
    }
    if (ahum_available) {
      WSContentSend_THD(SEN6XDATA->name, temperature, humidity);
      WSContentSend_PD(HTTP_SNS_F_ABS_HUM, SEN6XDATA->name, 4, &abs_humidity);
    }
#endif
  }
}

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xsns119(uint32_t function) {
  if (!I2cEnabled(XI2C_97)) { return false; }

  bool result = false;

  if (FUNC_INIT == function) {
    Sen6xInit();
  }
  else if (SEN6XDATA) {
    switch (function) {
      case FUNC_EVERY_SECOND:
        Sen6xUpdate();
        break;
      case FUNC_JSON_APPEND:
        Sen6xShow(1);
        break;
#ifdef USE_WEBSERVER
      case FUNC_WEB_SENSOR:
        Sen6xShow(0);
        break;
#endif // USE_WEBSERVER
      case FUNC_COMMAND:
        result = DecodeCommand(kSen6xCommands, Sen6xCommand);
        break;
    }
  }
  return result;
}

#endif  // USE_SEN6X
#endif  // USE_I2C
