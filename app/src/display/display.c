#include "display.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>

const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

int display_init(void)
{
    if (!device_is_ready(display)) {
    return -ENODEV;//no such device error
    }

display_blanking_off(display);

return 0;

}


