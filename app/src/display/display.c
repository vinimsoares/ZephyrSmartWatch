#include "display.h"
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <math.h>

#define SCREEN_CENTER_X 120
#define SCREEN_CENTER_Y 120
#define NUMBER_RADIUS   95 //magic number to make number fit nicely

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

/**
 * @brief Draws a round clock into the screen
 *
 * @param parent Pointer to the parent LVGL object
 */

static void create_clock_numbers(lv_obj_t *parent)
{
    for (int i = 1; i <= 12; i++) {//need to start at 1 for numbers
        //360/12=30 degrees per n
        double angle_deg = (i * 30) - 90;//-90 to start at top of circle
        double angle_rad = angle_deg * (M_PI / 180.0); //math.h uses radians

        int x = SCREEN_CENTER_X + (int)(NUMBER_RADIUS * cos(angle_rad));
        int y = SCREEN_CENTER_Y + (int)(NUMBER_RADIUS * sin(angle_rad));

        lv_obj_t *label = lv_label_create(parent);
        char buf[3];//buffer to hold number as string
        snprintf(buf, sizeof(buf), "%d", i);//coping i to buf
        lv_label_set_text(label, buf);

        // center the label ON that point, not top-left corner on that point
        lv_obj_align(label, LV_ALIGN_TOP_LEFT, x, y);
    }
}

int display_init(void)
{
    if (!device_is_ready(display)) {
    return -ENODEV;//no such device error
    }
create_clock_numbers(lv_scr_act());//make clock defualt screen when init

display_blanking_off(display);

return 0;

}



