/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleADC.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM ADC Module
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleADC_private.h"

/************************** DEFINES ********************************************/
#define	MODULEADC_MAIN_THREAD

ModuleADC_MAIN_State_et ModuleADC_MAIN_State = ModuleADC_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleADC_HWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleADC_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleADC_StartUP(void)
{
	ModuleADC_HWInit();
	ModuleADC_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULEADC_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleADC_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleADC_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleADC_MAIN(void)
{
	switch(ModuleADC_MAIN_State)
	{
	    case ModuleADC_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleADC_MAIN_State = ModuleADC_MAIN_State_ROUTINE;
	    break;

	    case ModuleADC_MAIN_State_ROUTINE:

	    	ModuleADC_MAIN_Routine();
	    break;

	    case ModuleADC_MAIN_State_PROCESS:

	    	ModuleADC_MAIN_Process();

	    break;

	    case ModuleADC_MAIN_State_SUSPEND:
	    	ModuleADC_MAIN_State = ModuleADC_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleADC_MAIN_State = ModuleADC_MAIN_State_SUSPEND;
	    break;

	}
}


#endif

