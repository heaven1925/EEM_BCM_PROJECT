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

extern  BCM_Module_st	BCM_MSG;
extern  HVAC_Module_st	HVAC_MSG;
extern  SCB_Module_st	SCB_MSG;
extern  BMS_Module_st	BMS_MSG;
extern  MS1_Module_st	MS1_MSG;
extern  MS2_Module_st	MS2_MSG;
extern  ISO_Module_st	ISO_MSG;
extern  TLM_Module_st	TLM_MSG;
extern  YSB_Module_st	YSB_MSG;

#define TEST_CAN



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
	else
	{
		/* Set Motor Speeds */
		adcModule.ops.setMotorSpeed( &BCM_MSG, adcModule.obj );
		/* Set Motor Directions */
		adcModule.ops.setAnalogSignals( &BCM_MSG, adcModule.obj );

#ifndef TEST_ADC_V1

		BCM_MSG.Message04.payload[0] = (uint8_t)(adcModule.obj->RS_VRx >> 8 );
		BCM_MSG.Message04.payload[1] = (uint8_t)(adcModule.obj->RS_VRx & 0xFF );

		BCM_MSG.Message04.payload[2] = (uint8_t)(adcModule.obj->RS_VRy >> 8 );
		BCM_MSG.Message04.payload[3] = (uint8_t)(adcModule.obj->RS_VRy & 0xFF );

		BCM_MSG.Message04.payload[4] = (uint8_t)(adcModule.obj->LS_VRx >> 8 );
		BCM_MSG.Message04.payload[5] = (uint8_t)(adcModule.obj->LS_VRx & 0xFF );

		BCM_MSG.Message04.payload[6] = (uint8_t)(adcModule.obj->LS_VRy >> 8 );
		BCM_MSG.Message04.payload[7] = (uint8_t)(adcModule.obj->LS_VRy & 0xFF );

#else

#endif

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

