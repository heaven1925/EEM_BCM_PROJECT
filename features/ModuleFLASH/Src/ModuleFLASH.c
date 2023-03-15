/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleFLASH.h
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM FLASH Module
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleFLASH_private.h"

/************************** DEFINES ********************************************/
#define	MODULEFLASH_MAIN_THREAD

ModuleFLASH_MAIN_State_et ModuleFLASH_MAIN_State = ModuleFLASH_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleFLASH_HWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleFLASH_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleFLASH_StartUP(void)
{
	ModuleFLASH_HWInit();
	ModuleFLASH_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULEFLASH_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleFLASH_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleFLASH_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleFLASH_MAIN(void)
{

	switch(ModuleFLASH_MAIN_State)
	{
	    case ModuleFLASH_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleFLASH_MAIN_State = ModuleFLASH_MAIN_State_ROUTINE;
	    break;

	    case ModuleFLASH_MAIN_State_ROUTINE:

	    	ModuleFLASH_MAIN_Routine();
	    break;

	    case ModuleFLASH_MAIN_State_PROCESS:

	    	ModuleFLASH_MAIN_Process();

	    break;

	    case ModuleFLASH_MAIN_State_SUSPEND:
	    	ModuleFLASH_MAIN_State = ModuleFLASH_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleFLASH_MAIN_State = ModuleFLASH_MAIN_State_SUSPEND;
	    break;

	}

}


#endif

