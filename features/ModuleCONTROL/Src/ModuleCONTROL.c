/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleCONTROL.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM Control Module
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleCONTROL_private.h"

/************************** DEFINES ********************************************/
#define	MODULECONTROL_MAIN_THREAD

ModuleCONTROL_MAIN_State_et ModuleCONTROL_MAIN_State = ModuleCONTROL_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleCONTROL_HWInit(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleCONTROL_SWInit(void)
{
	//@INFO: WIFI thread'ine ait yazilimsal init fonksiyonları
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleCONTROL_StartUP(void)
{
	ModuleCONTROL_HWInit();
	ModuleCONTROL_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULECONTROL_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleCONTROL_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleCONTROL_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleCONTROL_MAIN(void)
{

	switch(ModuleCONTROL_MAIN_State)
	{
	    case ModuleCONTROL_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleCONTROL_MAIN_State = ModuleCONTROL_MAIN_State_ROUTINE;


	    case ModuleCONTROL_MAIN_State_ROUTINE:

	    	ModuleCONTROL_MAIN_Routine();
	    break;

	    case ModuleCONTROL_MAIN_State_PROCESS:

	    	ModuleCONTROL_MAIN_Process();

	    break;

	    case ModuleCONTROL_MAIN_State_SUSPEND:
	    	ModuleCONTROL_MAIN_State = ModuleCONTROL_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleCONTROL_MAIN_State = ModuleCONTROL_MAIN_State_SUSPEND;
	    break;

	}

}


#endif

