#include "touch.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/input/input.h>

static const struct device *touch_dev = DEVICE_DT_GET(DT_NODELABEL(cst816d));

int touch_init(void)
{
    if (!device_is_ready(touch_dev)) {
        return -ENODEV;
    }


    return 0;
}