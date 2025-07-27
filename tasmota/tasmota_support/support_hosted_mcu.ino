/*
  support_hosted_mcu.ino - eeprom support for Tasmota

  Copyright (C) 2025  Theo Arends & Christian Baars

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifdef CONFIG_ESP_WIFI_REMOTE_ENABLED

#include "esp_hosted.h"
#include "esp_hosted_api_types.h"
#include "esp_hosted_ota.h"

String GetHostedMCU(void) {
  // Function is not yet implemented in Arduino Core so emulate it here
  if (0 == strcasecmp_P(CONFIG_ESP_HOSTED_IDF_SLAVE_TARGET, PSTR("esp32c6"))) {
    return String("ESP32-C6");
  }
  return String("Unknown");
}

int GetFwVersionNumber(void) {
  // Function is not yet implemented in Arduino Core so emulate it here
  return 0x0200000E;   // v2.0.14
}

int GetHostedMCUFwVersionNumber(void) {
  static int version = -1;

  if (!esp_hosted_is_config_valid()) {
    return 0;
  }
  if (-1 == version) {
    version = 6;   // v0.0.6
    esp_hosted_coprocessor_fwver_t ver_info;
    esp_err_t err = esp_hosted_get_coprocessor_fwversion(&ver_info);  // This takes almost 4 seconds on <v0.0.6
    if (err == ESP_OK) {
      version = ver_info.major1 << 24 | ver_info.minor1 << 16 | ver_info.patch1;
    } else {
      // We can not know exactly, as API was added after 0.0.6
      AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("HST: Error %d, hosted version 0.0.6 or older"), err);
    }  
  }
  return version;
}

String GetHostedMCUFwVersion(void) {
  int version = GetHostedMCUFwVersionNumber();

  if (0 == version) {
    return String("");
  }
  uint8_t major1 = version >> 24;
  uint8_t minor1 = version >> 16;
  uint16_t patch1 = version;
  char data[40];
  snprintf_P(data, sizeof(data), PSTR("%d.%d.%d"), major1, minor1, patch1);
  return String(data);
}

int OTAHostedMCU(const char* image_url) {
  AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("HST: About to OTA update with %s"), image_url);
  int result = esp_hosted_slave_ota(image_url);
  AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("HST: Done with result %d"), result);
  return result;
}

void HostedMCUStatus(void) {
  // Execute after HostedMCU is init by WiFi.mode()
  static bool once_shown = false;

  if (once_shown) { return; }
  if (esp_hosted_is_config_valid()) {
    once_shown = true;
    char config[128] = { 0 };
    struct esp_hosted_transport_config *pconfig;
    if (ESP_TRANSPORT_OK == esp_hosted_transport_get_config(&pconfig)) {
      if (pconfig->transport_in_use == H_TRANSPORT_SDIO) {
        struct esp_hosted_sdio_config *psdio_config;
        if (ESP_TRANSPORT_OK == esp_hosted_sdio_get_config(&psdio_config)) {
          snprintf_P(config, sizeof(config), PSTR(" using GPIO%02d(CLK), GPIO%02d(CMD), GPIO%02d(D0), GPIO%02d(D1), GPIO%02d(D2), GPIO%02d(D3) and GPIO%02d(RST)"), 
            psdio_config->pin_clk.pin, psdio_config->pin_cmd.pin, psdio_config->pin_d0.pin, psdio_config->pin_d1.pin, psdio_config->pin_d2.pin, psdio_config->pin_d3.pin, psdio_config->pin_reset.pin);
        }
      }
    }
    AddLog(LOG_LEVEL_INFO, PSTR("HST: Hosted MCU %s v%s%s"),
      GetHostedMCU().c_str(), GetHostedMCUFwVersion().c_str(), config);
  }
}

#endif  // CONFIG_ESP_WIFI_REMOTE_ENABLED