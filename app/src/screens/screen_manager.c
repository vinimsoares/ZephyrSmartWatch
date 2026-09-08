#include "screen_manager.h"
#include "screen_clock.h"
#include "screen_stepcount.h"
#include <lvgl.h>
#include <zephyr/sys/util.h>

#define SCREEN_ANIM_TIME_MS 200

static lv_obj_t *screens[2];
static size_t screen_count;
static size_t current_screen;

static void goto_screen(size_t index, lv_screen_load_anim_t anim)
{
    current_screen = index;//make sure to update the current screen variable so it can me updated in the callback
    lv_screen_load_anim(screens[current_screen], anim, SCREEN_ANIM_TIME_MS, 0, false);
}

static void gesture_event_cb(lv_event_t *e)//
{
    lv_indev_t *indev = lv_event_get_param(e);//indev is input device
    lv_dir_t dir = lv_indev_get_gesture_dir(indev);

    if (dir == LV_DIR_LEFT) {
        goto_screen((current_screen + 1) % screen_count, LV_SCREEN_LOAD_ANIM_MOVE_LEFT);
    } else if (dir == LV_DIR_RIGHT) {
        goto_screen((current_screen + screen_count - 1) % screen_count, LV_SCREEN_LOAD_ANIM_MOVE_RIGHT);//+screen_count - 1 makes sure it never goes below 0
    }
}

void screen_manager_init(void)
{
    screens[0] = screen_clock_create();
    screens[1] = screen_stepcount_create();
    screen_count = 2;

    for (size_t i = 0; i < screen_count; i++) {//got to go through each screen bc each is an lv obj
        lv_obj_remove_flag(screens[i], LV_OBJ_FLAG_SCROLLABLE);//make sure it doesn not count as scroll
        lv_obj_add_event_cb(screens[i], gesture_event_cb, LV_EVENT_GESTURE, NULL);//adding the gesture event to the lv callback
    }

    current_screen = 0;
    lv_screen_load(screens[current_screen]);
}
