/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <esp_rmaker_core.h>
#include <esp_rmaker_standard_types.h>
#include <esp_rmaker_standard_params.h>

#define DEFAULT_TEMPERATURE 25.0
#define REPORTING_PERIOD    60 /* Seconds */

#define DEFAULT_POWER       true

extern esp_rmaker_device_t *temp_sensor_device;
extern esp_rmaker_device_t *light_device;

void app_driver_init(void);
esp_err_t app_light_set_power(bool power);
float app_get_current_temperature();
void light_update_rainmaker(bool power);

