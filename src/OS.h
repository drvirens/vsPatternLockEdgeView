//
//  OS.h
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef OS_h
#define OS_h

//
// Purpose of this file is to let Xcode llvm compiler compile the shit while not linking to any tizen specific code
//


#ifdef __cplusplus
extern "C" {
#endif


#if defined __APPLE__
typedef void Evas_Object;
typedef struct _Evas Evas;

typedef void      (*Evas_Object_Event_Cb)(void *data, Evas *e, Evas_Object *obj, void *event_info);

typedef struct _Eina_List            Eina_List;

typedef struct _Evas_Event_Mouse_Down    Evas_Event_Mouse_Down; /**< @brief Event structure for #EVAS_CALLBACK_MOUSE_DOWN event callbacks */
typedef struct _Evas_Event_Mouse_Up      Evas_Event_Mouse_Up; /**< @brief Event structure for #EVAS_CALLBACK_MOUSE_UP event callbacks */
typedef struct _Evas_Event_Mouse_In      Evas_Event_Mouse_In; /**< @brief Event structure for #EVAS_CALLBACK_MOUSE_IN event callbacks */
typedef struct _Evas_Event_Mouse_Out     Evas_Event_Mouse_Out; /**< @brief Event structure for #EVAS_CALLBACK_MOUSE_OUT event callbacks */
typedef struct _Evas_Event_Mouse_Move    Evas_Event_Mouse_Move; /**< @brief Event structure for #EVAS_CALLBACK_MOUSE_MOVE event callbacks */
typedef struct _Evas_Event_Mouse_Wheel   Evas_Event_Mouse_Wheel; /**< @brief Event structure for #EVAS_CALLBACK_MOUSE_WHEEL event callbacks */


typedef int                        Evas_Coord;         /**< @brief Evas x y coordinates */

typedef struct _Evas_Coord_Rectangle       Evas_Coord_Rectangle; /**< @brief A generic rectangle handle */
typedef struct _Evas_Point                 Evas_Point;   /**< @brief Integer point */

typedef struct _Evas_Coord_Point           Evas_Coord_Point;    /**< @brief Evas_Coord point */
typedef struct _Evas_Coord_Precision_Point Evas_Coord_Precision_Point;   /**< @brief Evas_Coord point with sub-pixel precision */

typedef struct _Evas_Coord_Size            Evas_Coord_Size;    /**< @brief Evas_Coord size @since 1.8 */
typedef struct _Evas_Position              Evas_Position;   /**< @brief Associates the given point in Canvas and Output */
typedef struct _Evas_Precision_Position    Evas_Precision_Position;   /**< @brief Associates the given point in Canvas and Output, with sub-pixel precision */

typedef struct _Eina_Rectangle
{
   int x; /**< The top-left x co-ordinate of the rectangle */
   int y; /**< The top-left y co-ordinate of the rectangle */
   int w; /**< The width of the rectangle */
   int h; /**< The height of the rectangle */
} Eina_Rectangle;

struct _Evas_Point
{
   int x, y;
};

struct _Evas_Coord_Point
{
   Evas_Coord x; /**< X co-ordinate */
   Evas_Coord y; /**< Y co-ordinate */
};

struct _Evas_Coord_Size
{
   Evas_Coord w; /**< Width */
   Evas_Coord h; /**< Height */
};


struct _Evas_Position
{
   Evas_Point       output;
   Evas_Coord_Point canvas; /**< Position on the canvas */
};


struct _Evas_Event_Mouse_Down /** @brief Mouse button press event */
{
   int               button; /**< Mouse button number that went down (1 - 32) */

   Evas_Point        output; /**< The X/Y location of the cursor */
   Evas_Coord_Point  canvas; /**< The X/Y location of the cursor */

//   void             *data;
//   Evas_Modifier    *modifiers; /**< Modifier keys pressed during the event */
//   Evas_Lock        *locks;
//
//   Evas_Button_Flags flags; /**< Button flags set during the event */
//   unsigned int      timestamp;
//   Evas_Event_Flags  event_flags;
//   Evas_Device      *dev;
};


struct _Evas_Event_Mouse_Move /** @brief Mouse move event */
{
   int              buttons; /**< Button pressed mask, Bits set to @c 1 are buttons currently pressed (bit 0 = mouse button 1, bit 1 = mouse button 2 and so on) */

   Evas_Position    cur; /**< Current mouse position */
   Evas_Position    prev; /**< Previous mouse position */

//   void            *data;
//   Evas_Modifier    *modifiers; /**< Modifier keys pressed during the event */
//   Evas_Lock       *locks;
//   unsigned int     timestamp;
//   Evas_Event_Flags event_flags;
//   Evas_Device     *dev;
};

#endif

#if defined __TIZEN__
#include <evas.h>
#endif



#ifdef __cplusplus
}
#endif


#endif /* OS_h */
