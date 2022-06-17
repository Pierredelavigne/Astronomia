/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** scenes
*/

#ifndef SCENES_H_
#define SCENES_H_

#include "my.h"

#ifndef MACRO
#define MACRO

//filenames
#define HOME_BACKGROUND     "assets/scenes/homepage/space_moon_stars.png"
#define PAUSE_BACKGROUND    "assets/scenes/pause/onmoon.png"
#define START               "assets/scenes/homepage/letsplay.png"
#define QUIT                "assets/scenes/homepage/exit_neon.png"
#define HTP                 "assets/scenes/homepage/how_to_play.png"
#define RESUME              "assets/scenes/pause/play.png"
#define HOMEPAGE            "assets/scenes/pause/home.png"
#define EXIT                "assets/scenes/pause/exit_door.png"

#define HTP_SCENE           "assets/scenes/how_to_play.png"
#define CLOSE_HTP           "assets/scenes/closehtp.png"
#define BUTTON_CLICK        "assets/scenes/sound/button.ogg"
#define MAIN_SOUNDTRACK     "assets/soundtrack/xcom.ogg"

typedef struct button_s {
    sfRectangleShape* rect;
    sfVector2f *position;
    sfVector2f *size;
    char *filename;
} button_t;

typedef struct manage_button_s {
    button_t *button_play;
    button_t *button_quit;
    button_t *button_home;
    button_t *button_exit;
    button_t *button_resume_game;
} manage_button_t;

typedef struct game_object_s {
    sfTexture * texture_bg;
    sfSprite * sprite_bg;
    sfMusic *sound_but;
    sfMusic *music;
} game_object_t;

typedef struct scene_s {
    game_object_t *objs;
    manage_button_t * buttons;
    int i;
} scene_t;

#endif /* !MACRO */

#endif /* !SCENES_H_ */