/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    sys_rfAdaptor__public.h
  * @author	 Muhammet EFE , Atakan ERTEKiN
  * @version V1.0.0
  * @date		 16.09.2022
  * @rev     V1.0.0
  * @brief	 
********************************************************************************/
/************************************DEFINES***********************************/
#ifndef	__SYS_RFADAPTOR__PUBLIC_H__
#define __SYS_RFADAPTOR__PUBLIC_H__
/************************************INCLUDES***********************************/

#include "sys_rfAdaptor__definition.h"
#include "sx1262__definition.h"

/******************************************************************************/
extern 	sys_rfAdaptor_generalflags_ut			sys_rfAdaptor_generalflags		;
extern	rf_uint32_t								sys_rfAdaptor_delayCounter		;
extern 	rf_uint16_t								irqStatus						;

//@NEW: aertekin //@INFO: Kutuphane parametre ve fonksiyonlarina kapali erisim yapisi exclusuion
extern 	typedef_rfAdaptor_device_st				typdef_rfAdaptor_dev;

/******************************************************************************/
//@INFO: RFAdaptor Read-Write Tanimlamalari
extern	rf_err_t 				sys_rfAdaptor_writeCommand							( 	RadioCommands_t command  							,
																						rf_uint8_t*		buffer			 					,
																						rf_uint16_t 	size 				 				);
extern	rf_err_t 				sys_rfAdaptor_readStatus							( 	rf_uint8_t*		buffer 								);
extern	rf_err_t 				sys_rfAdaptor_readCommand							( 	RadioCommands_t command								,
																						rf_uint8_t*		buffer								,
																						rf_size_t 		size 								);
extern	rf_err_t				sys_rfAdaptor_writeRegisters						( 	rf_uint16_t 	address								,
																						rf_uint8_t* 	buffer								,
																						rf_size_t		size								);
extern	rf_err_t 				sys_rfAdaptor_writeRegister							( 	rf_uint16_t 	address								,
																						rf_uint8_t 		value								);
extern	rf_err_t				sys_rfAdaptor_readRegisters							( 	rf_uint16_t 	address								,
																						rf_uint8_t*		buffer								,
																						rf_size_t		size								);
extern	rf_uint8_t				sys_rfAdaptor_readRegister							( 	rf_uint16_t 	address								);

extern	rf_err_t				sys_rfAdaptor_writeBuffer							( 	rf_uint8_t*		buffer								,
																						rf_size_t 		size 								);
extern	rf_err_t				sys_rfAdaptor_readBuffer							( 	rf_uint8_t *	buffer								,
																						rf_size_t 		size 								,
																						rf_size_t		offset								);
extern	void 					sys_rfAdaptor_setOperatingMode						( 	rf_uint8_t	 	mode 								);
extern	rf_uint8_t 				sys_rfAdaptor_getOperatingMode						( 	void 												);
//@INFO: RFAdaptor Init/Config for Modules
extern	typedef_rfAdaptor_device_st		sys_rfAdaptor_driverInit					(	void 												);

extern	rf_err_t 				sys_rfAdaptor_changeChipMode		 				( 	rf_uint8_t 		mode								,
																						rf_uint8_t 		modeConfig					 		,
																						rf_uint32_t 	timeout								);
																													
extern	rf_err_t 				sys_rfAdaptor_specificSettings	 				    ( 	rf_uint8_t 		rfMode 								,
																				      	rf_uint8_t 		mode 								,
																				        rf_uint8_t 		direction							);
																													
extern	rf_err_t 				sys_rfAdaptor_defaultParameters	 					( void 													);
extern	rf_err_t 				sys_rfAdaptor_init							 		( rf_uint8_t 		mode								);
extern	rf_err_t				sys_rfAdaptor_deInit						 		( void 													);
extern	rf_err_t 				sys_rfAdaptor_initConfig				 			( void 													);

//@INFO: RFAdaptor Blocking Delay / irqRead
extern	void 					DelayMs												( rf_uint32_t delayTime 								);
extern	rf_bool_t 				sys_rfAdaptor_readPin								( void 													);


extern	void					sys_rfAdaptor_bootModeRxConfig					    (typedef_rfAdaptor_device_st* dev);
extern	void					sys_rfAdaptor_bootModeTxConfig					    (typedef_rfAdaptor_device_st* dev);
extern	void					sys_rfAdaptor_valveModeTxConfig					    (typedef_rfAdaptor_device_st* dev);
extern	void					sys_rfAdaptor_valveModeRxConfig					    (typedef_rfAdaptor_device_st* dev);
extern	void					sys_rfAdaptor_logModeTxConfig					    (typedef_rfAdaptor_device_st* dev);
extern	void					sys_rfAdaptor_logModeRxConfig					    (typedef_rfAdaptor_device_st* dev);



#endif //end __SYS_RFADAPTOR__PUBLIC_H__
