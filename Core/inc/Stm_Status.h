/*
 * Stm_Status.h
 *
 *  Created on: Oct 27, 2024
 *      Author: ganibllo
 */

#ifndef INC_STM_STATUS_H_
#define INC_STM_STATUS_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define ARM_DRIVER_VERSION_MAJOR_MINOR(major,minor) (((major) << 8) | (minor))


/* General return codes */
#define ARM_DRIVER_OK                 0 ///< Operation succeeded
#define ARM_DRIVER_ERROR             -1 ///< Unspecified error
#define ARM_DRIVER_ERROR_BUSY        -2 ///< Driver is busy
#define ARM_DRIVER_ERROR_TIMEOUT     -3 ///< Timeout occurred
#define ARM_DRIVER_ERROR_UNSUPPORTED -4 ///< Operation not supported
#define ARM_DRIVER_ERROR_PARAMETER   -5 ///< Parameter error
#define ARM_DRIVER_ERROR_SPECIFIC    -6 ///< Start of driver specific errors

/**
\brief General power states
*/
typedef enum _ARM_POWER_STATE {
  ARM_POWER_OFF,                        ///< Power off: no operation possible
  ARM_POWER_LOW,                        ///< Low Power mode: retain state, detect and signal wake-up events
  ARM_POWER_FULL                        ///< Power on: full operation at maximum performance
} ARM_POWER_STATE;


#endif /* INC_STM_STATUS_H_ */