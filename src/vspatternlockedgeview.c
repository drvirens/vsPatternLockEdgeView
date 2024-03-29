
#if defined __TIZEN__

#include <tizen.h>
#include "vspatternlockedgeview.h"
#include "BOLockWindowWrapper.h"
#include "trace.hpp"
#include "tests.hpp"

typedef struct appdata {
	Evas_Object *win;
	Evas_Object *conform;
	Evas_Object *bg;
} appdata_s;

static void win_delete_request_cb(void *data, Evas_Object *obj, void *event_info) {
	ui_app_exit();
}

static void win_back_cb(void *data, Evas_Object *obj, void *event_info) {
	appdata_s *ad = data;
	/* Let window go to hide state. */
	elm_win_lower(ad->win);
}

static void create_base_gui(appdata_s *ad)
{
	/* Window */
//	ad->win = elm_win_util_standard_add(PACKAGE, PACKAGE);
//	elm_win_autodel_set(ad->win, EINA_TRUE);

  ad->win = wrapper_CreateLockWindow();

//	if (elm_win_wm_rotation_supported_get(ad->win)) {
//		int rots[4] = { 0, 90, 180, 270 };
//		elm_win_wm_rotation_available_rotations_set(ad->win, (const int *)(&rots), 4);
//	}

	evas_object_smart_callback_add(ad->win, "delete,request", win_delete_request_cb, NULL);
	eext_object_event_callback_add(ad->win, EEXT_CALLBACK_BACK, win_back_cb, ad);

//
//	//window-background+
//	ad->bg = elm_bg_add(ad->win);
//	  evas_object_size_hint_weight_set(ad->bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
//	  elm_win_resize_object_add(ad->win, ad->bg);
//	  //elm_bg_color_set(ad->bg, 0x00, 0xff, 0x00);
//	  elm_bg_color_set(ad->bg, 0x00, 0x00, 0x00);
//	  evas_object_show(ad->bg);
//	  //window-background-



	Evas_Object* window = ad->win;

#if !defined __RUN_ALL_TIZEN_TESTS__

	{
	Evas_Object* target = NULL;
  
//  target = testThinEdgeView_Vertical(window); //nothing except table background should be displayed
//  target = testThickEdgeView_Vertical(window);
//  target = testThickEdgeView_Horizontal(window);
//  target = testThickEdgeView_ForwardSlashed(window); // /
//  target = testThickEdgeView_BackwardSlashed(window); // \
//
  
	target = testPatterLockVCShowAll_PassiveState(window);
//	target = testPatterLockVCShowAll_ActiveState(window);
//	target = testPatterLockVCShowAll_ActiveState_WithTimer(window);
//	target = testPatterLockVCShowAll_ActiveState_WithTimer_DecorateError(window);
//	target = testPatterLockVCShowAll_ActiveState_WithTimer_DecorateOkay(window);


	BO_ASSERT(target != NULL);

//  evas_object_move(target, 50, 200);
//  evas_object_resize(target, 200, 200);

//	elm_win_resize_object_add(window, target);

  int x = 0, y = 0, w = 0, h = 0;
  elm_win_screen_size_get(window, &x, &y, &w, &h);
  evas_object_move(target, 0, 100);
  evas_object_resize(target, w, w);

  evas_object_show(target);
	evas_object_show(window);
	}
#else
	runAllTizenTests(window);
#endif

}

static bool app_create(void *data) {
	appdata_s *ad = data;
	create_base_gui(ad);
	return true;
}

static void app_control(app_control_h app_control, void *data) {
	/* Handle the launch request. */
}

static void
app_pause(void *data)
{
	/* Take necessary actions when application becomes invisible. */
}

static void
app_resume(void *data)
{
	/* Take necessary actions when application becomes visible. */
}

static void
app_terminate(void *data)
{
	/* Release all resources. */
}

static void
ui_app_lang_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LANGUAGE_CHANGED*/
	char *locale = NULL;
	system_settings_get_value_string(SYSTEM_SETTINGS_KEY_LOCALE_LANGUAGE, &locale);
	elm_language_set(locale);
	free(locale);
	return;
}

static void
ui_app_orient_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_DEVICE_ORIENTATION_CHANGED*/
	return;
}

static void
ui_app_region_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_REGION_FORMAT_CHANGED*/
}

static void
ui_app_low_battery(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_BATTERY*/
}

static void
ui_app_low_memory(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_MEMORY*/
}

int
main(int argc, char *argv[])
{
	appdata_s ad = {0,};
	int ret = 0;

	ui_app_lifecycle_callback_s event_callback = {0,};
	app_event_handler_h handlers[5] = {NULL, };

	event_callback.create = app_create;
	event_callback.terminate = app_terminate;
	event_callback.pause = app_pause;
	event_callback.resume = app_resume;
	event_callback.app_control = app_control;

	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_BATTERY], APP_EVENT_LOW_BATTERY, ui_app_low_battery, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_MEMORY], APP_EVENT_LOW_MEMORY, ui_app_low_memory, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_DEVICE_ORIENTATION_CHANGED], APP_EVENT_DEVICE_ORIENTATION_CHANGED, ui_app_orient_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LANGUAGE_CHANGED], APP_EVENT_LANGUAGE_CHANGED, ui_app_lang_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_REGION_FORMAT_CHANGED], APP_EVENT_REGION_FORMAT_CHANGED, ui_app_region_changed, &ad);
	ui_app_remove_event_handler(handlers[APP_EVENT_LOW_MEMORY]);

	ret = ui_app_main(argc, argv, &event_callback, &ad);
	if (ret != APP_ERROR_NONE) {
		dlog_print(DLOG_ERROR, LOG_TAG, "app_main() is failed. err = %d", ret);
	}

	return ret;
}

#endif //__TIZEN__
