#ifndef JSD_EL3054_TYPES_H
#define JSD_EL3054_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "jsd/jsd_common_device_types.h"

#define JSD_EL3054_PRODUCT_CODE (uint32_t)0x0BEE3052
#define JSD_EL3054_NUM_CHANNELS 4

/**
 * @brief Configuration struct for EL3054 device initialization
 */
typedef struct {
} jsd_el3054_config_t;

/**
 * @brief Read struct for EL3054 device
 */
typedef struct {
  double  current_mA[JSD_EL3054_NUM_CHANNELS];    ///< Analog input data, converted
  int16_t adc_value[JSD_EL3054_NUM_CHANNELS];  ///< Analog input data, raw
  uint8_t underrange[JSD_EL3054_NUM_CHANNELS];  ///< True if value below
                                                ///< measuring range
  uint8_t
          overrange[JSD_EL3054_NUM_CHANNELS];  ///< True if measuring range exceeded
  uint8_t error[JSD_EL3054_NUM_CHANNELS];  ///< True if channel is over or under
                                           ///< range
  uint8_t
          txPDO_state[JSD_EL3054_NUM_CHANNELS];  ///< 0 - data is valid, 1 otherwise
  uint8_t txPDO_toggle[JSD_EL3054_NUM_CHANNELS];  ///< toggled on new data
} jsd_el3054_state_t;

#ifdef __cplusplus
}
#endif

#endif
