/*
	Vinicius Malaman Soares
*/
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>

const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
int main(void){

if (!device_is_ready(display)) {
    return 0;
}

display_blanking_off(display);
}