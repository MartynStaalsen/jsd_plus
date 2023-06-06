#ifndef JSD_EL4034_PUB_H
#define JSD_EL4034_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "jsd/jsd_el4034_types.h"
#include "jsd/jsd_pub.h"

/**
 * @brief Read the EL4034 device state
 *
 * Note: this device does not provide PDO feedback on state. This function reads
 * back the command sent to the EL4034 device.
 *
 * @param self Pointer to JSD context
 * @param slave_id Slave ID of EL4034 device
 * @return Pointer to EL4034 device state
 */
const jsd_el4034_state_t* jsd_el4034_get_state(jsd_t* self, uint16_t slave_id);

/**
 * @brief Writes the set commands into the SOEM IOmap and processes asynchronous
 * SDO responses
 *
 * @param self Pointer to JSD context
 * @param slave_id Slave ID of EL4034 device
 */
void jsd_el4034_process(jsd_t* self, uint16_t slave_id);

/**
 * @brief Sets the voltage (V) command for the given channel
 *
 * @param self Pointer to JSD context
 * @param slave_id Slave ID of EL4034 device
 * @param channel Device channel to command
 * @param output Commanded voltage. Provided value is clamped within [+/-10].
 */
void jsd_el4034_write_single_channel(jsd_t* self, uint16_t slave_id,
                                     uint8_t channel, double output);

/**
 * @brief Sets the voltage (V) command for each channel
 *
 * @param self Pointer to JSD context
 * @param slave_id Slave ID of EL4034 device
 * @param output Commanded voltages. Provided values are clamped within [+/-10].
 */
void jsd_el4034_write_all_channels(jsd_t* self, uint16_t slave_id,
                                   double output[JSD_EL4034_NUM_CHANNELS]);

#ifdef __cplusplus
}
#endif

#endif