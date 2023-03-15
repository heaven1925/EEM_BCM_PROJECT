/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModulePOWERSWITCH.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM POWERSWITCH Module
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModulePOWERSWITCH_private.h"

/************************** DEFINES ********************************************/
#define	MODULEPOWERSWITCH_MAIN_THREAD

ModulePOWERSWITCH_MAIN_State_et ModulePOWERSWITCH_MAIN_State = ModulePOWERSWITCH_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModulePOWERSWITCH_HWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModulePOWERSWITCH_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModulePOWERSWITCH_StartUP(void)
{
	ModulePOWERSWITCH_HWInit();
	ModulePOWERSWITCH_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULEPOWERSWITCH_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModulePOWERSWITCH_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModulePOWERSWITCH_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModulePOWERSWITCH_MAIN(void)
{

	switch(ModulePOWERSWITCH_MAIN_State)
	{
	    case ModulePOWERSWITCH_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModulePOWERSWITCH_MAIN_State = ModulePOWERSWITCH_MAIN_State_ROUTINE;
	    break;

	    case ModulePOWERSWITCH_MAIN_State_ROUTINE:

	    	ModulePOWERSWITCH_MAIN_Routine();
	    break;

	    case ModulePOWERSWITCH_MAIN_State_PROCESS:

	    	ModulePOWERSWITCH_MAIN_Process();

	    break;

	    case ModulePOWERSWITCH_MAIN_State_SUSPEND:
	    	ModulePOWERSWITCH_MAIN_State = ModulePOWERSWITCH_MAIN_State_IDLE;
	    break;

	    default:
	    	ModulePOWERSWITCH_MAIN_State = ModulePOWERSWITCH_MAIN_State_SUSPEND;
	    break;

	}

}


#endif

