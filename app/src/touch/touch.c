#include "touch.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/input/input.h>

static const struct device *touch_dev = DEVICE_DT_GET(DT_NODELABEL(cst816d));

static void touch_event_handler(struct input_event *evt, void *user_data)
{
    switch (evt->code) {
        case INPUT_ABS_X:
            printk("Touch X: %d\n", evt->value);
            break;
        case INPUT_ABS_Y:
            printk("Touch Y: %d\n", evt->value);
            break;
        case INPUT_BTN_TOUCH:
            printk("Touch %s\n", evt->value ? "pressed" : "released");
            break;
	}
}

INPUT_CALLBACK_DEFINE(DEVICE_DT_GET(DT_NODELABEL(cst816d)), touch_event_handler, NULL);

int touch_init(void)
{
    if (!device_is_ready(touch_dev)) {
        return -ENODEV;
    }


    return 0;
}