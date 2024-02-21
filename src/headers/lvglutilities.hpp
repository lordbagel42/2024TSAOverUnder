#ifndef LVGLUTILITIES_HPP
#define LVGLUTILITIES_HPP
#include "pros/apix.h"

lv_obj_t *createBtn(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int id, const char *title);
void setBtnStyle(lv_style_t * btnStyle, lv_obj_t * btn);
void btnSetToggled(lv_obj_t * btn, bool toggled);
lv_obj_t *createLabel(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int id, const char *title);

#endif // LVGLUTILITIES_HPP
