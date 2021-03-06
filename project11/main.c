#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <compat/deprecated.h>
#include <stdlib.h>
#include "task.h"
#include "uart.h"
#include "app.h"
#include "list.h"

#include "timer.h"
#include "led.h"

int main()
{
	int tag;
	struct task task;
	led_init();
	uart_init();
	task_init();
	timer_init();

	while(1){
		cli();
		tag = task_delete(&task);
		sei();
		if(tag){
			((*task.fun))(task.arg);
			printf("$ ");
		}
	}
}
