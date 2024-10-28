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

typedef struct
{
  uint32_t Mode;                /*!< Specifies the SPI operating mode.
                                     This parameter can be a value of @ref SPI_Mode */

  uint32_t Direction;           /*!< Specifies the SPI bidirectional mode state.
                                     This parameter can be a value of @ref SPI_Direction */

  uint32_t DataSize;            /*!< Specifies the SPI data size.
                                     This parameter can be a value of @ref SPI_Data_Size */

  uint32_t CLKPolarity;         /*!< Specifies the serial clock steady state.
                                     This parameter can be a value of @ref SPI_Clock_Polarity */

  uint32_t CLKPhase;            /*!< Specifies the clock active edge for the bit capture.
                                     This parameter can be a value of @ref SPI_Clock_Phase */

  uint32_t NSS;                 /*!< Specifies whether the NSS signal is managed by
                                     hardware (NSS pin) or by software using the SSI bit.
                                     This parameter can be a value of @ref SPI_Slave_Select_management */

  uint32_t BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                     used to configure the transmit and receive SCK clock.
                                     This parameter can be a value of @ref SPI_BaudRate_Prescaler
                                     @note The communication clock is derived from the master
                                     clock. The slave clock does not need to be set. */

  uint32_t FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
                                     This parameter can be a value of @ref SPI_MSB_LSB_transmission */

  uint32_t TIMode;              /*!< Specifies if the TI mode is enabled or not.
                                     This parameter can be a value of @ref SPI_TI_mode */

  uint32_t CRCCalculation;      /*!< Specifies if the CRC calculation is enabled or not.
                                     This parameter can be a value of @ref SPI_CRC_Calculation */

  uint32_t CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation.
                                     This parameter must be an odd number between Min_Data = 1 and Max_Data = 65535 */
} SPI_InitTypeDef;

/**
  * @brief  HAL SPI State structure definition
  */
typedef enum
{
  HAL_SPI_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
  HAL_SPI_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
  HAL_SPI_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
  HAL_SPI_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
  HAL_SPI_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
  HAL_SPI_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
  HAL_SPI_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
  HAL_SPI_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} HAL_SPI_StateTypeDef;

/**
  * @brief  SPI handle Structure definition
  */
typedef struct __SPI_HandleTypeDef
{
	SPI_TypeDef		*Instance;      //SPI current status
	SPI_InitTypeDef  Init;           /*!< SPI communication parameters             */

  uint8_t                    *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer        */

  uint16_t                   TxXferSize;     /*!< SPI Tx Transfer size                     */

  __IO uint16_t              TxXferCount;    /*!< SPI Tx Transfer Counter                  */

  uint8_t                    *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer        */

  uint16_t                   RxXferSize;     /*!< SPI Rx Transfer size                     */

  __IO uint16_t              RxXferCount;    /*!< SPI Rx Transfer Counter                  */

  void (*RxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Rx ISR       */

  void (*TxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Tx ISR       */

  DMA_HandleTypeDef          *hdmatx;        /*!< SPI Tx DMA Handle parameters             */

  DMA_HandleTypeDef          *hdmarx;        /*!< SPI Rx DMA Handle parameters             */

  HAL_LockTypeDef            Lock;           /*!< Locking object                           */

  __IO HAL_SPI_StateTypeDef  State;          /*!< SPI communication state                  */

  __IO uint32_t              ErrorCode;      /*!< SPI Error code                           */

} SPI_HandleTypeDef;
#endif /* INC_SPI_MASTER_F411_H_ */
