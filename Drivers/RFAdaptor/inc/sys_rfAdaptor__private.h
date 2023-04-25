/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    sys_rfAdaptor__private.h
  * @author	 Muhammet EFE , Atakan ERTEKiN
  * @version V1.0.0
  * @date		 16.09.2022
  * @rev     V1.0.0
  * @brief	 
********************************************************************************/
/************************************DEFINES***********************************/
#ifndef	__SYS_RFADAPTOR__PRIVATE_H__
#define __SYS_RFADAPTOR__PRIVATE_H__
/************************************INCLUDES***********************************/

#include "sys_rfAdaptor__definition.h"


//#include "LmHandler.h"
#include "sx1262__public.h"			//@ADD aertekin 
#include "radio.h"					//@ADD aertekin

/******************************************************************************/
rf_uint8_t syncWordTx[8] 		 = { 0x54, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
rf_uint8_t syncWordRx[8] 		 = { 0x54, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
/******************************************************************************/

/******************************************************************************/
//@INFO: RFAdaptor Temel Tanimlamalari

sys_rfAdaptor_generalflags_ut		sys_rfAdaptor_generalflags;

// sys_rfAdaptor_RFSTATUS_st 		sys_rfAdaptor_RFSTATUS	=	{0}			;
rf_uint32_t							sys_rfAdaptor_delayCounter	=	0			;

//struct rt_spi_device 				rt_spi_rfAdaptor			= { RT_NULL	}	;

typdef_rfAdaptor_irqHandlers		sys_rfAdaptor_irqHandlers	= { 0 }			;

typedef_rfAdaptor_device_st			typdef_rfAdaptor_dev 		;
/******************************************************************************/

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[					
//@NOTICE: Public Function Decleration
/******************************************************************************/
//@INFO: RFAdaptor Read-Write Tanimlamalari
rf_err_t 				sys_rfAdaptor_writeCommand						( RadioCommands_t command  	,
																		  rf_uint8_t *buffer		,
																		  rf_uint16_t size 			);
rf_err_t 				sys_rfAdaptor_readStatus						( rf_uint8_t *buffer 		);
rf_err_t 				sys_rfAdaptor_readCommand						( RadioCommands_t command	,
																	      rf_uint8_t *buffer		,
																	      rf_size_t size 			);
rf_err_t				sys_rfAdaptor_writeRegisters					( rf_uint16_t 	address		,
																	      rf_uint8_t* 	buffer		,
																	      rf_size_t		size		);
rf_err_t 				sys_rfAdaptor_writeRegister						( rf_uint16_t 	address		,
																		  rf_uint8_t 	value		);
rf_err_t				sys_rfAdaptor_readRegisters						( rf_uint16_t 	address		,
																	      rf_uint8_t*	buffer		,
																	      rf_size_t	     size		);
rf_uint8_t				sys_rfAdaptor_readRegister						( rf_uint16_t 	address		);

rf_err_t				sys_rfAdaptor_writeBuffer						( rf_uint8_t *buffer		,
																		  rf_size_t size 			);
rf_err_t				sys_rfAdaptor_readBuffer						( rf_uint8_t *buffer		,
																	      rf_size_t size 			,
																	      rf_size_t	offset			);
void 					sys_rfAdaptor_setOperatingMode					( rf_uint8_t mode 			);
rf_uint8_t 				sys_rfAdaptor_getOperatingMode					( void 						);
//@INFO: RFAdaptor Init/Config for Modules
typedef_rfAdaptor_device_st		sys_rfAdaptor_driverInit				( void 						);

rf_err_t 				sys_rfAdaptor_changeChipMode		 			( rf_uint8_t mode			,
																		  rf_uint8_t modeConfig		,
																		  rf_uint32_t timeout		);

rf_err_t 				sys_rfAdaptor_specificSettings	 				( rf_uint8_t rfMode 		,
																		  rf_uint8_t mode 			,
																		  rf_uint8_t direction		);

rf_err_t 				sys_rfAdaptor_defaultParameters	 				( void 						);
rf_err_t 				sys_rfAdaptor_init							 	(	rf_uint8_t mode			);
rf_err_t				sys_rfAdaptor_deInit						 	( void 						);
rf_err_t 				sys_rfAdaptor_initConfig				 		( void 						);


//@INFO: RFAdaptor Blocking Delay / irqRead
void 					DelayMs											( rf_uint32_t delayTime 	);
rf_bool_t 				sys_rfAdaptor_readPin							( void 						);
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
																													
																													
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[				
//@NOTICE: Private Function Decleration
/******************************************************************************/
//@INFO: RFAdaptor Base Init Functions
rf_err_t 				sys_rfAdaptor_gpioInit					 		( void						);
rf_err_t 				sys_rfAdaptor_spiInit						 	( void						);
rf_err_t 				sys_rfAdaptor_HW_Init						 	( void						);
rf_err_t 				sys_rfAdaptor_HW_deInit					 		( void						);
																													
/******************************************************************************/
//@INFO: RF Adaptor Interrupt Config / Functions
rf_err_t			    sys_rfAdaptor_tcxoInit					 		( void 						);
rf_err_t			    sys_rfAdaptor_setDio3AsTcxoCtrl	 				( RadioTcxoCtrlVoltage_t tcxoVoltage 	,
																		  rf_uint32_t timeout 		);
rf_err_t				sys_rfAdaptor_rfSwitchInit						( void 						);
rf_err_t				sys_rfAdaptor_setDio2AsRfSwitchCtrl				( rf_bool_t enable 			);

rf_err_t 				sys_rfAdaptor_rfIRQHandler						(	rf_uint16_t irqStatus	);
rf_err_t				sys_rfAdaptor_txDoneIRQHandler					(	void					);
rf_err_t				sys_rfAdaptor_rxDoneIRQHandler					(	void					);
rf_err_t				sys_rfAdaptor_timeOutIRQHandler					(	void					);
rf_err_t				sys_rfAdaptor_preambleDetectedIRQHandler		(	void					);
rf_err_t				sys_rfAdaptor_syncWordValidIRQHandler			(	void					);
rf_err_t				sys_rfAdaptor_crcError_IRQHandler				(	void					);
/******************************************************************************/

rf_err_t 				sys_rfAdaptor_hardwareTimerInit	 				( rf_uint32_t timeMS 		);
rf_err_t 				sys_rfAdaptor_btimerInit				 		( rf_uint32_t timeMS 		);
rf_err_t 				sys_rfAdaptor_btimerStart				 		( void 						);
rf_err_t				sys_rfAdaptor_btimerStop				 		( void 						);
void 					sys_rfAdaptor_delayMsBlocking		 			( rf_uint32_t delayTime 	);
/******************************************************************************/           		
//@INFO: Operating Mode  Functions                                                         		
rf_err_t				sys_rfAdaptor_checkDeviceReady	 				( void 						);
rf_err_t 			 	sys_rfAdaptor_waitOnBusy				 		( void 						);
rf_err_t				sys_rfAdaptor_chipReset					 		( void 						);
void 					sys_rfAdaptor_powerON							( void 						);
void 					sys_rfAdaptor_powerOFF					 		( void 						);
rf_err_t				sys_rfAdaptor_wakeUp				 			( void 						);
rf_err_t				sys_rfAdaptor_antSwMode			 				( void 						);
/******************************************************************************/           		
//@INFO: Init Routine Functions  

rf_err_t 				sys_rfAdaptor_EEM_RF_InitConfig					( rf_uint8_t wmBusMode 		,
																		  rf_uint8_t mode			);

void		 			sys_rfAdaptor_BT2ModeTxConfig					( typedef_rfAdaptor_device_st* dev	);
void		 			sys_rfAdaptor_BT2ModeRxConfig					( typedef_rfAdaptor_device_st* dev	);
/******************************************************************************/
//@INFO: EEM RF Mode Init
rf_err_t 				sys_rfAdaptor_ModeBT2							( typedef_rfAdaptor_device_st* dev	,
																	      rf_uint8_t mode					);




//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]


#endif //end __SYS_RFADAPTOR__PRIVATE_H__
/***********************************END OF FILE********************************/
