
/*******************************************************************************
  * @file    app.c
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil SCB Telemetry MAIN Code
********************************************************************************/

/* Main application header definition*/
#include "app.h"

GL_st __attribute__((section(".ARM.__at_0x20000000"))) __GL   = {0}; //@INFO: 4 Kbyte


#include "BodyControlMAIN_public.h"

#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"


APP_StaticTask_TYPE 			xTaskBuffer		;
APP_StackType_TYPE 				xStack			;
APP_TaskHandle_TYPE 			xHandle			;
APP_StaticSemaphore_TYPE 		xSemaphore		;
APP_SemaphoreHandle_TYPE 		xSemHandle		;
APP_SemaphoreResult_TYPE 		xSemResult		;
APP_StaticTimer_TYPE 			xStaticTimer	;
APP_TimerID_TYPE				xTimerID		;
APP_StaticTimerDef_TYPE			xStaticTimerDef	;

/* CAN BroadCast Periodic Time attributes */
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast01_attributes =
{
  .name = PROCESS_BROADCAST01_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast01				,
  .cb_size = sizeof(xStaticTimerDef.broadcast01)		,
};

/* Broadcast02 Attributes */
const osTimerAttr_t APP_broadcast02_attributes =
{
  .name = PROCESS_BROADCAST02_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast02				,
  .cb_size = sizeof(xStaticTimerDef.broadcast02)		,
};

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast03_attributes =
{
  .name = PROCESS_BROADCAST03_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast03				,
  .cb_size = sizeof(xStaticTimerDef.broadcast03)		,
};

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast04_attributes =
{
  .name = PROCESS_BROADCAST04_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast04				,
  .cb_size = sizeof(xStaticTimerDef.broadcast04)		,
};

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast05_attributes =
{
  .name = PROCESS_BROADCAST05_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast05				,
  .cb_size = sizeof(xStaticTimerDef.broadcast05)		,
};

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast06_attributes =
{
  .name = PROCESS_BROADCAST06_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast06				,
  .cb_size = sizeof(xStaticTimerDef.broadcast06)		,
};

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast07_attributes =
{
  .name = PROCESS_BROADCAST07_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast07				,
  .cb_size = sizeof(xStaticTimerDef.broadcast07)		,
};

/* Broadcast01 Attributes */
const osTimerAttr_t APP_broadcast08_attributes =
{
  .name = PROCESS_BROADCAST08_SWTIMERNAME				,
  .cb_mem = &xStaticTimerDef.broadcast08				,
  .cb_size = sizeof(xStaticTimerDef.broadcast08)		,
};

//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

/* Periodic Timer attributes */
const osTimerAttr_t APP_periodic_attributes =
{
  .name = PROCESS_PERIODIC_SWTIMERNAME					,
  .cb_mem = &xStaticTimerDef.periodic					,
  .cb_size = sizeof(xStaticTimerDef.periodic)			,
};

/* timeout Timer attributes */
const osTimerAttr_t APP_timeout_attributes =
{
  .name = PROCESS_TIMEOUT_SWTIMERNAME					,
  .cb_mem = &xStaticTimerDef.timeout					,
  .cb_size = sizeof(xStaticTimerDef.timeout)			,
};

/********************************************************************************/

#if 1 /* Software Timer IRQ Handlers */

void APP_timeoutTimerIRQHandler(void* param)
{

}

void APP_periodicTimerIRQHandler(void* param)
{
	/* msg Tick Counter inc every 10ms */
	__GL.can.msgTickCounter_u32++;

	static U8 adcSequance;

	adcSequance = __GL.can.msgTickCounter_u32 % 6 ;
	if( adcSequance == 0 )
	{
		__GL.mainState.flag.adc = TRUE;
	}
	else
	{
		__GL.mainState.flag.adc = FALSE;
	}

}


/* BroadCast Timers IRQ Handlers */
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
void APP_broadcast01TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID01 = TRUE;
	Process_CAN_Run();
}
void APP_broadcast02TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID02 = TRUE;
	Process_CAN_Run();
}
void APP_broadcast03TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID03 = TRUE;
	Process_CAN_Run();
}
void APP_broadcast04TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID04 = TRUE;
	Process_CAN_Run();
}
void APP_broadcast05TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID05 = TRUE;
	Process_CAN_Run();
}
void APP_broadcast06TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID06 = TRUE;
	Process_CAN_Run();
}
void APP_broadcast07TimerIRQHandler(void* param)
{
	__GL.can.msgSelect.Flag.ID07 = TRUE;
	Process_CAN_Run();
}
//void APP_broadcast08TimerIRQHandler(void* param)
//{
//
//}

//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

#endif

#ifdef DEBUG_THREAD
void    DEBUG_printThread(char *threadName, char *threadStatus)
{

    char console_message[50] = {0};

    sprintf(&console_message[0], "%s is %s. \n", &threadName[0], &threadStatus[0]);

    HAL_UART_Transmit(&DEBUG_UART, (U8 *)&console_message[0], sizeof(console_message), 10);
    return;

}
#endif


void Initilialise_App(void)
{
	/***************** Create Static Threads ******************************/

#ifdef BSP_PROCESS_BODYCONTROLMAIN
	xHandle.Process_BodyControlMAIN = xTaskCreateStatic
										(
										Process_BodyControlMAIN_TaskHandler,
										PROCESS_BODYCONTROLMAIN_THREADNAME,
										PROCESS_BODYCONTROLMAIN_STACKSIZE,
										(void *)1,
										PROCESS_BODYCONTROLMAIN_PRIORITY,
										xStack.Process_BodyControlMAIN,
										&xTaskBuffer.Process_BodyControlMAIN
										);
#endif


#ifdef BSP_PROCESS_ADC
	xHandle.Process_ADC = xTaskCreateStatic
										(
										Process_ADC_TaskHandler,
										PROCESS_ADC_THREADNAME,
										PROCESS_ADC_STACKSIZE,
										(void *)1,
										PROCESS_ADC_PRIORITY,
										xStack.Process_ADC,
										&xTaskBuffer.Process_ADC
										);
#endif

#ifdef BSP_PROCESS_AUDIO
	xHandle.Process_AUDIO = xTaskCreateStatic
										(
										Process_AUDIO_TaskHandler,
										PROCESS_AUDIO_THREADNAME,
										PROCESS_AUDIO_STACKSIZE,
										(void *)1,
										PROCESS_AUDIO_PRIORITY,
										xStack.Process_AUDIO,
										&xTaskBuffer.Process_AUDIO
										);
#endif

#ifdef BSP_PROCESS_CAN
	xHandle.Process_CAN = xTaskCreateStatic
										(
										Process_CAN_TaskHandler,
										PROCESS_CAN_THREADNAME,
										PROCESS_CAN_STACKSIZE,
										(void *)1,
										PROCESS_CAN_PRIORITY,
										xStack.Process_CAN,
										&xTaskBuffer.Process_CAN
										);
#endif

#ifdef BSP_PROCESS_CONTROL
	xHandle.Process_CONTROL = xTaskCreateStatic
										(
										Process_CONTROL_TaskHandler,
										PROCESS_CONTROL_THREADNAME,
										PROCESS_CONTROL_STACKSIZE,
										(void *)1,
										PROCESS_CONTROL_PRIORITY,
										xStack.Process_CONTROL,
										&xTaskBuffer.Process_CONTROL
										);
#endif

#ifdef BSP_PROCESS_FLASH
	xHandle.Process_FLASH = xTaskCreateStatic
										(
										Process_FLASH_TaskHandler,
										PROCESS_FLASH_THREADNAME,
										PROCESS_FLASH_STACKSIZE,
										(void *)1,
										PROCESS_FLASH_PRIORITY,
										xStack.Process_FLASH,
										&xTaskBuffer.Process_FLASH
										);
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	xHandle.Process_POWERSWITCH = xTaskCreateStatic
										(
										Process_POWERSWITCH_TaskHandler,
										PROCESS_POWERSWITCH_THREADNAME,
										PROCESS_POWERSWITCH_STACKSIZE,
										(void *)1,
										PROCESS_POWERSWITCH_PRIORITY,
										xStack.Process_POWERSWITCH,
										&xTaskBuffer.Process_POWERSWITCH
										);
#endif

#ifdef BSP_PROCESS_RTC
	xHandle.Process_RTC = xTaskCreateStatic
										(
										Process_RTC_TaskHandler,
										PROCESS_RTC_THREADNAME,
										PROCESS_RTC_STACKSIZE,
										(void *)1,
										PROCESS_RTC_PRIORITY,
										xStack.Process_RTC,
										&xTaskBuffer.Process_RTC
										);
#endif

#ifdef BSP_PROCESS_SDCARD
	xHandle.Process_SDCARD = xTaskCreateStatic
										(
										Process_SDCARD_TaskHandler,
										PROCESS_SDCARD_THREADNAME,
										PROCESS_SDCARD_STACKSIZE,
										(void *)1,
										PROCESS_SDCARD_PRIORITY,
										xStack.Process_SDCARD,
										&xTaskBuffer.Process_SDCARD
										);
#endif

#ifdef BSP_PROCESS_TELEMETRY
	xHandle.Process_TELEMETRY = xTaskCreateStatic
										(
										Process_TELEMETRY_TaskHandler,
										PROCESS_TELEMETRY_THREADNAME,
										PROCESS_TELEMETRY_STACKSIZE,
										(void *)1,
										PROCESS_TELEMETRY_PRIORITY,
										xStack.Process_TELEMETRY,
										&xTaskBuffer.Process_TELEMETRY
										);
#endif


/********************* Binary Semaphore Create **********************/

#ifdef BSP_PROCESS_ADC
	xSemHandle.Process_ADC 			= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_ADC);
#endif

#ifdef BSP_PROCESS_AUDIO
	xSemHandle.Process_AUDIO 		= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_AUDIO);
#endif

#ifdef BSP_PROCESS_CAN
	xSemHandle.Process_CAN 			= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_CAN);
#endif

#ifdef BSP_PROCESS_CONTROL
	xSemHandle.Process_CONTROL 		= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_CONTROL);
#endif

#ifdef BSP_PROCESS_FLASH
	xSemHandle.Process_FLASH 		= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_FLASH);
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	xSemHandle.Process_POWERSWITCH 	= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_POWERSWITCH);
#endif

#ifdef BSP_PROCESS_RTC
	xSemHandle.Process_RTC 			= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_RTC);
#endif

#ifdef BSP_PROCESS_SDCARD
	xSemHandle.Process_SDCARD 		= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_SDCARD);
#endif

#ifdef BSP_PROCESS_TELEMETRY
	xSemHandle.Process_TELEMETRY 	= xSemaphoreCreateBinaryStatic(&xSemaphore.Process_TELEMETRY);
#endif


	/************************ Create  Software Timers ***********************************/

    xTimerID.periodic = 	osTimerNew( APP_periodicTimerIRQHandler			,
    									osTimerPeriodic						,
										NULL								,
										&APP_periodic_attributes			);

    xTimerID.timeout  = 	osTimerNew( APP_timeoutTimerIRQHandler			,
    									osTimerOnce							,
										NULL								,
										&APP_timeout_attributes				);

    /* Create Broadcast Timers */

    xTimerID.broadcast01 = 	osTimerNew( APP_broadcast01TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast01_attributes			);

    xTimerID.broadcast02 = 	osTimerNew( APP_broadcast02TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast02_attributes			);

    xTimerID.broadcast03 = 	osTimerNew( APP_broadcast03TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast03_attributes			);

    xTimerID.broadcast04 = 	osTimerNew( APP_broadcast04TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast04_attributes			);

    xTimerID.broadcast05 = 	osTimerNew( APP_broadcast05TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast05_attributes			);

    xTimerID.broadcast06 = 	osTimerNew( APP_broadcast06TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast06_attributes			);

    xTimerID.broadcast07 = 	osTimerNew( APP_broadcast07TimerIRQHandler		,
    									osTimerPeriodic						,
										NULL								,
										&APP_broadcast07_attributes			);

//    xTimerID.broadcast08 = 	osTimerNew( APP_broadcast08TimerIRQHandler			,
//    									osTimerPeriodic						,
//										NULL								,
//										&APP_broadcast08_attributes			);

    /*
    * 10ms Periodic Timer Start
    */
    osTimerStart(xTimerID.periodic, pdMS_TO_TICKS(10));

    /* Broadcast periodic sw timer start */

    /*
     * Broadcast01 - Start for Message 03
     */
    osTimerStart(xTimerID.broadcast01 , pdMS_TO_TICKS(100));

    /*
    * Broadcast02 - Start for Message 04
    */
    osTimerStart(xTimerID.broadcast02 , pdMS_TO_TICKS(200));

    /*
    * Broadcast03 - Start for Message 05
    */
    osTimerStart(xTimerID.broadcast03 , pdMS_TO_TICKS(300));

    /*
     * Broadcast04 - Start for Message 11
     */
    osTimerStart(xTimerID.broadcast01 , pdMS_TO_TICKS(400));

    /*
    * Broadcast05 - Start for Message 12
    */
    osTimerStart(xTimerID.broadcast05 , pdMS_TO_TICKS(500));

    /*
    * Broadcast06 - Start for Message 19
    */
    osTimerStart(xTimerID.broadcast06 , pdMS_TO_TICKS(600));

    /*
    * Broadcast07 - Start for Message 20
    */
    osTimerStart(xTimerID.broadcast07 , pdMS_TO_TICKS(100));
    vTaskDelay(pdMS_TO_TICKS(10));

//    /*
//    * Broadcast08 - Not Used Yet !
//    */
//    osTimerStart(xTimerID.broadcast01 , pdMS_TO_TICKS(100));
//    HAL_Delay(10); /* 10ms delay for sequance */
//

#ifdef DEBUG_MODE
    HAL_UART_Receive_DMA(&huart1, (U8 *)&__GL.DEBUG_Buffer[0], (U8)DEBUG_MSG_SIZE);
#endif

}




/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void MAIN_App(void)
{
	/* Create Threads, Semph, SW Timers */
    Initilialise_App();
    /* Start Scheduler */
    vTaskStartScheduler();

}








#if 1 /* MAIN - Thread Definition */
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void Process_BodyControlMAIN_TaskHandler(void* param)
{

	BodyControlMAIN_StartUP();

	while(1)
	{

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_BODYCONTROLMAIN_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        BodyControlMAIN(); /* Main Application */

//        vTaskDelay( pdMS_TO_TICKS(10) );

//        Process_AUDIO_Run();
//        Process_CONTROL_Run();
//        Process_FLASH_Run();
//        Process_POWERSWITCH_Run();
//        Process_RTC_Run();
//        Process_SDCARD_Run();
//        Process_TELEMETRY_Run();

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_BODYCONTROLMAIN_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
	}

}

#endif


#if 1 /* Module - Threads Definitions */

#ifdef BSP_PROCESS_ADC
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_ADC_TaskHandler(void *params)
{
	ModuleADC_StartUP();


 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_ADC = xQueueSemaphoreTake(xSemHandle.Process_ADC, osWaitForever);
	if (pdTRUE == xSemResult.Process_ADC)
	{

		/* Semph has taken */
		__GL.itc.flag.adc = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_ADC_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleADC_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_ADC_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_ADC = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_ADC);
	}

  }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_ADC_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_ADC_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_ADC = xSemaphoreGive(xSemHandle.Process_ADC);

    if (pdPASS == xSemResult.Process_ADC)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.adc = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.adc = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_ADC_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_ADC = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_ADC);
    }
}
#endif

#ifdef BSP_PROCESS_AUDIO
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_AUDIO_TaskHandler(void *params)
{
	ModuleAUDIO_StartUP();

 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_AUDIO = xQueueSemaphoreTake(xSemHandle.Process_AUDIO, osWaitForever);
	if (pdTRUE == xSemResult.Process_AUDIO)
	{

		/* Semph has taken */
		__GL.itc.flag.audio = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_AUDIO_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleAUDIO_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_AUDIO_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_AUDIO = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_AUDIO);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_AUDIO_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_AUDIO_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_AUDIO = xSemaphoreGive(xSemHandle.Process_AUDIO);

    if (pdPASS == xSemResult.Process_AUDIO)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.audio = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.audio = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_AUDIO_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_AUDIO = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_AUDIO);
    }
}
#endif

#ifdef BSP_PROCESS_CAN
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_CAN_TaskHandler(void *params)
{
	ModuleCAN_StartUP();


 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_CAN = xQueueSemaphoreTake(xSemHandle.Process_CAN, osWaitForever);
	if (pdTRUE == xSemResult.Process_CAN)
	{

		/* Semph has taken */
		__GL.itc.flag.can = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_CAN_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleCAN_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_CAN_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_CAN = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_CAN);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_CAN_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_CAN_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_CAN = xSemaphoreGive(xSemHandle.Process_CAN);

    if (pdPASS == xSemResult.Process_CAN)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.can = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.can = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_CAN_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_CAN = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_CAN);
    }

}
#endif

#ifdef BSP_PROCESS_CONTROL
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_CONTROL_TaskHandler(void *params)
{
	ModuleCONTROL_StartUP();

 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_CONTROL = xQueueSemaphoreTake(xSemHandle.Process_CONTROL, osWaitForever);
	if (pdTRUE == xSemResult.Process_CONTROL)
	{

		/* Semph has taken */
		__GL.itc.flag.control = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_CONTROL_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleCONTROL_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_CONTROL_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_CONTROL = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_CONTROL);
	}
 }

}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_CONTROL_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_CONTROL_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_CONTROL = xSemaphoreGive(xSemHandle.Process_CONTROL);

    if (pdPASS == xSemResult.Process_CONTROL)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.control = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.control = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_CONTROL_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_CONTROL = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_CONTROL);
    }
}
#endif

#ifdef BSP_PROCESS_FLASH
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_FLASH_TaskHandler(void *params)
{
	ModuleFLASH_StartUP();

 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_FLASH = xQueueSemaphoreTake(xSemHandle.Process_FLASH, osWaitForever);
	if (pdTRUE == xSemResult.Process_FLASH)
	{

		/* Semph has taken */
		__GL.itc.flag.flash = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_FLASH_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleFLASH_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_FLASH_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_FLASH = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_FLASH);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_FLASH_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_RTC_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_FLASH = xSemaphoreGive(xSemHandle.Process_FLASH);

    if (pdPASS == xSemResult.Process_FLASH)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.flash = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.flash = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_RTC_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_FLASH = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_FLASH);
    }
}
#endif

#ifdef BSP_PROCESS_POWERSWITCH
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_POWERSWITCH_TaskHandler(void *params)
{
	ModulePOWERSWITCH_StartUP();
 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_POWERSWITCH = xQueueSemaphoreTake(xSemHandle.Process_POWERSWITCH, osWaitForever);
	if (pdTRUE == xSemResult.Process_FLASH)
	{

		/* Semph has taken */
		__GL.itc.flag.powerswitch = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_POWERSWITCH_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModulePOWERSWITCH_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_POWERSWITCH_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_POWERSWITCH = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_POWERSWITCH);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_POWERSWITCH_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_POWERSWITCH_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_POWERSWITCH = xSemaphoreGive(xSemHandle.Process_POWERSWITCH);

    if (pdPASS == xSemResult.Process_POWERSWITCH)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.powerswitch = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.powerswitch = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_POWERSWITCH_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_POWERSWITCH = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_POWERSWITCH);
    }
}
#endif

#ifdef BSP_PROCESS_RTC
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_RTC_TaskHandler(void *params)
{
	ModuleRTC_StartUP();

 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_RTC = xQueueSemaphoreTake(xSemHandle.Process_RTC, osWaitForever);
	if (pdTRUE == xSemResult.Process_RTC)
	{

		/* Semph has taken */
		__GL.itc.flag.rtc = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_RTC_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleRTC_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_RTC_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_RTC = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_RTC);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_RTC_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_RTC_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_RTC = xSemaphoreGive(xSemHandle.Process_RTC);

    if (pdPASS == xSemResult.Process_RTC)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.rtc = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.rtc = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_RTC_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_RTC = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_RTC);
    }
}
#endif

#ifdef BSP_PROCESS_SDCARD
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_SDCARD_TaskHandler(void *params)
{
	ModuleSDCARD_StartUP();

 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_SDCARD = xQueueSemaphoreTake(xSemHandle.Process_SDCARD, osWaitForever);
	if (pdTRUE == xSemResult.Process_SDCARD)
	{

		/* Semph has taken */
		__GL.itc.flag.sdcard = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_SDCARD_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleSDCARD_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_SDCARD_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */


	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_SDCARD = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_SDCARD);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_SDCARD_Run(void)
{
/* Message first, release later :) */

#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_SDCARD_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_SDCARD = xSemaphoreGive(xSemHandle.Process_SDCARD);

    if (pdPASS == xSemResult.Process_SDCARD)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.sdcard = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.sdcard = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_SDCARD_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_SDCARD = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_SDCARD);
    }
}
#endif

#ifdef BSP_PROCESS_TELEMETRY
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_TELEMETRY_TaskHandler(void *params)
{
	ModuleTELEMETRY_StartUP();

 while (1)
 {
	/* Semaphore Wait */
	xSemResult.Process_TELEMETRY = xQueueSemaphoreTake(xSemHandle.Process_TELEMETRY, osWaitForever);
	if (pdTRUE == xSemResult.Process_TELEMETRY)
	{
		/* Semph has taken */
		__GL.itc.flag.telemetry = FALSE;

		//HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_TELEMETRY_THREADNAME, "STARTED");
#endif
        // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

        ModuleTELEMETRY_MAIN(); /* Main Application */

        // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifdef DEBUG_THREAD
        DEBUG_printThread((char *)PROCESS_TELEMETRY_THREADNAME, "ENDED");
#endif
        //HAL_IWDG_Refresh(&hiwdg);   /*	Watchdog-Clear	 */

	}
	else
	{
		/* Semaphore fail / Create Again                                                             */
		xSemHandle.Process_TELEMETRY = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_TELEMETRY);
	}
 }
}
/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void     		Process_TELEMETRY_Run(void)
{
#ifdef DEBUG_THREAD
    DEBUG_printThread((char *)PROCESS_TELEMETRY_SEMAPHORENAME, "RELEASED");
#endif

    xSemResult.Process_TELEMETRY = xSemaphoreGive(xSemHandle.Process_TELEMETRY);

    if (pdPASS == xSemResult.Process_TELEMETRY)
    {
        /* Bootloader Semaphore is Passed */
    	__GL.itc.flag.telemetry = TRUE;
    }
    else
    {
        /* Bootloader Semaphore is Fail	& Create Again */
    	__GL.itc.flag.telemetry = FALSE;

#ifdef DEBUG_THREAD
   DEBUG_printThread((char *)PROCESS_TELEMETRY_SEMAPHORENAME, "ALREADY RUNNING");
#endif

        xSemHandle.Process_TELEMETRY = xSemaphoreCreateBinaryStatic(&xSemaphore.Process_TELEMETRY);
    }
}
#endif


#endif
