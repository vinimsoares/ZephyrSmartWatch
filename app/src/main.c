/*
	Vinicius Malaman Soares
*/
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>

const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
int main(void){
if (!device_is_ready(display)) {
    return 0;
}

lv_obj_t *label = lv_label_create(lv_scr_act());//create a label pointer and set it to the active screen
lv_label_set_text(label, "Hello, World!");
lv_obj_center(label);

display_blanking_off(display);
	while (1) { //this will keep the message on the screen until the device is turned off
		lv_timer_handler();//call the lvgl handler to update the screen
		k_sleep(K_MSEC(5));

	}

}