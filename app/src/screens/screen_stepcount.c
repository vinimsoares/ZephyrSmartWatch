#include "screen_stepcount.h"

lv_obj_t *screen_stepcount_create(void)
{
    lv_obj_t *scr = lv_obj_create(NULL);

    lv_obj_t *label = lv_label_create(scr);
    lv_label_set_text(label, "Step Count");
    lv_obj_center(label);

    return scr;
}
