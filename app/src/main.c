/*
	Vinicius Malaman Soares
*/
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include "display/display.h"



int main(void){

	int ret = display_init();
	if (ret < 0) {
		return ret;
	}

	while (1) { 
		lv_timer_handler();//call the lvgl handler to update the screen
		k_sleep(K_MSEC(5));
	}

}