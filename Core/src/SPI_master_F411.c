/*
 * SPI_master_F411.c
 *
 *  Created on: Oct 27, 2024
 *      Author: ganibllo
 */


#include "SPI_master_F411.h"

//
//  Functions
//
static bool ARM_SPI_Initialize(void){

	return 0;
}

static bool ARM_SPI_Uninitialize(void){

}

static int32_t ARM_SPI_PowerControl(ARM_POWER_STATE state)
{
    switch (state)
    {
    case ARM_POWER_OFF:
        break;

    case ARM_POWER_LOW:
        break;

    case ARM_POWER_FULL:
        break;
    }
    return ARM_DRIVER_OK;
}

static int32_t ARM_SPI_Send(const void *data, uint32_t num){
;
}

static int32_t ARM_SPI_Receive(void *data, uint32_t num){
;
}

static int32_t ARM_SPI_Transfer(const void *data_out, void *data_in, uint32_t num){
;
}

static uint32_t ARM_SPI_GetDataCount(void){
	;
}

static int32_t ARM_SPI_Control(uint32_t control, uint32_t arg)
{
    switch (control & ARM_SPI_CONTROL_Msk)
    {
    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;

    case ARM_SPI_MODE_INACTIVE:             // SPI Inactive
        return ARM_DRIVER_OK;

    case ARM_SPI_MODE_MASTER:               // SPI Master (Output on MOSI, Input on MISO); arg = Bus Speed in bps
        break;

    case ARM_SPI_MODE_SLAVE:                // SPI Slave  (Output on MISO, Input on MOSI)
        break;

    case ARM_SPI_SET_BUS_SPEED:             // Set Bus Speed in bps; arg = value
        break;

    case ARM_SPI_GET_BUS_SPEED:             // Get Bus Speed in bps
        break;

    case ARM_SPI_SET_DEFAULT_TX_VALUE:      // Set default Transmit value; arg = value
        break;

    case ARM_SPI_CONTROL_SS:                // Control Slave Select; arg = 0:inactive, 1:active
        break;

    case ARM_SPI_ABORT_TRANSFER:            // Abort current data transfer
        break;
    }
}

static ARM_SPI_STATUS ARM_SPI_GetStatus(void){
;
}

static void ARM_SPI_SignalEvent(uint32_t event)
{
	;
    // function body
}

// End SPI Interface

extern \
ARM_DRIVER_SPI Driver_SPI0;
ARM_DRIVER_SPI Driver_SPI0 = {
    ARM_SPI_Initialize,
    ARM_SPI_Uninitialize,
    ARM_SPI_PowerControl,
    ARM_SPI_Send,
    ARM_SPI_Receive,
    ARM_SPI_Transfer,
    ARM_SPI_GetDataCount,
    ARM_SPI_Control,
    ARM_SPI_GetStatus
};
