/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.33.0
 * Product:       svm4x
 * Model-Version: 2.0.3
 */
/*
 * Copyright (c) 2023, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SVM4X_UART_H
#define SVM4X_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"
#define SVM4X_SHDLC_ADDR 0x00

typedef enum {
    GET_PRODUCT_TYPE_CMD_ID = 0xd0,
    GET_PRODUCT_NAME_CMD_ID = 0xd0,
    GET_SERIAL_NUMBER_CMD_ID = 0xd0,
    GET_VERSION_CMD_ID = 0xd1,
    DEVICE_RESET_CMD_ID = 0xd3,
    GET_SYSTEM_UP_TIME_CMD_ID = 0x93,
    START_MEASUREMENT_CMD_ID = 0x0,
    STOP_MEASUREMENT_CMD_ID = 0x1,
    READ_MEASURED_VALUES_AS_INTEGERS_CMD_ID = 0x3,
    READ_MEASURED_RAW_VALUES_CMD_ID = 0x3,
    GET_TEMPERATURE_OFFSET_FOR_RHT_MEASUREMENTS_CMD_ID = 0x60,
    GET_VOC_TUNING_PARAMETERS_CMD_ID = 0x60,
    GET_NOX_TUNING_PARAMETERS_CMD_ID = 0x60,
    STORE_NV_DATA_CMD_ID = 0x60,
    SET_TEMPERATURE_OFFSET_FOR_RHT_MEASUREMENTS_CMD_ID = 0x60,
    SET_VOC_TUNING_PARAMETERS_CMD_ID = 0x60,
    SET_NOX_TUNING_PARAMETERS_CMD_ID = 0x60,
    GET_VOC_STATE_CMD_ID = 0x61,
    GET_NOX_STATE_CMD_ID = 0x61,
    SET_VOC_STATE_CMD_ID = 0x61,
    SET_NOX_STATE_CMD_ID = 0x61,
} cmd_id_t;

/**
 * @brief signal_temperature
 *
 * @param[in] temperature_raw
 *
 * @return Compensated ambient temperature in degrees celsius.
 */
float signal_temperature(int16_t temperature_raw);

/**
 * @brief signal_humidity
 *
 * @param[in] humidity_raw
 *
 * @return Compensated ambient humidity in %RH.
 */
float signal_humidity(int16_t humidity_raw);

/**
 * @brief signal_voc_index
 *
 * @param[in] voc_index_raw
 *
 * @return VOC Index
 */
float signal_voc_index(int16_t voc_index_raw);

/**
 * @brief signal_nox_index
 *
 * @param[in] nox_index_raw
 *
 * @return NOx Index
 */
float signal_nox_index(int16_t nox_index_raw);

/**
 * @brief Read measurement data and apply scaling.
 *
 * @param[out] a_humidity Compensated ambient humidity in %RH.
 * @param[out] a_temperature Compensated ambient temperature in degrees celsius.
 * @param[out] a_voc_index VOC Index
 * @param[out] a_nox_index NOx Index
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_read_measured_values(float* a_humidity, float* a_temperature,
                                   float* a_voc_index, float* a_nox_index);

/**
 * @brief svm4x_get_temperature_offset_for_rht_measurements
 *
 * Gets the T-Offset for the temperature compensation of the RHT algorithm.
 *
 * @param[out] arg_0
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_temperature_offset_for_rht_measurements(float* arg_0);

/**
 * @brief svm4x_set_temperature_offset_for_rht_measurements
 *
 * This command sets the temperature offset used for the compensation of
 * subsequent RHT measurement
 *
 * @param[in] t_offset Temperature offset as float in degrees celsius.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_set_temperature_offset_for_rht_measurements(float t_offset);

/**
 * @brief svm4x_get_product_type
 *
 * Gets the product type from the device.
 *
 * @param[out] product_type Character array containing the product type.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_product_type(int8_t* product_type,
                               uint16_t product_type_size);

/**
 * @brief svm4x_get_product_name
 *
 * Gets the product name from the device.
 *
 * @param[out] product_name Character array containing the product name.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_product_name(int8_t* product_name,
                               uint16_t product_name_size);

/**
 * @brief svm4x_get_serial_number
 *
 * Gets the serial number from the device.
 *
 * @param[out] serial_number Character array containing the serial number.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_serial_number(int8_t* serial_number,
                                uint16_t serial_number_size);

/**
 * @brief svm4x_get_version
 *
 * Gets the version information for the hardware, firmware and SHDLC protocol.
 *
 * @param[out] firmware_major Firmware major version number.
 * @param[out] firmware_minor Firmware minor version number.
 * @param[out] firmware_debug Firmware debug state. If the debug state is set,
 * the firmware is in development.
 * @param[out] hardware_major Hardware major version number.
 * @param[out] hardware_minor Hardware minor version number.
 * @param[out] protocol_major Protocol major version number.
 * @param[out] protocol_minor Protocol minor version number.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_version(uint8_t* firmware_major, uint8_t* firmware_minor,
                          bool* firmware_debug, uint8_t* hardware_major,
                          uint8_t* hardware_minor, uint8_t* protocol_major,
                          uint8_t* protocol_minor);

/**
 * @brief svm4x_device_reset
 *
 * Executs a reset on the device.
 *
 * @note The device will reply before executing the reset. If the command is
 * send with broadcast, the reset is done directly after the reception of the
 * command.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_device_reset();

/**
 * @brief svm4x_get_system_up_time
 *
 * Get the system up time of the device.
 *
 * @param[out] system_up_time The time since the last power-on or device reset
 * in seconds.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_system_up_time(uint32_t* system_up_time);

/**
 * @brief svm4x_start_measurement
 *
 * Starts measurement in polling mode.
 *
 * @note This command is only available in idle mode.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_start_measurement();

/**
 * @brief svm4x_stop_measurement
 *
 * Leaves the measurement mode and returns to the idle mode.
 *
 * @note This command is only available in measurement mode.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_stop_measurement();

/**
 * @brief svm4x_read_measured_values_as_integers
 *
 * Read measurement data as integers. This command is named get_signals in the
 * datasheet.
 *
 * @param[out] humidity Compensated ambient humidity in % RH with a scaling
 * factor of 100.
 * @param[out] temperature Compensated ambient temperature in degrees celsius
 * with a scaling of 200.
 * @param[out] voc_index VOC index with a scaling value of 10.
 * @param[out] nox_index NOx index with a scaling value of 10.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_read_measured_values_as_integers(int16_t* humidity,
                                               int16_t* temperature,
                                               int16_t* voc_index,
                                               int16_t* nox_index);

/**
 * @brief svm4x_read_measured_raw_values
 *
 * Read measuremed raw values. This command is named get_signals_raw in the
 * datasheet.
 *
 * @param[out] raw_humidity Uncompensated raw humidity in % RH as read from the
 * SHT40 with a scaling factor of 100.
 * @param[out] raw_temperature Uncompensated raw temperature in degrees celsius
 * as read from the SHT40 with a scaling of 200.
 * @param[out] raw_voc_ticks Raw VOC output ticks as read from the SGP sensor.
 * @param[out] raw_nox_ticks Raw NOx output ticks as read from the SGP sensor.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_read_measured_raw_values(int16_t* raw_humidity,
                                       int16_t* raw_temperature,
                                       uint16_t* raw_voc_ticks,
                                       uint16_t* raw_nox_ticks);

/**
 * @brief ll_svm4x_get_temperature_offset_for_rht_measurements
 *
 * Gets the T-Offset for the temperature compensation of the RHT algorithm. This
 * command is named get_temperature_offset in the datasheet.
 *
 * @param[out] t_offset Temperature offset which is used for the RHT
 * measurements. Values are in degrees celsius with a scaling of 200. Thus the
 * received value must be divided by 200.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t ll_svm4x_get_temperature_offset_for_rht_measurements(int16_t* t_offset);

/**
 * @brief svm4x_get_voc_tuning_parameters
 *
 * Gets the currently set parameters for customizing the VOC algorithm. This
 * command is named get_voc_parameters in the datasheet.
 *
 * @param[out] voc_index_offset VOC index representing typical (average)
 * conditions.
 * @param[out] learning_time_offset_hours Time constant to estimate the VOC
 * algorithm offset from the history in hours. Past events will be forgotten
 * after about twice the learning time.
 * @param[out] learning_time_gain_hours Time constant to estimate the VOC
 * algorithm gain from the history in hours. Past events will be forgotten after
 * about twice the learning time.
 * @param[out] gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high VOC index signal). Set to zero to disable
 * the gating.
 * @param[out] std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations.
 * @param[out] gain_factor Gain factor to amplify or to attenuate the VOC index
 * output.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_voc_tuning_parameters(int16_t* voc_index_offset,
                                        int16_t* learning_time_offset_hours,
                                        int16_t* learning_time_gain_hours,
                                        int16_t* gating_max_duration_minutes,
                                        int16_t* std_initial,
                                        int16_t* gain_factor);

/**
 * @brief svm4x_get_nox_tuning_parameters
 *
 * Gets the currently set parameters for customizing the NOx algorithm. This
 * command is named get_nox_parameters in the datasheet.
 *
 * @param[out] nox_index_offset NOx index representing typical (average)
 * conditions.
 * @param[out] learning_time_offset_hours Time constant to estimate the NOx
 * algorithm offset from the history in hours. Past events will be forgotten
 * after about twice the learning time.
 * @param[out] learning_time_gain_hours The time constant to estimate the NOx
 * algorithm gain from the history has no impact for NOx. This parameter is
 * still in place for consistency reasons with the VOC tuning parameters
 * command. This getter will always return the default value.
 * @param[out] gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high NOx index signal). Set to zero to disable
 * the gating.
 * @param[out] std_initial The initial estimate for standard deviation has no
 * impact for NOx. This parameter is still in place for consistency reasons with
 * the VOC tuning parameters command. This getter will always return the default
 * value.
 * @param[out] gain_factor Gain factor to amplify or to attenuate the NOx index
 * output.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_nox_tuning_parameters(int16_t* nox_index_offset,
                                        int16_t* learning_time_offset_hours,
                                        int16_t* learning_time_gain_hours,
                                        int16_t* gating_max_duration_minutes,
                                        int16_t* std_initial,
                                        int16_t* gain_factor);

/**
 * @brief svm4x_store_nv_data
 *
 * This command stores all parameters previously set with the commands
 * set_temperature_offset_for_rht_measurements, set_voc_tuning_parameters and
 * set_nox_tuning_parameters to the non-volatile memory of SVM4x. These
 * parameters will not be erased during reset and will be used by the
 * corresponding algorithms after start-up. To reset the storage to factory
 * settings the master has to set all parameters to the default values followed
 * by a subsequent call of the store_nv_data command. This command is named
 * store_input_parameters in the datasheet.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_store_nv_data();

/**
 * @brief ll_svm4x_set_temperature_offset_for_rht_measurements
 *
 * Sets the T-Offset for the temperature compensation of the RHT algorithm.
 *
 * @param[in] t_offset Temperature offset in degrees celsius. Accepted data
 * formats is a int16 value (2 bytes). Values are in degrees celsius with a
 * scaling of 200. Thus the provided value must be multiplied by 200.
 *
 * @note Execute the store command after writing the parameter to store it in
 * the non- volatile memory of the device otherwise the parameter will be reset
 * upton a device reset.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t ll_svm4x_set_temperature_offset_for_rht_measurements(int16_t t_offset);

/**
 * @brief svm4x_set_voc_tuning_parameters
 *
 * Sets parameters to customize the VOC algorithm. This command is only
 * available in idle mode. This command is named set_voc_parameters in the
 * datasheet.
 *
 * @param[in] voc_index_offset VOC index representing typical (average)
 * conditions. Allowed values are in range 1..250. The default value is 100.
 * @param[in] learning_time_offset_hours Time constant to estimate the VOC
 * algorithm offset from the history in hours. Past events will be forgotten
 * after about twice the learning time. Allowed values are in range 1..1000. The
 * default value is 12 hours.
 * @param[in] learning_time_gain_hours Time constant to estimate the VOC
 * algorithm gain from the history in hours. Past events will be forgotten after
 * about twice the learning time. Allowed values are in range 1..1000. The
 * default value is 12 hours.
 * @param[in] gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high VOC index signal). Set to zero to disable
 * the gating. Allowed values are in range 0..3000. The default value is 180
 * minutes.
 * @param[in] std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. Allowed values are in range 10..5000. The
 * default value is 50.
 * @param[in] gain_factor Gain factor to amplify or to attenuate the VOC index
 * output. Allowed values are in range 1..1000. The default value is 230.
 *
 * @note Execute the store command after writing the parameter to store it in
 * the non- volatile memory of the device otherwise the parameter will be reset
 * upton a device reset.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_set_voc_tuning_parameters(int16_t voc_index_offset,
                                        int16_t learning_time_offset_hours,
                                        int16_t learning_time_gain_hours,
                                        int16_t gating_max_duration_minutes,
                                        int16_t std_initial,
                                        int16_t gain_factor);

/**
 * @brief svm4x_set_nox_tuning_parameters
 *
 * Sets parameters to customize the NOx algorithm. This command is only
 * available in idle mode. This command is named set_nox_parameters in the
 * datasheet.
 *
 * @param[in] nox_index_offset NOx index representing typical (average)
 * conditions. Allowed values are in range 1..250. The default value is 1.
 * @param[in] learning_time_offset_hours Time constant to estimate the NOx
 * algorithm offset from the history in hours. Past events will be forgotten
 * after about twice the learning time. Allowed values are in range 1..1000. The
 * default value is 12 hours.
 * @param[in] learning_time_gain_hours The time constant to estimate the NOx
 * algorithm gain from the history has no impact for the NOx algorithm. This
 * parameter is still in place for consistency reasons with the VOC tuning
 * parameters command. This parameter must always be set to 12 hours.
 * @param[in] gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high NOx index signal). Set to zero to disable
 * the gating. Allowed values are in range 0..3000. The default value is 720
 * minutes.
 * @param[in] std_initial The initial estimate for standard deviation parameter
 * has no impact for the NOx algorithm. This parameter is still in place for
 * consistency reasons with the VOC tuning parameters command. This parameter
 * must always be set to 50.
 * @param[in] gain_factor Gain factor to amplify or to attenuate the NOx index
 * output. Allowed values are in range 1..1000. The default value is 230.
 *
 * @note Execute the store command after writing the parameter to store it in
 * the non- volatile memory of the device otherwise the parameter will be reset
 * upton a device reset.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_set_nox_tuning_parameters(int16_t nox_index_offset,
                                        int16_t learning_time_offset_hours,
                                        int16_t learning_time_gain_hours,
                                        int16_t gating_max_duration_minutes,
                                        int16_t std_initial,
                                        int16_t gain_factor);

/**
 * @brief svm4x_get_voc_state
 *
 * Gets the current VOC algorithm state. Retrieved values can be used to set the
 * VOC algorithm state to resume operation after a short interruption, skipping
 * initial learning phase. This command is only available during measurement
 * mode.
 *
 * @param[out] state Current VOC algorithm state.
 *
 * @note This feature can only be used after at least 3 hours of continuous
 * operation.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_voc_state(uint8_t* state, uint16_t state_size);

/**
 * @brief svm4x_get_nox_state
 *
 * Gets the current NOx algorithm state. Retrieved values can be used to set the
 * NOx algorithm state to resume operation after a short interruption, skipping
 * initial learning phase. This command is only available during measurement
 * mode.
 *
 * @param[out] state Current NOx algorithm state.
 *
 * @note This feature can only be used after at least 3 hours of continuous
 * operation.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_get_nox_state(uint8_t* state, uint16_t state_size);

/**
 * @brief svm4x_set_voc_state
 *
 * Set previously retrieved VOC algorithm state to resume operation after a
 * short interruption, skipping initial learning phase. This command is only
 * available in idle mode.
 *
 * @param[in] state Current VOC algorithm state.
 *
 * @note This feature should not be used after interruptions of more than 10
 * minutes.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_set_voc_state(const uint8_t* state, uint16_t state_size);

/**
 * @brief svm4x_set_nox_state
 *
 * Set previously retrieved NOx algorithm state to resume operation after a
 * short interruption, skipping initial learning phase. This command is only
 * available in idle mode.
 *
 * @param[in] state Current NOx algorithm state.
 *
 * @note This feature should not be used after interruptions of more than 10
 * minutes.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t svm4x_set_nox_state(const uint8_t* state, uint16_t state_size);

#ifdef __cplusplus
}
#endif
#endif  // SVM4X_UART_H
