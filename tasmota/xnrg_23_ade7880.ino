/*
  xnrg_23_ade7880.ino - ADE7880 energy sensor support for Tasmota

  SPDX-FileCopyrightText: 2022 Theo Arends and AndreKR

  SPDX-License-Identifier: GPL-3.0-only
*/

#ifdef USE_I2C
#ifdef USE_ENERGY_SENSOR
#ifdef USE_ADE7880
/*********************************************************************************************\
 * ADE7880 - Energy used in Shelly 3EM
 *
 * {"NAME":"Shelly 3EM","GPIO":[1,1,544,1,32,8065,0,0,640,8064,608,224,8096,0],"FLAG":0,"BASE":18}
 *
 * Based on datasheet from https://www.analog.com/en/products/ade7880.html
 *
 * I2C Address: 0x38
\*********************************************************************************************/

#define XNRG_23                 23
#define XI2C_65                 65           // See I2CDEVICES.md

#define ADE7880_ADDR            0x38

//#define ADE7880_COMPMODE_FREQ   0x4000       // Connected to networks with fundamental frequencies between 55 Hz and 66 Hz. Default 45 Hz to 55 Hz

/*********************************************************************************************/

//#define ADE7880_DEBUG
//#define ADE7880_PROFILING

/*
Derive these parameters from the original Shelly 3EM 4M firmware dump. Look for JSON file called calib.data
{
  "state": 0,
  "rms": {
    "current_a": 3166385,
    "current_b": 3125691,
    "current_c": 3131983,
    "current_n": -1474892307,
    "current_s": 1756557,
    "voltage_a": -767262,
    "voltage_b": -763439,
    "voltage_c": -749854
  },
  "angles": {
    "angle0": 180,
    "angle1": 176,
    "angle2": 176
  },
  "powers": {
    "totactive": {
      "a": -1345820,
      "b": -1347328,
      "c": -1351979
    },
    "apparent": {
      "a": 214966,
      "b": 214961,
      "c": 214949
    }
  },
 "energies": {
    "totactive": {
      "a": 8752,
      "b": 8751,
      "c": 8751
    },
    "apparent": {
      "a": 40496,
      "b": 40513,
      "c": 40524
    }
  }
}
*/
#define ADE7880_AIGAIN_INIT     3166385      // rms, current_a
#define ADE7880_BIGAIN_INIT     3125691      // rms, current_b
#define ADE7880_CIGAIN_INIT     3131983      // rms, current_c
#define ADE7880_NIGAIN_INIT     1756557      // rms, current_s !!
#define ADE7880_AVGAIN_INIT     -767262      // rms, voltage_a
#define ADE7880_BVGAIN_INIT     -763439      // rms, voltage_b
#define ADE7880_CVGAIN_INIT     -749854      // rms, voltage_c
#define ADE7880_APHCAL_INIT     180          // angles, angle0
#define ADE7880_BPHCAL_INIT     176          // angles, angle1
#define ADE7880_CPHCAL_INIT     176          // angles, angle2
#define ADE7880_APGAIN_INIT     -1345820     // powers, totactive, a
#define ADE7880_BPGAIN_INIT     -1347328     // powers, totactive, b
#define ADE7880_CPGAIN_INIT     -1351979     // powers, totactive, c

/*
// Original defines from logic analyzer
#define ADE7880_AIGAIN_INIT     0x002FFED1   // = 3145425
#define ADE7880_BIGAIN_INIT     0x00309661   // = 3184225
#define ADE7880_CIGAIN_INIT     0x0030DBFD   // = 3202045
#define ADE7880_NIGAIN_INIT     0x04D906AC   // = 81331884 (14223020)
#define ADE7880_AVGAIN_INIT     0xFFF43977   // = -771720
#define ADE7880_BVGAIN_INIT     0xFFF4DD00   // = -729855
#define ADE7880_CVGAIN_INIT     0xFFF4A306   // = -744697
#define ADE7880_APHCAL_INIT     0xD895       // = 55445 (149)
#define ADE7880_BPHCAL_INIT     0xD8A9       // = 55456 (169)
#define ADE7880_CPHCAL_INIT     0xD89D       // = 55453 (157)
#define ADE7880_APGAIN_INIT     0xFF14B7E3   // = -15419420
#define ADE7880_BPGAIN_INIT     0xFF14A7B1   // = -15423566
#define ADE7880_CPGAIN_INIT     0xFF14999C   // = -15427171
*/
/*
#define ADE7880_AIGAIN_INIT     3145425
#define ADE7880_BIGAIN_INIT     3184225
#define ADE7880_CIGAIN_INIT     3202045
#define ADE7880_NIGAIN_INIT     14223020
#define ADE7880_AVGAIN_INIT     -771720
#define ADE7880_BVGAIN_INIT     -729855
#define ADE7880_CVGAIN_INIT     -744697
#define ADE7880_APHCAL_INIT     149
#define ADE7880_BPHCAL_INIT     169
#define ADE7880_CPHCAL_INIT     157
#define ADE7880_APGAIN_INIT     -15419420
#define ADE7880_BPGAIN_INIT     -15423566
#define ADE7880_CPGAIN_INIT     -15427171
*/

enum Ade7880DspRegisters {
  ADE7880_AIGAIN = 0x4380,         // 0x4380  R/W  24  32 ZPSE  S   0x000000    Phase A current gain adjust.
  ADE7880_AVGAIN,                  // 0x4381  R/W  24  32 ZPSE  S   0x000000    Phase A voltage gain adjust.
  ADE7880_BIGAIN,                  // 0x4382  R/W  24  32 ZPSE  S   0x000000    Phase B current gain adjust.
  ADE7880_BVGAIN,                  // 0x4383  R/W  24  32 ZPSE  S   0x000000    Phase B voltage gain adjust.
  ADE7880_CIGAIN,                  // 0x4384  R/W  24  32 ZPSE  S   0x000000    Phase C current gain adjust.
  ADE7880_CVGAIN,                  // 0x4385  R/W  24  32 ZPSE  S   0x000000    Phase C voltage gain adjust.
  ADE7880_NIGAIN,                  // 0x4386  R/W  24  32 ZPSE  S   0x000000    Neutral current gain adjust.
  ADE7880_DICOEFF = 0x4388,        // 0x4388  R/W  24  32 ZPSE  S   0x0000000   Register used in the digital integrator algorithm. If the integrator is turned on, it must be set at 0xFF8000. In practice, it is transmitted as 0xFFF8000.
  ADE7880_APGAIN,                  // 0x4389  R/W  24  32 ZPSE  S   0x000000    Phase A power gain adjust.
  ADE7880_AWATTOS,                 // 0x438A  R/W  24  32 ZPSE  S   0x000000    Phase A total active power offset adjust.
  ADE7880_BPGAIN,                  // 0x438B  R/W  24  32 ZPSE  S   0x000000    Phase B power gain adjust.
  ADE7880_BWATTOS,                 // 0x438C  R/W  24  32 ZPSE  S   0x000000    Phase B total active power offset adjust.
  ADE7880_CPGAIN,                  // 0x438D  R/W  24  32 ZPSE  S   0x000000    Phase C power gain adjust.
  ADE7880_CWATTOS,                 // 0x438E  R/W  24  32 ZPSE  S   0x000000    Phase C total active power offset adjust.
  ADE7880_AIRMSOS,                 // 0x438F  R/W  24  32 ZPSE  S   0x000000    Phase A current rms offset.
  ADE7880_AVRMSOS,                 // 0x4390  R/W  24  32 ZPSE  S   0x000000    Phase A voltage rms offset.
  ADE7880_BIRMSOS,                 // 0x4391  R/W  24  32 ZPSE  S   0x000000    Phase B current rms offset.
  ADE7880_BVRMSOS,                 // 0x4392  R/W  24  32 ZPSE  S   0x000000    Phase B voltage rms offset.
  ADE7880_CIRMSOS,                 // 0x4393  R/W  24  32 ZPSE  S   0x000000    Phase C current rms offset.
  ADE7880_CVRMSOS,                 // 0x4394  R/W  24  32 ZPSE  S   0x000000    Phase C voltage rms offset.
  ADE7880_NIRMSOS,                 // 0x4395  R/W  24  32 ZPSE  S   0x000000    Neutral current rms offset.
  ADE7880_HPGAIN = 0x4398,         // 0x4398  R/W  24  32 ZPSE  S   0x000000    Harmonic powers gain adjust.
  ADE7880_ISUMLVL,                 // 0x4399  R/W  24  32 ZPSE  S   0x000000    Threshold used in comparison between the sum of phase currents and the neutral current.
  ADE7880_VLEVEL = 0x439F,         // 0x439F  R/W  28  32 ZP    S   0x0000000   Register used in the algorithm that computes the fundamental active and reactive powers. Set this register according to Equation 22 for proper functioning of fundamental powers and harmonic computations.
  ADE7880_AFWATTOS = 0x43A2,       // 0x43A2  R/W  24  32 ZPSE  S   0x000000    Phase A fundamental active power offset adjust.
  ADE7880_BFWATTOS,                // 0x43A3  R/W  24  32 ZPSE  S   0x000000    Phase B fundamental active power offset adjust.
  ADE7880_CFWATTOS,                // 0x43A4  R/W  24  32 ZPSE  S   0x000000    Phase C fundamental active power offset adjust.
  ADE7880_AFVAROS,                 // 0x43A5  R/W  24  32 ZPSE  S   0x000000    Phase A fundamental reactive power offset adjust.
  ADE7880_BFVAROS,                 // 0x43A6  R/W  24  32 ZPSE  S   0x000000    Phase B fundamental reactive power offset adjust.
  ADE7880_CFVAROS,                 // 0x43A7  R/W  24  32 ZPSE  S   0x000000    Phase C fundamental reactive power offset adjust.
  ADE7880_AFIRMSOS,                // 0x43A8  R/W  24  32 ZPSE  S   0x000000    Phase A fundamental current rms offset.
  ADE7880_BFIRMSOS,                // 0x43A9  R/W  24  32 ZPSE  S   0x000000    Phase B fundamental current rms offset.
  ADE7880_CFIRMSOS,                // 0x43AA  R/W  24  32 ZPSE  S   0x000000    Phase C fundamental current rms offset.
  ADE7880_AFVRMSOS,                // 0x43AB  R/W  24  32 ZPSE  S   0x000000    Phase A fundamental voltage rms offset.
  ADE7880_BFVRMSOS,                // 0x43AC  R/W  24  32 ZPSE  S   0x000000    Phase B fundamental voltage rms offset.
  ADE7880_CFVRMSOS,                // 0x43AD  R/W  24  32 ZPSE  S   0x000000    Phase C fundamental voltage rms offset.
  ADE7880_HXWATTOS,                // 0x43AE  R/W  24  32 ZPSE  S   0x000000    Active power offset adjust on harmonic X (see Harmonics Calculations section for details).
  ADE7880_HYWATTOS,                // 0x43AF  R/W  24  32 ZPSE  S   0x000000    Active power offset adjust on harmonic Y (see Harmonics Calculations section for details).
  ADE7880_HZWATTOS,                // 0x43B0  R/W  24  32 ZPSE  S   0x000000    Active power offset adjust on harmonic Z (see Harmonics Calculations section for details).
  ADE7880_HXVAROS,                 // 0x43B1  R/W  24  32 ZPSE  S   0x000000    Active power offset adjust on harmonic X (see Harmonics Calculations section for details).
  ADE7880_HYVAROS,                 // 0x43B2  R/W  24  32 ZPSE  S   0x000000    Active power offset adjust on harmonic Y (see Harmonics Calculations section for details).
  ADE7880_HZVAROS,                 // 0x43B3  R/W  24  32 ZPSE  S   0x000000    Active power offset adjust on harmonic Z (see Harmonics Calculations section for details).
  ADE7880_HXIRMSOS,                // 0x43B4  R/W  24  32 ZPSE  S   0x000000    Current rms offset on harmonic X (see Harmonics Calculations section for details).
  ADE7880_HYIRMSOS,                // 0x43B5  R/W  24  32 ZPSE  S   0x000000    Current rms offset on harmonic Y (see Harmonics Calculations section for details).
  ADE7880_HZIRMSOS,                // 0x43B6  R/W  24  32 ZPSE  S   0x000000    Current rms offset on harmonic Z (see Harmonics Calculations section for details).
  ADE7880_HXVRMSOS,                // 0x43B7  R/W  24  32 ZPSE  S   0x000000    Voltage rms offset on harmonic X (see Harmonics Calculations section for details).
  ADE7880_HYVRMSOS,                // 0x43B8  R/W  24  32 ZPSE  S   0x000000    Voltage rms offset on harmonic Y (see Harmonics Calculations section for details).
  ADE7880_HZVRMSOS,                // 0x43B9  R/W  24  32 ZPSE  S   0x000000    Voltage rms offset on harmonic Z (see Harmonics Calculations section for details).
  ADE7880_AIRMS = 0x43C0,          // 0x43C0  R    24  32 ZP    S   N/A         Phase A current rms value.
  ADE7880_AVRMS,                   // 0x43C1  R    24  32 ZP    S   N/A         Phase A voltage rms value.
  ADE7880_BIRMS,                   // 0x43C2  R    24  32 ZP    S   N/A         Phase B current rms value.
  ADE7880_BVRMS,                   // 0x43C3  R    24  32 ZP    S   N/A         Phase B voltage rms value.
  ADE7880_CIRMS,                   // 0x43C4  R    24  32 ZP    S   N/A         Phase C current rms value.
  ADE7880_CVRMS,                   // 0x43C5  R    24  32 ZP    S   N/A         Phase C voltage rms value.
  ADE7880_NIRMS,                   // 0x43C6  R    24  32 ZP    S   N/A         Neutral current rms value.
  ADE7880_ISUM                     // 0x43C7  R    28  32 ZP    S   N/A         Sum of IAWV, IBWV and ICWV registers.
};

enum Ade7880InternalDspRegisters {
  ADE7880_Run = 0xE228             // 0xE228  R/W  16  16       U   0x0000      Run register starts and stops the DSP. See the Digital Signal Processor section for more details.
};

enum Ade7880BillableRegisters {
  ADE7880_AWATTHR = 0xE400,        // 0xE400  R    32  32       S   0x00000000  Phase A total active energy accumulation.
  ADE7880_BWATTHR,                 // 0xE401  R    32  32       S   0x00000000  Phase B total active energy accumulation.
  ADE7880_CWATTHR,                 // 0xE402  R    32  32       S   0x00000000  Phase C total active energy accumulation.
  ADE7880_AFWATTHR,                // 0xE403  R    32  32       S   0x00000000  Phase A fundamental active energy accumulation.
  ADE7880_BFWATTHR,                // 0xE404  R    32  32       S   0x00000000  Phase B fundamental active energy accumulation.
  ADE7880_CFWATTHR,                // 0xE405  R    32  32       S   0x00000000  Phase C fundamental active energy accumulation.
  ADE7880_AFVARHR = 0xE409,        // 0xE409  R    32  32       S   0x00000000  Phase A fundamental reactive energy accumulation.
  ADE7880_BFVARHR,                 // 0xE40A  R    32  32       S   0x00000000  Phase B fundamental reactive energy accumulation.
  ADE7880_CFVARHR,                 // 0xE40B  R    32  32       S   0x00000000  Phase C fundamental reactive energy accumulation.
  ADE7880_AVAHR,                   // 0xE40C  R    32  32       S   0x00000000  Phase A apparent energy accumulation.
  ADE7880_BVAHR,                   // 0xE40D  R    32  32       S   0x00000000  Phase B apparent energy accumulation.
  ADE7880_CVAHR                    // 0xE40E  R    32  32       S   0x00000000  Phase C apparent energy accumulation.
};

enum Ade7880PowerQualityRegisters {
  ADE7880_IPEAK = 0xE500,          // 0xE500  R    32  32       U   N/A         Current peak register. See Figure 60 and Table 34 for details about its composition.
  ADE7880_VPEAK,                   // 0xE501  R    32  32       U   N/A         Voltage peak register. See Figure 60 and Table 35 for details about its composition.
  ADE7880_STATUS0,                 // 0xE502  R/W  32  32       U   N/A         Interrupt Status Register 0. See Table 36.
  ADE7880_STATUS1,                 // 0xE503  R/W  32  32       U   N/A         Interrupt Status Register 1. See Table 37.
  ADE7880_AIMAV,                   // 0xE504  R    20  32 ZP    U   N/A         Phase A current mean absolute value computed during PSM0 and PSM1 modes.
  ADE7880_BIMAV,                   // 0xE505  R    20  32 ZP    U   N/A         Phase B current mean absolute value computed during PSM0 and PSM1 modes.
  ADE7880_CIMAV,                   // 0xE506  R    20  32 ZP    U   N/A         Phase C current mean absolute value computed during PSM0 and PSM1 modes.
  ADE7880_OILVL,                   // 0xE507  R/W  24  32 ZP    U   0xFFFFFF    Overcurrent threshold.
  ADE7880_OVLVL,                   // 0xE508  R/W  24  32 ZP    U   0xFFFFFF    Overvoltage threshold.
  ADE7880_SAGLVL,                  // 0xE509  R/W  24  32 ZP    U   0x000000    Voltage SAG level threshold.
  ADE7880_MASK0,                   // 0xE50A  R/W  32  32       U   0x00000000  Interrupt Enable Register 0. See Table 38.
  ADE7880_MASK1,                   // 0xE50B  R/W  32  32       U   0x00000000  Interrupt Enable Register 1. See Table 39.
  ADE7880_IAWV,                    // 0xE50C  R    24  32 SE    S   N/A         Instantaneous value of Phase A current.
  ADE7880_IBWV,                    // 0xE50D  R    24  32 SE    S   N/A         Instantaneous value of Phase B current.
  ADE7880_ICWV,                    // 0xE50E  R    24  32 SE    S   N/A         Instantaneous value of Phase C current.
  ADE7880_INWV,                    // 0xE50F  R    24  32 SE    S   N/A         Instantaneous value of neutral current.
  ADE7880_VAWV,                    // 0xE510  R    24  32 SE    S   N/A         Instantaneous value of Phase A voltage.
  ADE7880_VBWV,                    // 0xE511  R    24  32 SE    S   N/A         Instantaneous value of Phase B voltage.
  ADE7880_VCWV,                    // 0xE512  R    24  32 SE    S   N/A         Instantaneous value of Phase C voltage.
  ADE7880_AWATT,                   // 0xE513  R    24  32 SE    S   N/A         Instantaneous value of Phase A total active power.
  ADE7880_BWATT,                   // 0xE514  R    24  32 SE    S   N/A         Instantaneous value of Phase B total active power.
  ADE7880_CWATT,                   // 0xE515  R    24  32 SE    S   N/A         Instantaneous value of Phase C total active power.
  ADE7880_AVA = 0xE519,            // 0xE519  R    24  32 SE    S   N/A         Instantaneous value of Phase A apparent power.
  ADE7880_BVA,                     // 0xE51A  R    24  32 SE    S   N/A         Instantaneous value of Phase B apparent power.
  ADE7880_CVA,                     // 0xE51B  R    24  32 SE    S   N/A         Instantaneous value of Phase C apparent power.
  ADE7880_CHECKSUM = 0xE51F,       // 0xE51F  R    32  32       U   0xAFFA63B9  Checksum verification. See the Checksum Register section for details.
  ADE7880_VNOM,                    // 0xE520  R/W  24  32 ZP    S   0x000000    Nominal phase voltage rms used in the alternative computation of the apparent power. When the VNOMxEN bit is set, the
                                   //                                           applied voltage input in the corresponding phase is ignored and all corresponding rms voltage instances are replaced by the value in the VNOM register.
  ADE7880_LAST_RWDATA32 = 0xE5FF,  // 0xE5FF  R    32  32       U   N/A         Contains the data from the last successful 32-bit register communication.
  ADE7880_PHSTATUS,                // 0xE600  R    16  16       U   N/A         Phase peak register. See Table 40.
  ADE7880_ANGLE0,                  // 0xE601  R    16  16       U   N/A         Time Delay 0. See the Time Interval Between Phases section for details.
  ADE7880_ANGLE1,                  // 0xE602  R    16  16       U   N/A         Time Delay 1. See the Time Interval Between Phases section for details.
  ADE7880_ANGLE2,                  // 0xE603  R    16  16       U   N/A         Time Delay 2. See the Time Interval Between Phases section for details.
  ADE7880_PHNOLOAD = 0xE608,       // 0xE608  R    16  16       U   N/A         Phase no load register. See Table 41.
  ADE7880_LINECYC = 0xE60C,        // 0xE60C  R/W  16  16       U   0xFFFF      Line cycle accumulation mode count.
  ADE7880_ZXTOUT,                  // 0xE60D  R/W  16  16       U   0xFFFF      Zero-crossing timeout count.
  ADE7880_COMPMODE,                // 0xE60E  R/W  16  16       U   0x01FF      Computation-mode register. See Table 42.
  ADE7880_Gain,                    // 0xE60F  R/W  16  16       U   0x0000      PGA gains at ADC inputs. See Table 43.
  ADE7880_CFMODE,                  // 0xE610  R/W  16  16       U   0x0EA0      CFx configuration register. See Table 44.
  ADE7880_CF1DEN,                  // 0xE611  R/W  16  16       U   0x0000      CF1 denominator.
  ADE7880_CF2DEN,                  // 0xE612  R/W  16  16       U   0x0000      CF2 denominator.
  ADE7880_CF3DEN,                  // 0xE613  R/W  16  16       U   0x0000      CF3 denominator.
  ADE7880_APHCAL,                  // 0xE614  R/W  10  16 ZP    S   0x0000      Phase calibration of Phase A. See Table 45.
  ADE7880_BPHCAL,                  // 0xE615  R/W  10  16 ZP    S   0x0000      Phase calibration of Phase B. See Table 45.
  ADE7880_CPHCAL,                  // 0xE616  R/W  10  16 ZP    S   0x0000      Phase calibration Phase of C. See Table 45.
  ADE7880_PHSIGN,                  // 0xE617  R    16  16       U   N/A         Power sign register. See Table 46.
  ADE7880_CONFIG,                  // 0xE618  R/W  16  16       U   0x0002      ADE7880 configuration register. See Table 47.
  ADE7880_MMODE = 0xE700,          // 0xE700  R/W  8   8        U   0x1C        Measurement mode register. See Table 48.
  ADE7880_ACCMODE,                 // 0xE701  R/W  8   8        U   0x80        Accumulation mode register. See Table 49.
  ADE7880_LCYCMODE,                // 0xE702  R/W  8   8        U   0x78        Line accumulation mode behavior. See Table 51.
  ADE7880_PEAKCYC,                 // 0xE703  R/W  8   8        U   0x00        Peak detection half line cycles.
  ADE7880_SAGCYC,                  // 0xE704  R/W  8   8        U   0x00        SAG detection half line cycles.
  ADE7880_CFCYC,                   // 0xE705  R/W  8   8        U   0x01        Number of CF pulses between two consecutive energy latches. See the Synchronizing Energy Registers with CFx Outputs section.
  ADE7880_HSDC_CFG,                // 0xE706  R/W  8   8        U   0x00        HSDC configuration register. See Table 52.
  ADE7880_Version,                 // 0xE707  R    8   8        U               Version of die.
  ADE7880_DSPWP_SET = 0xE7E3,      // 0xE7E3  W    8   8        U   0x00        Write protect DSP (0x80) or enable write (0x00). See page 40.
  ADE7880_Reserved,                // 0xE7E4  R    8   8        U   0x08        This register must remain at this value for checksum functionality to work. If this register shows a different value while being read, reset the chip before working with the checksum feature.
  ADE7880_LAST_RWDATA8 = 0xE7FD,   // 0xE7FD  R    8   8        U   N/A         Contains the data from the last successful 8-bit register communication.
  ADE7880_DSPWP_SEL,               // 0xE7FE  W    8   8        U   0xAD        Select DSP writeprotect. See page 40.
  ADE7880_FVRMS = 0xE880,          // 0xE880  R    24  32       S   N/A         The rms value of the fundamental component of the phase voltage.
  ADE7880_FIRMS,                   // 0xE881  R    24  32       S   N/A         The rms value of the fundamental component of the phase current
  ADE7880_FWATT,                   // 0xE882  R    24  32       S   N/A         The active power of the fundamental component.
  ADE7880_FVAR,                    // 0xE883  R    24  32       S   N/A         The reactive power of the fundamental component.
  ADE7880_FVA,                     // 0xE884  R    24  32       S   N/A         The apparent power of the fundamental component.
  ADE7880_FPF,                     // 0xE885  R    24  32       S   N/A         The power factor of the fundamental component.
  ADE7880_VTHD,                    // 0xE886  R    24  32       S   N/A         Total harmonic distortion of the phase voltage.
  ADE7880_ITHD,                    // 0xE887  R    24  32       S   N/A         Total harmonic distortion of the phase current.
  ADE7880_HXVRMS,                  // 0xE888  R    24  32       S   N/A         The rms value of the phase voltage harmonic X.
  ADE7880_HXIRMS,                  // 0xE889  R    24  32       S   N/A         The rms value of the phase current harmonic X.
  ADE7880_HXWATT,                  // 0xE88A  R    24  32       S   N/A         The active power of the harmonic X.
  ADE7880_HXVAR,                   // 0xE88B  R    24  32       S   N/A         The reactive power of the harmonic X.
  ADE7880_HXVA,                    // 0xE88C  R    24  32       S   N/A         The apparent power of the harmonic X.
  ADE7880_HXPF,                    // 0xE88D  R    24  32       S   N/A         The power factor of the harmonic X.
  ADE7880_HXVHD,                   // 0xE88E  R    24  32       S   N/A         Harmonic distortion of the phase voltage harmonic X relative to the fundamental.
  ADE7880_HXIHD,                   // 0xE88F  R    24  32       S   N/A         Harmonic distortion of the phase current harmonic X relative to the fundamental.
  ADE7880_HYVRMS,                  // 0xE890  R    24  32       S   N/A         The rms value of the phase voltage harmonic Y.
  ADE7880_HYIRMS,                  // 0xE891  R    24  32       S   N/A         The rms value of the phase current harmonic Y.
  ADE7880_HYWATT,                  // 0xE892  R    24  32       S   N/A         The active power of the harmonic Y.
  ADE7880_HYVAR,                   // 0xE893  R    24  32       S   N/A         The reactive power of the harmonic Y.
  ADE7880_HYVA,                    // 0xE894  R    24  32       S   N/A         The apparent power of the harmonic Y.
  ADE7880_HYPF,                    // 0xE895  R    24  32       S   N/A         The power factor of the harmonic Y.
  ADE7880_HYVHD,                   // 0xE896  R    24  32       S   N/A         Harmonic distortion of the phase voltage harmonic Y relative to the fundamental.
  ADE7880_HYIHD,                   // 0xE897  R    24  32       S   N/A         Harmonic distortion of the phase current harmonic Y relative to the fundamental.
  ADE7880_HZVRMS,                  // 0xE898  R    24  32       S   N/A         The rms value of the phase voltage harmonic Z.
  ADE7880_HZIRMS,                  // 0xE899  R    24  32       S   N/A         The rms value of the phase current harmonic Z.
  ADE7880_HZWATT,                  // 0xE89A  R    24  32       S   N/A         The active power of the harmonic Z.
  ADE7880_HZVAR,                   // 0xE89B  R    24  32       S   N/A         The reactive power of the harmonic Z.
  ADE7880_HZVA,                    // 0xE89C  R    24  32       S   N/A         The apparent power of the harmonic Z.
  ADE7880_HZPF,                    // 0xE89D  R    24  32       S   N/A         The power factor of the harmonic Z.
  ADE7880_HZVHD,                   // 0xE89E  R    24  32       S   N/A         Harmonic distortion of the phase voltage harmonic Z relative to the fundamental.
  ADE7880_HZIHD,                   // 0xE89F  R    24  32       S   N/A         Harmonic distortion of the phase current harmonic Z relative to the fundamental.
  ADE7880_HCONFIG = 0xE900,        // 0xE900  R/W  16  16       U   0x08        Harmonic Calculations Configuration register. See Table 54.
  ADE7880_APF = 0xE902,            // 0xE902  R    16  16       S   N/A         Phase A power factor.
  ADE7880_BPF,                     // 0xE903  R    16  16       S   N/A         Phase B power factor.
  ADE7880_CPF,                     // 0xE904  R    16  16       S   N/A         Phase C power factor.
  ADE7880_APERIOD,                 // 0xE905  R    16  16       U   N/A         Line period on Phase A voltage.
  ADE7880_BPERIOD,                 // 0xE906  R    16  16       U   N/A         Line period on Phase B voltage.
  ADE7880_CPERIOD,                 // 0xE907  R    16  16       U   N/A         Line period on Phase C voltage.
  ADE7880_APNOLOAD,                // 0xE908  R/W  16  16       U   0x0000      No load threshold in the total/ fundamental active power data paths. Do not write 0xFFFF to this register.
  ADE7880_VARNOLOAD,               // 0xE909  R/W  16  16       U   0x0000      No load threshold in the total/ fundamental reactive power data path. Do not write 0xFFFF to this register.
  ADE7880_VANOLOAD,                // 0xE90A  R/W  16  16       U   0x0000      No load threshold in the apparent power data path. Do not write 0xFFFF to this register.
  ADE7880_LAST_ADD = 0xE9FE,       // 0xE9FE  R    16  16       U   N/A         The address of the register successfully accessed during the last read/write operation.
  ADE7880_LAST_RWDATA16,           // 0xE9FF  R    16  16       U   N/A         Contains the data from the last successful 16-bit register communication.
  ADE7880_CONFIG3,                 // 0xEA00  R/W  8   8        U   0x01        Configuration register. See Table 53.
  ADE7880_LAST_OP,                 // 0xEA01  R    8   8        U   N/A         Indicates the type, read or write, of the last successful read/write operation.
  ADE7880_WTHR,                    // 0xEA02  R/W  8   8        U   0x03        Threshold used in phase total/fundamental active power data path.
  ADE7880_VARTHR,                  // 0xEA03  R/W  8   8        U   0x03        Threshold used in phase total/fundamental reactive power data path.
  ADE7880_VATHR,                   // 0xEA04  R/W  8   8        U   0x03        Threshold used in phase apparent power data path.
  ADE7880_HX = 0xEA08,             // 0xEA08  R/W  8   8        U   3           Selects an index of the harmonic monitored by the harmonic computations.
  ADE7880_HY,                      // 0xEA09  R/W  8   8        U   5           Selects an index of the harmonic monitored by the harmonic computations.
  ADE7880_HZ,                      // 0xEA0A  R/W  8   8        U   7           Selects an index of the harmonic monitored by the harmonic computations.
  ADE7880_LPOILVL = 0xEC00,        // 0xEC00  R/W  8   8        U   0x07        Overcurrent threshold used during PSM2 mode. See Table 55 in which the register is detailed.
  ADE7880_CONFIG2                  // 0xEC01  R/W  8   8        U   0x00        Configuration register used during PSM1 mode. See Table 56.
};

struct Ade7880 {
  int32_t nirms;
  int32_t isum;
  int32_t active_energy[3];
  int32_t apparent_energy[3];
  uint16_t angle[3];

  uint8_t init_state;
  uint8_t cycle_count;
  uint8_t irq0_state;
  uint8_t irq1_state;
} Ade7880;

/*********************************************************************************************/

int Ade7880RegSize(uint16_t reg) {
  int size = 0;
  switch ((reg >> 8) & 0x0F) {
    case 0x03:  // 32-bit
    case 0x04:
    case 0x05:
    case 0x08:
      size++;
      size++;
    case 0x01:  // 16-bit
    case 0x02:
    case 0x06:
    case 0x09:
      size++;
    case 0x00:  // 8-bit
    case 0x07:
    case 0x0A:
    case 0x0B:
    case 0x0C:
      size++;
  }
  return size;
}

void Ade7880Write(uint16_t reg, uint32_t val) {
  int size = Ade7880RegSize(reg);
  if (size) {
#ifdef ADE7880_DEBUG
    char log_format[100];
    snprintf_P(log_format, sizeof(log_format), PSTR("A78: Rd 0x%%04X 0x%%0%dX (%%d)"), size << 1);
    AddLog(LOG_LEVEL_DEBUG_MORE, log_format, reg, val, val);
#endif  // ADE7880_DEBUG
    Wire.beginTransmission(ADE7880_ADDR);
    Wire.write((reg >> 8) & 0xFF);
    Wire.write(reg & 0xFF);
    while (size--) {
      Wire.write((val >> (8 * size)) & 0xFF);                              // Write data, MSB first
    }
    Wire.endTransmission();
    delayMicroseconds(5);                                                  // Bus-free time minimum 4.7us
  }
}

bool Ade7880VerifyWrite(uint16_t reg) {
  if (0xCA != Ade7880Read(ADE7880_LAST_OP)) {                              // Indicates the type, read (0x35) or write (0xCA), of the last successful read/write operation.
    return false;
  }
  if (reg != Ade7880Read(ADE7880_LAST_ADD)) {                              // The address of the register successfully accessed during the last read/write operation.
    return false;
  }
  return true;
}

bool Ade7880WriteVerify(uint16_t reg, uint32_t val) {
  Ade7880Write(reg, val);
  return Ade7880VerifyWrite(reg);
}

int32_t Ade7880Read(uint16_t reg) {
	uint32_t response = 0;
  int size = Ade7880RegSize(reg);
  if (size) {
    Wire.beginTransmission(ADE7880_ADDR);
    Wire.write((reg >> 8) & 0xFF);
    Wire.write(reg & 0xFF);
    Wire.endTransmission(0);
    Wire.requestFrom(ADE7880_ADDR, size);
    if (size <= Wire.available()) {
      for (uint32_t i = 0; i < size; i++) {
        response = response << 8 | Wire.read();                            // receive DATA (MSB first)
      }
    }
#ifdef ADE7880_DEBUG
    char log_format[100];
    snprintf_P(log_format, sizeof(log_format), PSTR("A78: Rd 0x%%04X 0x%%0%dX (%%d)"), size << 1);
    AddLog(LOG_LEVEL_DEBUG_MORE, log_format, reg, response, response);
#endif  // ADE7880_DEBUG
  }
	return response;
}

int32_t Ade7880ReadVerify(uint16_t reg) {
  int32_t result = Ade7880Read(reg);
  if (0x35 != Ade7880Read(ADE7880_LAST_OP)) {                              // Indicates the type, read (0x35) or write (0xCA), of the last successful read/write operation.

  }
  if (reg != Ade7880Read(ADE7880_LAST_ADD)) {                              // The address of the register successfully accessed during the last read/write operation.

  }
  return result;
}

/*********************************************************************************************/

bool Ade7880Init(void) {
  // Init sequence about 100mS after reset - See page 40 (takes 68ms)
#ifdef ADE7880_PROFILING
  uint32_t start = millis();
#endif  // ADE7880_PROFILING
  uint32_t status1 = Ade7880ReadVerify(ADE7880_STATUS1);                   // 0x01A08000
  if (bitRead(status1, 15)) {                                              // RSTDONE
    // Power on or Reset
    Ade7880WriteVerify(ADE7880_CONFIG2, 0x02);                             // ADE7880_I2C_LOCK
    Ade7880WriteVerify(ADE7880_STATUS1, 0x3FFE8930);                       // Acknowledge RSTDONE - Reset IRQ1 line
    status1 = Ade7880ReadVerify(ADE7880_STATUS1);                          // 0x01A00007
  } else {
    return false;
  }
  uint8_t version = Ade7880ReadVerify(ADE7880_Version);                    // 0x01

  delayMicroseconds(240);                                                  // Grab parameters from flash/filesystem

  Ade7880WriteVerify(ADE7880_Gain, 0x0000);                                // Gain register set to 1 for current, and voltage
  Ade7880WriteVerify(ADE7880_APGAIN, ADE7880_APGAIN_INIT);
  Ade7880WriteVerify(ADE7880_BPGAIN, ADE7880_BPGAIN_INIT);
  Ade7880WriteVerify(ADE7880_CPGAIN, ADE7880_CPGAIN_INIT);
  Ade7880WriteVerify(ADE7880_AVGAIN, ADE7880_AVGAIN_INIT);
  Ade7880WriteVerify(ADE7880_BVGAIN, ADE7880_BVGAIN_INIT);
  Ade7880WriteVerify(ADE7880_CVGAIN, ADE7880_CVGAIN_INIT);
  Ade7880WriteVerify(ADE7880_AIGAIN, ADE7880_AIGAIN_INIT);
  Ade7880WriteVerify(ADE7880_BIGAIN, ADE7880_BIGAIN_INIT);
  Ade7880WriteVerify(ADE7880_CIGAIN, ADE7880_CIGAIN_INIT);
  Ade7880WriteVerify(ADE7880_NIGAIN, ADE7880_NIGAIN_INIT);
  Ade7880WriteVerify(ADE7880_APHCAL, ADE7880_APHCAL_INIT);
  Ade7880WriteVerify(ADE7880_BPHCAL, ADE7880_BPHCAL_INIT);
  Ade7880WriteVerify(ADE7880_CPHCAL, ADE7880_CPHCAL_INIT);
#ifdef ADE7880_COMPMODE_FREQ
  Ade7880WriteVerify(ADE7880_COMPMODE, 0x01FF | ADE7880_COMPMODE_FREQ);    // Connected to networks with fundamental frequencies between 55 Hz and 66 Hz. Default is 45 Hz and 55 Hz.
#endif
  bool error = false;
  if (Ade7880ReadVerify(ADE7880_AVGAIN) != (ADE7880_AVGAIN_INIT & 0x0FFFFFFF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_BVGAIN) != (ADE7880_BVGAIN_INIT & 0x0FFFFFFF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_CVGAIN) != (ADE7880_CVGAIN_INIT & 0x0FFFFFFF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_AIGAIN) != ADE7880_AIGAIN_INIT) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_BIGAIN) != ADE7880_BIGAIN_INIT) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_CIGAIN) != ADE7880_CIGAIN_INIT) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_NIGAIN) != ADE7880_NIGAIN_INIT) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_APGAIN) != (ADE7880_APGAIN_INIT & 0x0FFFFFFF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_BPGAIN) != (ADE7880_BPGAIN_INIT & 0x0FFFFFFF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_CPGAIN) != (ADE7880_CPGAIN_INIT & 0x0FFFFFFF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_APHCAL) != (ADE7880_APHCAL_INIT & 0x00FF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_BPHCAL) != (ADE7880_BPHCAL_INIT & 0x00FF)) { error = true; }
  else if (Ade7880ReadVerify(ADE7880_CPHCAL) != (ADE7880_CPHCAL_INIT & 0x00FF)) { error = true; }
#ifdef ADE7880_COMPMODE_FREQ
  else if (Ade7880ReadVerify(ADE7880_COMPMODE) != (0x01FF | ADE7880_COMPMODE_FREQ)) { error = true; }
#endif
  if (error) {
    AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Error initializing parameters"));
    return false;
  }
  if (!Ade7880WriteVerify(ADE7880_LCYCMODE, 0x09)) {                       // Line cycle accumulation mode
                                                                           // - Watt-hour accumulation registers (AWATTHR, BWATTHR, CWATTHR, AFWATTHR, BFWATTHR, and CFWATTHR) are placed into line cycle accumulation mode.
                                                                           // - Phase A is selected for zero-crossings counts in the line cycle accumulation mode.
    AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Error setting LCYCMODE register"));
    return false;
  }

  if (!Ade7880WriteVerify(ADE7880_LINECYC, 0x0064)) {                      // = 100
    AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Error setting LINECYC register"));
    return false;
  }

  Ade7880WriteVerify(ADE7880_MASK0, 0x00000020);                           // IRQ0 at end of an integration over an integer number of half line cycles set in the LINECYC register.
  if (!Ade7880VerifyWrite(ADE7880_MASK0)) {
    AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Error setting MASK0 register"));
    return false;
  }
  Ade7880Write(ADE7880_MASK0, 0x00000020);
  Ade7880Write(ADE7880_MASK0, 0x00000020);
  Ade7880Write(ADE7880_MASK0, 0x00000020);

  Ade7880Write(ADE7880_DSPWP_SEL, 0xAD);                                   // Select DSP write protection
  Ade7880Write(ADE7880_DSPWP_SET, 0x80);                                   // Write protect DSP area

  Ade7880WriteVerify(ADE7880_Run, 0x0201);                                 // Start DSP
#ifdef ADE7880_PROFILING
  AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Init done in %d ms"), millis() - start);
#endif  // ADE7880_PROFILING
  return true;
}

bool Ade7880Service1(void) {
  // Init sequence
  SkipSleep(false);
  bool result = Ade7880Init();
  Ade7880.irq1_state = 0;
  return result;
}

void IRAM_ATTR Ade7880Isr1(void) {
  // Init sequence
  if (!Ade7880.irq1_state) {
    Ade7880.irq1_state = 1;
    SkipSleep(true);
  }
}

/*********************************************************************************************/

void Ade7880Cycle(void) {
  // Cycle sequence (takes 55ms)
#ifdef ADE7880_PROFILING
  uint32_t start = millis();
#endif  // ADE7880_PROFILING
  uint32_t status0 = Ade7880ReadVerify(ADE7880_STATUS0);                   // 0x000FEFE0
  if (!bitRead(status0, 5)) {                                              // LENERGY
    return;
  } else {
    Ade7880WriteVerify(ADE7880_STATUS0, 0x00000020);                       // Acknowledge LENERGY - Reset IRQ0 line
    status0 = Ade7880ReadVerify(ADE7880_STATUS0);                          // 0x000FEFC0
  }
  if (Ade7880.cycle_count < 2) {                                           // Allow calibration stabilization
    Ade7880.cycle_count++;
    return;                                                                // Skip first two cycles
  }
                                                                           // Incandescent light bulb, 242V, 0.11A, Pf100%, 27.9W
  Energy.voltage[0] = (float)Ade7880ReadVerify(ADE7880_AVRMS) / 10000;     // 0x0024CC94 = 241.1668 V
  Energy.current[0] = (float)Ade7880ReadVerify(ADE7880_AIRMS) / 1000000;   // 0x00002D6D = 0.011629 A
  Energy.voltage[1] = (float)Ade7880ReadVerify(ADE7880_BVRMS) / 10000;     // 0x000003E8
  Energy.current[1] = (float)Ade7880ReadVerify(ADE7880_BIRMS) / 1000000;   // 0x0000053C = 0.001340 A
  Energy.voltage[2] = (float)Ade7880ReadVerify(ADE7880_CVRMS) / 10000;     // 0x0000037D
  Energy.current[2] = (float)Ade7880ReadVerify(ADE7880_CIRMS) / 1000000;   // 0x00000547 = 0.001351 A
  Ade7880.nirms = Ade7880ReadVerify(ADE7880_NIRMS);                        // 0x000026DF = 0.009951 A ??
  Ade7880.isum = Ade7880ReadVerify(ADE7880_ISUM);                          // 0x00000FBE = 0.004030 A ??
  Energy.active_power[0] = (float)Ade7880ReadVerify(ADE7880_AWATT) / 100;  // 0xFFFFF524 = -27.79 W (reverse connected)
  Energy.active_power[1] = (float)Ade7880ReadVerify(ADE7880_BWATT) / 100;  // 0x00000000
  Energy.active_power[2] = (float)Ade7880ReadVerify(ADE7880_CWATT) / 100;  // 0x00000000
  Energy.apparent_power[0] = (float)Ade7880ReadVerify(ADE7880_AVA) / 100;  // 0xFFFFF50D
  Energy.apparent_power[1] = (float)Ade7880ReadVerify(ADE7880_BVA) / 100;  // 0xFFFFFFFF
  Energy.apparent_power[2] = (float)Ade7880ReadVerify(ADE7880_CVA) / 100;  // 0xFFFFFFFF
  // Billable
  Ade7880.active_energy[0] = Ade7880ReadVerify(ADE7880_AWATTHR);           // 0xFFFFFF8F = -1.12 Whr ??
  Ade7880.active_energy[1] = Ade7880ReadVerify(ADE7880_BWATTHR);           // 0x00000000
  Ade7880.active_energy[2] = Ade7880ReadVerify(ADE7880_CWATTHR);           // 0x00000000
  Ade7880.apparent_energy[0] = Ade7880ReadVerify(ADE7880_AVAHR);           // 0xFFFFFB9C = -11.23 VAr ??
  Ade7880.apparent_energy[1] = Ade7880ReadVerify(ADE7880_BVAHR);           // 0xFFFFFFC7
  Ade7880.apparent_energy[2] = Ade7880ReadVerify(ADE7880_CVAHR);           // 0xFFFFFFC6

  uint16_t comp_mode = Ade7880ReadVerify(ADE7880_COMPMODE);                // 0x01FF (or 0x41FF) = Angles between phase voltages and phase currents are measured
  uint32_t fline = (bitRead(comp_mode, 14)) ? 60 : 50;                      // Line frequency in Hz
  Ade7880.angle[0] = Ade7880ReadVerify(ADE7880_ANGLE0);                    // 0x13FD = cos(5117 * 360 * fline / 256000) = cos_phi
  Ade7880.angle[1] = Ade7880ReadVerify(ADE7880_ANGLE1);                    // 0x0706
  Ade7880.angle[2] = Ade7880ReadVerify(ADE7880_ANGLE2);                    // 0x0859

  Energy.frequency[0] = 256000.0f / Ade7880ReadVerify(ADE7880_APERIOD);    // Page 34 and based on ADE7880_COMPMODE_FREQ
  Energy.frequency[1] = 256000.0f / Ade7880ReadVerify(ADE7880_BPERIOD);
  Energy.frequency[2] = 256000.0f / Ade7880ReadVerify(ADE7880_CPERIOD);
#ifdef ADE7880_PROFILING
  AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Cycle in %d ms"), millis() - start);
#endif  // ADE7880_PROFILING
}

void Ade7880Service0(void) {
  // Poll sequence
  SkipSleep(false);
  Ade7880Cycle();
  Ade7880.irq0_state = 0;
}

void IRAM_ATTR Ade7880Isr0(void) {
  // Poll sequence
  if (!Ade7880.irq0_state) {
    Ade7880.irq0_state = 1;
    SkipSleep(true);
  }
}

/*********************************************************************************************/

void Ade7880EnergyEverySecond(void) {
  for (uint32_t i = 0; i < 3; i++) {
    if (Ade7880.active_energy[i] != 0) {
      Energy.kWhtoday_delta[i] += Energy.active_power[i] * 1000 / 36;
    }
  }
}

void Ade7880DrvInit(void) {
  if (PinUsed(GPIO_ADE7880_IRQ) && PinUsed(GPIO_ADE7880_IRQ, 1)) {

#ifdef ADE7880_PROFILING
    uint32_t start = millis();
#endif  // ADE7880_PROFILING

    int reset = Pin(GPIO_RESET);
    if (-1 == reset) { reset = 16; }                                       // Reset pin ADE7880 in Shelly 3EM
    pinMode(reset, OUTPUT);
    digitalWrite(reset, 0);
    delay(1);
    digitalWrite(reset, 1);
    pinMode(reset, INPUT);

    pinMode(Pin(GPIO_ADE7880_IRQ), INPUT);
    attachInterrupt(Pin(GPIO_ADE7880_IRQ), Ade7880Isr0, FALLING);
    Ade7880.irq0_state = 0;
    pinMode(Pin(GPIO_ADE7880_IRQ, 1), INPUT);
    attachInterrupt(Pin(GPIO_ADE7880_IRQ, 1), Ade7880Isr1, FALLING);
    Ade7880.irq1_state = 0;

    uint32_t timeout = millis() + 400;
    while (!TimeReached(timeout)) {                                        // Wait up to 400 mSec
      if (1 == Ade7880.irq1_state) {

#ifdef ADE7880_PROFILING
        AddLog(LOG_LEVEL_DEBUG, PSTR("A78: Reset in %d ms"), millis() - start);
#endif  // ADE7880_PROFILING

        if (Ade7880Service1()) {
          if (I2cSetDevice(ADE7880_ADDR)) {
            I2cSetActiveFound(ADE7880_ADDR, "ADE7880");
            Energy.phase_count = 3;                                        // Three phases
//            Settings->flag5.energy_phase = 1;                            // SetOption129 - (Energy) Show phase information
//            Energy.use_overtemp = true;                                     // Use global temperature for overtemp detection
            TasmotaGlobal.energy_driver = XNRG_23;
          }
        }
        break;
      }
    }
  }
}

bool Ade7880Command(void) {
  // Investigate for need calibration of all three phases
  bool serviced = true;


  return serviced;
}

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xnrg23(uint8_t function) {
  if (!I2cEnabled(XI2C_65)) { return false; }

  bool result = false;

  switch (function) {
    case FUNC_LOOP:
      if (1 == Ade7880.irq0_state) { Ade7880Service0(); }
//      if (1 == Ade7880.irq1_state) { Ade7880Service1(); }
      break;
    case FUNC_ENERGY_EVERY_SECOND:
      Ade7880EnergyEverySecond();
      break;
    case FUNC_COMMAND:
      result = Ade7880Command();
      break;
    case FUNC_PRE_INIT:
      Ade7880DrvInit();
      break;
  }
  return result;
}

#endif  // USE_ADE7880
#endif  // USE_ENERGY_SENSOR
#endif  // USE_I2C
