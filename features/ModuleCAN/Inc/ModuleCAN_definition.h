/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleCAN_definition.h
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil CAN Stack
********************************************************************************/

#ifndef __CAN_MODULE_DEFINITION_H__
#define	__CAN_MODULE_DEFINITION_H__

	
	
/*********************** INCLUDES **********************************************/

#include "types.h"


/*********************** DEFINES ***********************************************/

typedef enum
{
	ModuleCAN_MAIN_State_IDLE = 0,
	ModuleCAN_MAIN_State_ROUTINE ,
	ModuleCAN_MAIN_State_PROCESS ,
	ModuleCAN_MAIN_State_SUSPEND ,

}ModuleCAN_MAIN_State_et;
	
typedef enum
{
	ModuleCAN_PROCESS_State_IDLE = 0 ,
	/*******************************/
	ModuleCAN_PROCESS_State_MSG01 ,
	ModuleCAN_PROCESS_State_MSG02 ,
	ModuleCAN_PROCESS_State_MSG03 ,
	ModuleCAN_PROCESS_State_MSG04 ,
	ModuleCAN_PROCESS_State_MSG05 ,
	ModuleCAN_PROCESS_State_MSG06 ,
	ModuleCAN_PROCESS_State_MSG07 ,
	ModuleCAN_PROCESS_State_MSG08 ,
	/*******************************/
	ModuleCAN_PROCESS_State_SUSPEND ,
}ModuleCAN_PROCESS_State_et;


/********************** FUNCTION PROTOTYPE **************************************/	
	

	
	
	
	
#endif /*__CAN_MODULE_DEFINITION_H__ */	

/*********************** END OF FILE ********************************************/
















































