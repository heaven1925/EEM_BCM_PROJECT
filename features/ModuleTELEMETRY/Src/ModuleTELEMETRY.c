/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleTELEMETRY.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM TELEMETRY Module
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleTELEMETRY_private.h"

/************************** DEFINES ********************************************/
#define	MODULETELEMETRY_MAIN_THREAD

ModuleTELEMETRY_MAIN_State_et ModuleTELEMETRY_MAIN_State = ModuleTELEMETRY_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleTELEMETRY_HWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleTELEMETRY_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleTELEMETRY_StartUP(void)
{
	ModuleTELEMETRY_HWInit();
	ModuleTELEMETRY_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULETELEMETRY_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleTELEMETRY_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleTELEMETRY_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleTELEMETRY_MAIN(void)
{

	switch(ModuleTELEMETRY_MAIN_State)
	{
	    case ModuleTELEMETRY_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleTELEMETRY_MAIN_State = ModuleTELEMETRY_MAIN_State_ROUTINE;
	    break;

	    case ModuleTELEMETRY_MAIN_State_ROUTINE:

	    	ModuleTELEMETRY_MAIN_Routine();
	    break;

	    case ModuleTELEMETRY_MAIN_State_PROCESS:

	    	ModuleTELEMETRY_MAIN_Process();

	    break;

	    case ModuleTELEMETRY_MAIN_State_SUSPEND:
	    	ModuleTELEMETRY_MAIN_State = ModuleTELEMETRY_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleTELEMETRY_MAIN_State = ModuleTELEMETRY_MAIN_State_SUSPEND;
	    break;

	}

}


#endif

