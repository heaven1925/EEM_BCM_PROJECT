/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleSDCARD.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM SDCARD MODULE
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleSDCARD_private.h"

/************************** DEFINES ********************************************/
#define	MODULESDCARDN_MAIN_THREAD

ModuleSDCARD_MAIN_State_et ModuleSDCARD_MAIN_State = ModuleSDCARD_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleSDCARD_HWInit(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleSDCARD_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleSDCARD_StartUP(void)
{
	ModuleSDCARD_HWInit();
	ModuleSDCARD_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULESDCARDN_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleSDCARD_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleSDCARD_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleSDCARD_MAIN(void)
{
	switch(ModuleSDCARD_MAIN_State)
	{
	    case ModuleSDCARD_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleSDCARD_MAIN_State = ModuleSDCARD_MAIN_State_ROUTINE;
	    break;

	    case ModuleSDCARD_MAIN_State_ROUTINE:

	    	ModuleSDCARD_MAIN_Routine();
	    break;

	    case ModuleSDCARD_MAIN_State_PROCESS:

	    	ModuleSDCARD_MAIN_Process();

	    break;

	    case ModuleSDCARD_MAIN_State_SUSPEND:
	    	ModuleSDCARD_MAIN_State = ModuleSDCARD_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleSDCARD_MAIN_State = ModuleSDCARD_MAIN_State_SUSPEND;
	    break;

	}
}


#endif

