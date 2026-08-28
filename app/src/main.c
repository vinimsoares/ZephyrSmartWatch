/*
	Vinicius Malaman Soares
*/
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include "display/display.h"
#include "touch/touch.h"



int main(void){


	int ret = display_init();
	if (ret < 0) {
		printk("display_init failed: %d\n", ret);
		return ret;
	}

	ret = touch_init();
    if (ret < 0) {
        printk("touch_init failed: %d\n", ret);
        return ret;
    }


	while (1) { 
		lv_timer_handler();//call the lvgl handler to update the screen
		k_sleep(K_MSEC(5));
	}

}