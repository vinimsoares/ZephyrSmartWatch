#include "screen_clock.h"
#include <stdio.h>
#include <math.h>

#define SCREEN_CENTER_X 120
#define SCREEN_CENTER_Y 120
#define NUMBER_RADIUS   95

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static void create_clock_numbers(lv_obj_t *parent)
{
    for (int i = 1; i <= 12; i++) {
        double angle_deg = (i * 30) - 90;
        double angle_rad = angle_deg * (M_PI / 180.0);

        int x = SCREEN_CENTER_X + (int)(NUMBER_RADIUS * cos(angle_rad));
        int y = SCREEN_CENTER_Y + (int)(NUMBER_RADIUS * sin(angle_rad));

        lv_obj_t *label = lv_label_create(parent);
        char buf[3];
        snprintf(buf, sizeof(buf), "%d", i);
        lv_label_set_text(label, buf);

        lv_obj_align(label, LV_ALIGN_TOP_LEFT, x, y);
    }
}

lv_obj_t *screen_clock_create(void)
{
    lv_obj_t *scr = lv_obj_create(NULL);

    create_clock_numbers(scr);

    return scr;
}
