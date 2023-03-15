#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "main.h"
#include "types.h"

/*----------------------------------------------------------------------------*/
/* Miscellaneous definitions                                                  */
/*----------------------------------------------------------------------------*/

/* Enable - Disable Modules */
#define		BSP_PROCESS_BODYCONTROLMAIN

#define		BSP_PROCESS_ADC
#define     BSP_PROCESS_AUDIO
#define     BSP_PROCESS_CAN
#define     BSP_PROCESS_CONTROL
#define     BSP_PROCESS_FLASH
#define     BSP_PROCESS_POWERSWITCH
#define     BSP_PROCESS_RTC
#define     BSP_PROCESS_SDCARD
#define     BSP_PROCESS_TELEMETRY

#define		DEBUG_THREAD

/* Process Task Name definitions */
#define	PROCESS_BODYCONTROLMAIN_THREADNAME		"ProcessBCMMAINThread"

#define PROCESS_ADC_THREADNAME                	"ProcessADCThread"
#define PROCESS_AUDIO_THREADNAME                "ProcessAUDIOThread"
#define PROCESS_CAN_THREADNAME                  "ProcessCANThread"
#define PROCESS_CONTROL_THREADNAME              "ProcessCONTROLThread"
#define PROCESS_FLASH_THREADNAME                "ProcessFLASHThread"
#define PROCESS_POWERSWITCH_THREADNAME          "ProcessPSThread"
#define PROCESS_RTC_THREADNAME                  "ProcessRTCThread"
#define PROCESS_SDCARD_THREADNAME               "ProcessSDCARDThread"
#define PROCESS_TELEMETRY_THREADNAME            "ProcessTLMThread"


/* Process Semphore Name definitions */
#define PROCESS_ADC_SEMAPHORENAME               "ProcessADCSemaphore"
#define PROCESS_AUDIO_SEMAPHORENAME             "ProcessAUDIOSemaphore"
#define PROCESS_CAN_SEMAPHORENAME               "ProcessCANSemaphore"
#define PROCESS_CONTROL_SEMAPHORENAME           "ProcessCONTROLSemaphore"
#define PROCESS_FLASH_SEMAPHORENAME             "ProcessFLASHSemaphore"
#define PROCESS_POWERSWITCH_SEMAPHORENAME       "ProcessPSSemaphore"
#define PROCESS_RTC_SEMAPHORENAME               "ProcessRTCSemaphore"
#define PROCESS_SDCARD_SEMAPHORENAME            "ProcessSDCARDSemaphore"
#define PROCESS_TELEMETRY_SEMAPHORENAME         "ProcessTLMSemaphore"


/* Process SW Timer Name definitions */
#define	PROCESS_PERIODIC_SWTIMERNAME			"ProcessPeriodicSWTIM"
#define	PROCESS_TIMEOUT_SWTIMERNAME				"ProcessTimeoutSWTIM"
/* BroadCast Timer Name definitions */
#define	PROCESS_BROADCAST01_SWTIMERNAME			"ProcessBroadcast01TIM"
#define	PROCESS_BROADCAST02_SWTIMERNAME			"ProcessBroadcast02TIM"
#define	PROCESS_BROADCAST03_SWTIMERNAME         "ProcessBroadcast03TIM"
#define	PROCESS_BROADCAST04_SWTIMERNAME         "ProcessBroadcast04TIM"
#define	PROCESS_BROADCAST05_SWTIMERNAME         "ProcessBroadcast05TIM"
#define	PROCESS_BROADCAST06_SWTIMERNAME         "ProcessBroadcast06TIM"
#define	PROCESS_BROADCAST07_SWTIMERNAME         "ProcessBroadcast07TIM"
#define	PROCESS_BROADCAST08_SWTIMERNAME         "ProcessBroadcast08TIM"

/* Software Default Timer Periods */

/* Process Task Stack Size definitions */

#define	PROCESS_BODYCONTROLMAIN_STACKSIZE	1024

#define PROCESS_ADC_STACKSIZE      			512
#define PROCESS_AUDIO_STACKSIZE             512
#define PROCESS_CAN_STACKSIZE               512
#define PROCESS_CONTROL_STACKSIZE           512
#define PROCESS_FLASH_STACKSIZE             512
#define PROCESS_POWERSWITCH_STACKSIZE       512
#define PROCESS_RTC_STACKSIZE               512
#define PROCESS_SDCARD_STACKSIZE            512
#define PROCESS_TELEMETRY_STACKSIZE         512


/* Process Task Stack Size Priority definitions  */

#define PROCESS_BODYCONTROLMAIN_PRIORITY      	0x01

#define PROCESS_ADC_PRIORITY              		0x06
#define PROCESS_AUDIO_PRIORITY            		0x0A
#define PROCESS_CAN_PRIORITY              		0x05
#define PROCESS_CONTROL_PRIORITY      			0x04
#define PROCESS_FLASH_PRIORITY            		0x02
#define PROCESS_POWERSWITCH_PRIORITY      		0x07
#define PROCESS_RTC_PRIORITY              		0x03
#define PROCESS_SDCARD_PRIORITY           		0x09
#define PROCESS_TELEMETRY_PRIORITY        		0x08

/*----------------------------------------------------------------------------*/
/* Functions used outside this module                                         */
/*----------------------------------------------------------------------------*/
void            MAIN_App(void);

void            DEBUG_printThread(char *threadName,
                                  char *threadStatus);

/*----------------------------------------------------------------------------*/
/* Functions used only by this module                                         */
/*----------------------------------------------------------------------------*/
void     		Initilialise_App(void);

/* Main Thread */
#ifdef BSP_PROCESS_BODYCONTROLMAIN
void     		Process_BodyControlMAIN_TaskHandler(void *params);
#endif

/* Depends Semph Release */

#ifdef BSP_PROCESS_ADC
void     		Process_ADC_TaskHandler(void *params);
extern void     Process_ADC_Run(void);
#endif

#ifdef BSP_PROCESS_AUDIO
void     		Process_AUDIO_TaskHandler(void *params);
extern void     Process_AUDIO_Run(void);
#endif

#ifdef BSP_PROCESS_CAN
void     		Process_CAN_TaskHandler(void *params);
extern void     Process_CAN_Run(void);
#endif

#ifdef BSP_PROCESS_CONTROL
void     		Process_CONTROL_TaskHandler(void *params);
extern void     Process_CONTROL_Run(void);
#endif

#ifdef BSP_PROCESS_FLASH
void     		Process_FLASH_TaskHandler(void *params);
extern void     Process_FLASH_Run(void);
#endif

#ifdef BSP_PROCESS_POWERSWITCH
void     		Process_POWERSWITCH_TaskHandler(void *params);
extern void     Process_POWERSWITCH_Run(void);
#endif

#ifdef BSP_PROCESS_RTC
void     		Process_RTC_TaskHandler(void *params);
extern void     Process_RTC_Run(void);
#endif

#ifdef BSP_PROCESS_SDCARD
void     		Process_SDCARD_TaskHandler(void *params);
extern void     Process_SDCARD_Run(void);
#endif

#ifdef BSP_PROCESS_TELEMETRY
void     		Process_TELEMETRY_TaskHandler(void *params);
extern void     Process_TELEMETRY_Run(void);
#endif


/*----------------------------------------------------------------------------*/
/* Variables used only by this module                                         */
/*----------------------------------------------------------------------------*/

/* Structure that will hold the TCB of the task being created.                */
typedef struct {

#ifdef BSP_PROCESS_BODYCONTROLMAIN
	StaticTask_t Process_BodyControlMAIN;
#endif

#ifdef BSP_PROCESS_ADC
	StaticTask_t Process_ADC;
#endif

#ifdef BSP_PROCESS_AUDIO
	StaticTask_t Process_AUDIO;
#endif

#ifdef BSP_PROCESS_CAN
	StaticTask_t Process_CAN;
#endif

#ifdef BSP_PROCESS_CONTROL
	StaticTask_t Process_CONTROL;
#endif

#ifdef BSP_PROCESS_FLASH
	StaticTask_t Process_FLASH;
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	StaticTask_t Process_POWERSWITCH;
#endif

#ifdef BSP_PROCESS_RTC
	StaticTask_t Process_RTC;
#endif

#ifdef BSP_PROCESS_SDCARD
	StaticTask_t Process_SDCARD;
#endif

#ifdef BSP_PROCESS_TELEMETRY
	StaticTask_t Process_TELEMETRY;
#endif

}APP_StaticTask_TYPE;


typedef struct {

#ifdef BSP_PROCESS_BODYCONTROLMAIN
	StackType_t Process_BodyControlMAIN	[ PROCESS_BODYCONTROLMAIN_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_ADC
	StackType_t Process_ADC				[ PROCESS_ADC_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_AUDIO
	StackType_t Process_AUDIO			[ PROCESS_AUDIO_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_CAN
	StackType_t Process_CAN				[ PROCESS_CAN_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_CONTROL
	StackType_t Process_CONTROL			[ PROCESS_CONTROL_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_FLASH
	StackType_t Process_FLASH			[ PROCESS_FLASH_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	StackType_t Process_POWERSWITCH		[ PROCESS_POWERSWITCH_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_RTC
	StackType_t Process_RTC				[ PROCESS_RTC_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_SDCARD
	StackType_t Process_SDCARD			[ PROCESS_SDCARD_STACKSIZE ];
#endif

#ifdef BSP_PROCESS_TELEMETRY
	StackType_t Process_TELEMETRY		[ PROCESS_TELEMETRY_STACKSIZE ];
#endif
}APP_StackType_TYPE;


typedef struct {

#ifdef BSP_PROCESS_BODYCONTROLMAIN
	TaskHandle_t Process_BodyControlMAIN;
#endif

#ifdef BSP_PROCESS_ADC
	TaskHandle_t Process_ADC;
#endif

#ifdef BSP_PROCESS_AUDIO
	TaskHandle_t Process_AUDIO;
#endif

#ifdef BSP_PROCESS_CAN
	TaskHandle_t Process_CAN;
#endif

#ifdef BSP_PROCESS_CONTROL
	TaskHandle_t Process_CONTROL;
#endif

#ifdef BSP_PROCESS_FLASH
	TaskHandle_t Process_FLASH;
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	TaskHandle_t Process_POWERSWITCH;
#endif

#ifdef BSP_PROCESS_RTC
	TaskHandle_t Process_RTC;
#endif

#ifdef BSP_PROCESS_SDCARD
	TaskHandle_t Process_SDCARD;
#endif

#ifdef BSP_PROCESS_TELEMETRY
	TaskHandle_t Process_TELEMETRY;
#endif

}APP_TaskHandle_TYPE;


/* Semaphore definitions							 */
typedef struct {

#ifdef BSP_PROCESS_ADC
	StaticSemaphore_t Process_ADC;
#endif

#ifdef BSP_PROCESS_AUDIO
	StaticSemaphore_t Process_AUDIO;
#endif

#ifdef BSP_PROCESS_CAN
	StaticSemaphore_t Process_CAN;
#endif

#ifdef BSP_PROCESS_CONTROL
	StaticSemaphore_t Process_CONTROL;
#endif

#ifdef BSP_PROCESS_FLASH
	StaticSemaphore_t Process_FLASH;
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	StaticSemaphore_t Process_POWERSWITCH;
#endif

#ifdef BSP_PROCESS_RTC
	StaticSemaphore_t Process_RTC;
#endif

#ifdef BSP_PROCESS_SDCARD
	StaticSemaphore_t Process_SDCARD;
#endif

#ifdef BSP_PROCESS_TELEMETRY
	StaticSemaphore_t Process_TELEMETRY;
#endif

}APP_StaticSemaphore_TYPE;

typedef struct { /* Same as QueueHandle_t */

#ifdef BSP_PROCESS_ADC
	QueueHandle_t Process_ADC;
#endif

#ifdef BSP_PROCESS_AUDIO
	QueueHandle_t Process_AUDIO;
#endif

#ifdef BSP_PROCESS_CAN
	QueueHandle_t Process_CAN;
#endif

#ifdef BSP_PROCESS_CONTROL
	QueueHandle_t Process_CONTROL;
#endif

#ifdef BSP_PROCESS_FLASH
	QueueHandle_t Process_FLASH;
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	QueueHandle_t Process_POWERSWITCH;
#endif

#ifdef BSP_PROCESS_RTC
	QueueHandle_t Process_RTC;
#endif

#ifdef BSP_PROCESS_SDCARD
	QueueHandle_t Process_SDCARD;
#endif

#ifdef BSP_PROCESS_TELEMETRY
	QueueHandle_t Process_TELEMETRY;
#endif

}APP_SemaphoreHandle_TYPE;

typedef struct {

#ifdef BSP_PROCESS_ADC
	BaseType_t Process_ADC;
#endif

#ifdef BSP_PROCESS_AUDIO
	BaseType_t Process_AUDIO;
#endif

#ifdef BSP_PROCESS_CAN
	BaseType_t Process_CAN;
#endif

#ifdef BSP_PROCESS_CONTROL
	BaseType_t Process_CONTROL;
#endif

#ifdef BSP_PROCESS_FLASH
	BaseType_t Process_FLASH;
#endif

#ifdef BSP_PROCESS_POWERSWITCH
	BaseType_t Process_POWERSWITCH;
#endif

#ifdef BSP_PROCESS_RTC
	BaseType_t Process_RTC;
#endif

#ifdef BSP_PROCESS_SDCARD
	BaseType_t Process_SDCARD;
#endif

#ifdef BSP_PROCESS_TELEMETRY
	BaseType_t Process_TELEMETRY;
#endif

}APP_SemaphoreResult_TYPE;

/* Timer Structures */

typedef struct
{
	StaticTimer_t	periodic;
	StaticTimer_t 	timeout;
	/**************************/
	StaticTimer_t	broadcast01;
	StaticTimer_t	broadcast02;
	StaticTimer_t	broadcast03;
	StaticTimer_t	broadcast04;
	StaticTimer_t	broadcast05;
	StaticTimer_t	broadcast06;
	StaticTimer_t	broadcast07;
	StaticTimer_t	broadcast08;

}APP_StaticTimer_TYPE;

/* Timer Handle */

typedef struct
{
	osTimerId_t	periodic;
	osTimerId_t timeout;
	/**************************/
	osTimerId_t	broadcast01;
	osTimerId_t	broadcast02;
	osTimerId_t	broadcast03;
	osTimerId_t	broadcast04;
	osTimerId_t	broadcast05;
	osTimerId_t	broadcast06;
	osTimerId_t	broadcast07;
	osTimerId_t	broadcast08;

}APP_TimerID_TYPE;

/* Timer Default */

typedef struct
{
	StaticTimer_t	periodic;
	StaticTimer_t	timeout;
	/**************************/
	StaticTimer_t	broadcast01;
	StaticTimer_t	broadcast02;
	StaticTimer_t	broadcast03;
	StaticTimer_t	broadcast04;
	StaticTimer_t	broadcast05;
	StaticTimer_t	broadcast06;
	StaticTimer_t	broadcast07;
	StaticTimer_t	broadcast08;


}APP_StaticTimerDef_TYPE;


#endif /* APPLICATION_H_ */




