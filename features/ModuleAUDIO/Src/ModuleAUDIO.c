/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleAUDIO.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM Audio 
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleAUDIO_private.h"

/************************** DEFINES ********************************************/
#define	MODULEAUDIO_MAIN_THREAD

ModuleAUDIO_MAIN_State_et ModuleAUDIO_MAIN_State = ModuleAUDIO_MAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleAUDIO_HWInit(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleAUDIO_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleAUDIO_StartUP(void)
{
	ModuleAUDIO_HWInit();
	ModuleAUDIO_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULEAUDIO_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleAUDIO_MAIN_Routine(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleAUDIO_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleAUDIO_MAIN(void)
{

	switch(ModuleAUDIO_MAIN_State)
	{
	    case ModuleAUDIO_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleAUDIO_MAIN_State = ModuleAUDIO_MAIN_State_ROUTINE;
	    break;

	    case ModuleAUDIO_MAIN_State_ROUTINE:

	    	ModuleAUDIO_MAIN_Routine();
	    break;

	    case ModuleAUDIO_MAIN_State_PROCESS:

	    	ModuleAUDIO_MAIN_Process();

	    break;

	    case ModuleAUDIO_MAIN_State_SUSPEND:
	    	ModuleAUDIO_MAIN_State = ModuleAUDIO_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleAUDIO_MAIN_State = ModuleAUDIO_MAIN_State_SUSPEND;
	    break;

	}
}


#endif

