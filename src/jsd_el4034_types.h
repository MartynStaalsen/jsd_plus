#ifndef JSD_EL4034_TYPES_H
#define JSD_EL4034_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "jsd/jsd_common_device_types.h"

#define JSD_EL4034_PRODUCT_CODE (uint32_t)0x0FC23052

#define JSD_EL4034_NUM_CHANNELS 4

/**
 * @brief Configuration struct for EL4034 device initialization
 */
typedef struct {
} jsd_el4034_config_t;

/**
 * @brief EL4034 state data
 */
typedef struct {
  int16_t dac_output[JSD_EL4034_NUM_CHANNELS];     ///< +/-10 V (0x7FFF-0x8001)
                                                   ///< analog output
  double voltage_output[JSD_EL4034_NUM_CHANNELS];  ///< Voltage equivalent of
                                                   ///< dac_output computed by
                                                   ///< this driver
} jsd_el4034_state_t;

#ifdef __cplusplus
}
#endif

#endif