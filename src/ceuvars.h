#ifndef CEUVARS
#define CEUVARS
enum {
CEU_IN_COMPONENT_DRAW = 128,
CEU_IN_DELETE_CREDITS,
CEU_IN_DELETE_DEMO_SESSION,
CEU_IN_DELETE_GAME_SESSION,
CEU_IN_DELETE_LEVEL_MENU,
CEU_IN_DELETE_PINGUS_MENU = 133,
CEU_IN_DELETE_RESULT_SCREEN,
#if 0
CEU_IN_DELETE_SCREEN_MANAGER,
#endif
CEU_IN_DELETE_SERVER_EVENT,
CEU_IN_DELETE_START_SCREEN,
CEU_IN_DELETE_STORY_SCREEN,
CEU_IN_DELETE_WORLDMAP_SCREEN,
CEU_IN_DEMO_SESSION_ON_SCROLLER_MOVE,
CEU_IN_LOAD_WORLDMAP_SCREEN,
#if 0
CEU_IN_NEW_CREDITS = 142,
#endif
CEU_IN_NEW_DEMO_SESSION,
CEU_IN_NEW_GAME_SESSION,
#if 0
CEU_IN_NEW_LEVEL_MENU,
CEU_IN_NEW_PINGUS_MENU = 146,
#endif
CEU_IN_NEW_RESULT_SCREEN,
CEU_IN_NEW_SCREEN_MANAGER,
CEU_IN_NEW_SERVER_EVENT,
CEU_IN_NEW_START_SCREEN,
CEU_IN_NEW_STORY_SCREEN,
CEU_IN_NEW_WORLDMAP_SCREEN,
#if 0
CEU_IN_ON_POINTER_ENTER,
CEU_IN_ON_POINTER_LEAVE,
CEU_IN_ON_POINTER_MOVE,
CEU_IN_ON_PRIMARY_BUTTON_CLICK,
CEU_IN_ON_PRIMARY_BUTTON_PRESS,
CEU_IN_ON_PRIMARY_BUTTON_RELEASE,
CEU_IN_ON_SECONDARY_BUTTON_CLICK,
CEU_IN_ON_SECONDARY_BUTTON_PRESS,
CEU_IN_ON_SECONDARY_BUTTON_RELEASE,
#endif
CEU_IN_ON_STARTUP,
CEU_IN_PUSH_FONT_TEST_SCREEN,
CEU_IN_RECT_COMPONENT_UPDATE_LAYOUT,
CEU_IN_RESTART_DEMO_SESSION,
CEU_IN_SCREEN_MANAGER_UPDATE,
CEU_IN_SCREEN_RESIZE,
CEU_IN_SDL_DT,
CEU_IN_SDL_QUIT,
CEU_IN_SDL_REDRAW,
CEU_IN__WCLOCK
};
#include "_ceu_app.h"
extern tceu_app CEUapp;
#endif
