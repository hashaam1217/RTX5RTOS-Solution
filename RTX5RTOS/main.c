#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"

void app_main(void *);

int __attribute__((noreturn)) main (void) {
    SystemCoreClockUpdate();                    // initialize clocks etc

	osKernelInitialize();                       // initialize RTOS

	osThreadNew(app_main, NULL, NULL);          // Create application main thread

	if (osKernelGetState() == osKernelReady)    // If all OK...
		osKernelStart();                        // Start thread execution

	while(1);                                   // If you get to here, something has gone wrong!
}