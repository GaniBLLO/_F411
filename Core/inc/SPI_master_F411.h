/*
 * SPI_master_F411.h
 *
 *  Created on: Oct 27, 2024
 *      Author: ganibllo
 */

#ifndef INC_SPI_MASTER_F411_H_
#define INC_SPI_MASTER_F411_H_

#include "main.h"
#include "Stm_Status.h"

/****** SPI Control Codes *****/
#define ARM_SPI_CONTROL_Pos              0
#define ARM_SPI_CONTROL_Msk             (0xFFUL << ARM_SPI_CONTROL_Pos)

/****** SPI Slave Select Signal definitions *****/
#define ARM_SPI_SS_INACTIVE              0UL                                ///< SPI Slave Select Signal Inactive
#define ARM_SPI_SS_ACTIVE                1UL                                ///< SPI Slave Select Signal Active


/*----- SPI Control Codes: Miscellaneous Controls  -----*/
#define ARM_SPI_SET_BUS_SPEED           (0x10UL << ARM_SPI_CONTROL_Pos)     ///< Set Bus Speed in bps; arg = value
#define ARM_SPI_GET_BUS_SPEED           (0x11UL << ARM_SPI_CONTROL_Pos)     ///< Get Bus Speed in bps
#define ARM_SPI_SET_DEFAULT_TX_VALUE    (0x12UL << ARM_SPI_CONTROL_Pos)     ///< Set default Transmit value; arg = value
#define ARM_SPI_CONTROL_SS              (0x13UL << ARM_SPI_CONTROL_Pos)     ///< Control Slave Select; arg: 0=inactive, 1=active
#define ARM_SPI_ABORT_TRANSFER          (0x14UL << ARM_SPI_CONTROL_Pos)     ///< Abort current data transfer


/*----- SPI Control Codes: Mode -----*/
#define ARM_SPI_MODE_INACTIVE           (0x00UL << ARM_SPI_CONTROL_Pos)     ///< SPI Inactive
#define ARM_SPI_MODE_MASTER             (0x01UL << ARM_SPI_CONTROL_Pos)     ///< SPI Master (Output on MOSI, Input on MISO); arg = Bus Speed in bps
#define ARM_SPI_MODE_SLAVE              (0x02UL << ARM_SPI_CONTROL_Pos)     ///< SPI Slave  (Output on MISO, Input on MOSI)
#define ARM_SPI_MODE_MASTER_SIMPLEX     (0x03UL << ARM_SPI_CONTROL_Pos)     ///< SPI Master (Output/Input on MOSI); arg = Bus Speed in bps @deprecated Simplex Mode has been removed
#define ARM_SPI_MODE_SLAVE_SIMPLEX      (0x04UL << ARM_SPI_CONTROL_Pos)     ///< SPI Slave  (Output/Input on MISO) @deprecated Simplex Mode has been removed


/**
\brief SPI Status
*/
typedef struct _ARM_SPI_STATUS {
	uint32_t busy       : 1;              ///< Transmitter/Receiver busy flag
	uint32_t data_lost  : 1;              ///< Data lost: Receive overflow / Transmit underflow (cleared on start of transfer operation)
	uint32_t mode_fault : 1;              ///< Mode fault detected; optional (cleared on start of transfer operation)
	uint32_t reserved   : 29;
} ARM_SPI_STATUS;


/**
\brief Access structure of the SPI Driver.
*/
typedef struct _ARM_DRIVER_SPI {
	bool	             (*Initialize)      (void);
	bool             	 (*Uninitialize)    (void);
	int32_t              (*PowerControl)    (ARM_POWER_STATE state);            ///< Pointer to \ref ARM_SPI_PowerControl : Control SPI Interface Power.
	int32_t              (*Send)            (const void *data, uint32_t num);   ///< Pointer to \ref ARM_SPI_Send : Start sending data to SPI Interface.
	int32_t              (*Receive)         (      void *data, uint32_t num);   ///< Pointer to \ref ARM_SPI_Receive : Start receiving data from SPI Interface.
	int32_t              (*Transfer)        (const void *data_out,
												   void *data_in,
												   uint32_t num);                  ///< Pointer to \ref ARM_SPI_Transfer : Start sending/receiving data to/from SPI.
	uint32_t             (*GetDataCount)    (void);                             ///< Pointer to \ref ARM_SPI_GetDataCount : Get transferred data count.
	int32_t              (*Control)         (uint32_t control, uint32_t arg);   ///< Pointer to \ref ARM_SPI_Control : Control SPI Interface.
	ARM_SPI_STATUS       (*GetStatus)       (void);                             ///< Pointer to \ref ARM_SPI_GetStatus : Get SPI status.
} const ARM_DRIVER_SPI;


#endif /* INC_SPI_MASTER_F411_H_ */
