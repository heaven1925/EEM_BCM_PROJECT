/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    BodyControlMAIN.c
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM MAIN Thread
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "BodyControlMAIN_private.h"

/************************** DEFINES ********************************************/



#define	BODYCONTROL_MAIN_THREAD

BodyControlMAIN_State_et BodyControlMAIN_State = BodyControlMAIN_State_IDLE;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void BodyControlMAIN_HWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void BodyControlMAIN_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void BodyControlMAIN_StartUP(void)
{
	BodyControlMAIN_HWInit();
	BodyControlMAIN_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef BODYCONTROL_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void BodyControlMAIN_Routine(void)
{

	if( __GL.mainState.flag.adc == TRUE )
	{
		/* Release Periodically ADC Semph */
		Process_ADC_Run();
		__GL.mainState.flag.adc = FALSE;
	}

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void BodyControlMAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :s
	 @date	  :
	 @INFO		:
********************************************************************************/

void BodyControlMAIN(void)
{

	switch(BodyControlMAIN_State)
	{
	    case BodyControlMAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	BodyControlMAIN_State = BodyControlMAIN_State_ROUTINE;
	    break;

	    case BodyControlMAIN_State_ROUTINE:

	    	BodyControlMAIN_Routine();
	    break;

	    case BodyControlMAIN_State_PROCESS:

	    	BodyControlMAIN_Process();

	    break;

	    case BodyControlMAIN_State_SUSPEND:
	    	BodyControlMAIN_State = BodyControlMAIN_State_IDLE;
	    break;

	    default:
	    	BodyControlMAIN_State = BodyControlMAIN_State_SUSPEND;
	    break;

	}
}


#endif

