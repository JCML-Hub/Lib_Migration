/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_obj_t * kb;
static void kb_event_cb(lv_obj_t * event_kb, lv_event_t event)
{
	/* Just call the regular event handler */
	lv_keyboard_def_event_cb(event_kb, event);
	if(event == LV_EVENT_APPLY || event == LV_EVENT_CANCEL){
		if(NULL != kb){
			lv_obj_del(kb);
		}
	}
}
static void text_area_event_cb(lv_obj_t* ta, lv_event_t event)
{

	if(event == LV_EVENT_CLICKED){
		 if( !lv_debug_check_obj_valid(kb) ){
			/* Create a keyboard and make it fill the width of the above text areas */
			kb = lv_keyboard_create(lv_scr_act(), NULL);
			lv_obj_set_event_cb(kb, kb_event_cb);
			lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);
		}
		lv_keyboard_set_textarea(kb, ta);
		lv_keyboard_set_cursor_manage(kb, true); 
	}
}

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write style LV_OBJ_PART_MAIN for screen
	static lv_style_t style_screen_main;
	lv_style_reset(&style_screen_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_main
	lv_style_set_bg_color(&style_screen_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen, LV_OBJ_PART_MAIN, &style_screen_main);

	//Write codes screen_calendar_1
	ui->screen_calendar_1 = lv_calendar_create(ui->screen, NULL);

	//Write style LV_CALENDAR_PART_BG for screen_calendar_1
	static lv_style_t style_screen_calendar_1_bg;
	lv_style_reset(&style_screen_calendar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_1_bg
	lv_style_set_bg_color(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_width(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_shadow_opa(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_spread(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_shadow_ofs_x(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_shadow_ofs_y(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_screen_calendar_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_calendar_1, LV_CALENDAR_PART_BG, &style_screen_calendar_1_bg);

	//Write style LV_CALENDAR_PART_HEADER for screen_calendar_1
	static lv_style_t style_screen_calendar_1_header;
	lv_style_reset(&style_screen_calendar_1_header);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_1_header
	lv_style_set_text_color(&style_screen_calendar_1_header, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_1_header, LV_STATE_DEFAULT, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_screen_calendar_1_header, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_calendar_1, LV_CALENDAR_PART_HEADER, &style_screen_calendar_1_header);

	//Write style LV_CALENDAR_PART_DAY_NAMES for screen_calendar_1
	static lv_style_t style_screen_calendar_1_day_names;
	lv_style_reset(&style_screen_calendar_1_day_names);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_1_day_names
	lv_style_set_text_color(&style_screen_calendar_1_day_names, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_1_day_names, LV_STATE_DEFAULT, &lv_font_montserratMedium_12);
	lv_obj_add_style(ui->screen_calendar_1, LV_CALENDAR_PART_DAY_NAMES, &style_screen_calendar_1_day_names);

	//Write style LV_CALENDAR_PART_DATE for screen_calendar_1
	static lv_style_t style_screen_calendar_1_date;
	lv_style_reset(&style_screen_calendar_1_date);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_1_date
	lv_style_set_text_color(&style_screen_calendar_1_date, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_1_date, LV_STATE_DEFAULT, &lv_font_montserratMedium_12);

	//Write style state: LV_STATE_FOCUSED for style_screen_calendar_1_date
	lv_style_set_bg_color(&style_screen_calendar_1_date, LV_STATE_FOCUSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_calendar_1_date, LV_STATE_FOCUSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_calendar_1_date, LV_STATE_FOCUSED, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_calendar_1_date, LV_STATE_FOCUSED, 255);
	lv_style_set_text_color(&style_screen_calendar_1_date, LV_STATE_FOCUSED, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_1_date, LV_STATE_FOCUSED, &lv_font_montserratMedium_12);

	//Write style state: LV_STATE_CHECKED for style_screen_calendar_1_date
	lv_style_set_bg_color(&style_screen_calendar_1_date, LV_STATE_CHECKED, lv_color_make(0x04, 0xc2, 0x6b));
	lv_style_set_bg_grad_color(&style_screen_calendar_1_date, LV_STATE_CHECKED, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_calendar_1_date, LV_STATE_CHECKED, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_screen_calendar_1_date, LV_STATE_CHECKED, 255);
	lv_style_set_text_color(&style_screen_calendar_1_date, LV_STATE_CHECKED, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_1_date, LV_STATE_CHECKED, &lv_font_montserratMedium_12);
	lv_obj_add_style(ui->screen_calendar_1, LV_CALENDAR_PART_DATE, &style_screen_calendar_1_date);
	lv_obj_set_pos(ui->screen_calendar_1, 22, 23);
	lv_obj_set_size(ui->screen_calendar_1, 200, 180);
	today.year = 2023;
	today.month = 8;
	today.day = 13;
	lv_calendar_set_today_date(ui->screen_calendar_1, &today);
	lv_calendar_set_showed_date(ui->screen_calendar_1, &today);
	highlihted_days[0].year = 2023;
	highlihted_days[0].month = 8;
	highlihted_days[0].day = 14;
	lv_calendar_set_highlighted_dates(ui->screen_calendar_1, highlihted_days, 1);

	//Write codes screen_calendar_2
	ui->screen_calendar_2 = lv_calendar_create(ui->screen, NULL);

	//Write style LV_CALENDAR_PART_BG for screen_calendar_2
	static lv_style_t style_screen_calendar_2_bg;
	lv_style_reset(&style_screen_calendar_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_2_bg
	lv_style_set_bg_color(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_width(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_shadow_opa(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_spread(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_shadow_ofs_x(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_shadow_ofs_y(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_screen_calendar_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_calendar_2, LV_CALENDAR_PART_BG, &style_screen_calendar_2_bg);

	//Write style LV_CALENDAR_PART_HEADER for screen_calendar_2
	static lv_style_t style_screen_calendar_2_header;
	lv_style_reset(&style_screen_calendar_2_header);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_2_header
	lv_style_set_text_color(&style_screen_calendar_2_header, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_2_header, LV_STATE_DEFAULT, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_screen_calendar_2_header, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_calendar_2, LV_CALENDAR_PART_HEADER, &style_screen_calendar_2_header);

	//Write style LV_CALENDAR_PART_DAY_NAMES for screen_calendar_2
	static lv_style_t style_screen_calendar_2_day_names;
	lv_style_reset(&style_screen_calendar_2_day_names);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_2_day_names
	lv_style_set_text_color(&style_screen_calendar_2_day_names, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_2_day_names, LV_STATE_DEFAULT, &lv_font_montserratMedium_12);
	lv_obj_add_style(ui->screen_calendar_2, LV_CALENDAR_PART_DAY_NAMES, &style_screen_calendar_2_day_names);

	//Write style LV_CALENDAR_PART_DATE for screen_calendar_2
	static lv_style_t style_screen_calendar_2_date;
	lv_style_reset(&style_screen_calendar_2_date);

	//Write style state: LV_STATE_DEFAULT for style_screen_calendar_2_date
	lv_style_set_text_color(&style_screen_calendar_2_date, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_2_date, LV_STATE_DEFAULT, &lv_font_montserratMedium_12);

	//Write style state: LV_STATE_FOCUSED for style_screen_calendar_2_date
	lv_style_set_bg_color(&style_screen_calendar_2_date, LV_STATE_FOCUSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_calendar_2_date, LV_STATE_FOCUSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_calendar_2_date, LV_STATE_FOCUSED, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_calendar_2_date, LV_STATE_FOCUSED, 255);
	lv_style_set_text_color(&style_screen_calendar_2_date, LV_STATE_FOCUSED, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_2_date, LV_STATE_FOCUSED, &lv_font_montserratMedium_12);

	//Write style state: LV_STATE_CHECKED for style_screen_calendar_2_date
	lv_style_set_bg_color(&style_screen_calendar_2_date, LV_STATE_CHECKED, lv_color_make(0x04, 0xc2, 0x6b));
	lv_style_set_bg_grad_color(&style_screen_calendar_2_date, LV_STATE_CHECKED, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_calendar_2_date, LV_STATE_CHECKED, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_screen_calendar_2_date, LV_STATE_CHECKED, 255);
	lv_style_set_text_color(&style_screen_calendar_2_date, LV_STATE_CHECKED, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_calendar_2_date, LV_STATE_CHECKED, &lv_font_montserratMedium_12);
	lv_obj_add_style(ui->screen_calendar_2, LV_CALENDAR_PART_DATE, &style_screen_calendar_2_date);
	lv_obj_set_pos(ui->screen_calendar_2, 22, 212);
	lv_obj_set_size(ui->screen_calendar_2, 200, 180);
	today.year = 2023;
	today.month = 8;
	today.day = 13;
	lv_calendar_set_today_date(ui->screen_calendar_2, &today);
	lv_calendar_set_showed_date(ui->screen_calendar_2, &today);
	highlihted_days[0].year = 2023;
	highlihted_days[0].month = 8;
	highlihted_days[0].day = 14;
	lv_calendar_set_highlighted_dates(ui->screen_calendar_2, highlihted_days, 1);
}