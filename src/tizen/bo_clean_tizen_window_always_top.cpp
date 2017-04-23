//
//  bo_clean_tizen_window_always_top.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//


#if defined __TIZEN__
#include <efl_util.h>
#endif

#include "bo_clean_tizen_window_always_top.hpp"
#include "trace.hpp"



//below is used for actual screen lock app that should get launched by service when display on/off occurs monitored via dbus
//#define USE_LOCK_SCREEN_ALWAYS_ON_TOP_WINDOW 1

 

extern Evas_Object* __tizen_lock_window_create(void) 
{TRACE
  //int x = 0, y = 0, w = 0, h = 0;

  Evas_Object* win = NULL;

#if defined __TIZEN__

#if !defined USE_LOCK_SCREEN_ALWAYS_ON_TOP_WINDOW


#if !defined(PACKAGE)
#define PACKAGE "org.example.vspatternlockedgeview"
#endif

	win = elm_win_util_standard_add(PACKAGE, PACKAGE);
	elm_win_autodel_set(win, EINA_TRUE);
  
#else

  win = elm_win_add(NULL, "LOCKSCREEN", ELM_WIN_NOTIFICATION);
  //retv_if(!win, NULL);

  //elm_win_alpha_set(win, EINA_TRUE);
  elm_win_alpha_set(win, EINA_FALSE);
  //elm_win_aux_hint_add(win, "wm.policy.win.user.geometry", "1");
  elm_win_title_set(win, "LOCKSCREEN");
  elm_win_borderless_set(win, EINA_TRUE);
  elm_win_autodel_set(win, EINA_TRUE);
  elm_win_role_set(win, "no-dim");
  elm_win_indicator_mode_set(win, ELM_WIN_INDICATOR_SHOW);
  //elm_win_indicator_mode_set(win, ELM_WIN_INDICATOR_HIDE);
  efl_util_set_notification_window_level(win, EFL_UTIL_NOTIFICATION_LEVEL_1);

  //elm_win_screen_size_get(win, &x, &y, &w, &h);

  Evas_Object* bg = elm_bg_add(win);
  evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
  elm_win_resize_object_add(win, bg);
  elm_bg_color_set(bg, 0xf4, 0x59, 0x42); //f45942
  evas_object_show(bg);
#endif

#endif //__TIZEN__

  return win;
}
