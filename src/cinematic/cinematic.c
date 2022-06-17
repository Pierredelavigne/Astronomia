/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** cinematic
*/

#include "my.h"

const sfVector2f middle_pos = { 300 - 64, 720 / 2 - 64};

void do_fire_sound(t_global *global)
{
    if (!global->bools.fire_sound) {
        sfSound_play(global->sounds.cinmatic_enemy_fire);
        global->bools.fire_sound = 1;
    }
}

void draw_cinematic_two(sfRenderWindow *window, t_global *global,
float seconds)
{
    if (seconds < 17 && seconds > 12) {
        sfRenderWindow_drawSprite(window,
        set_enemy_ship(global->sprites.cinematic_enemy, global, 100), NULL);
        global->cinematic.pos_fire =
        sfSprite_getPosition(global->sprites.cinematic_enemy);
        global->cinematic.pos_fire.x += 150;
    }
    if (seconds > 17)
        sfRenderWindow_drawSprite(window,
        set_enemy_ship(global->sprites.cinematic_enemy, global, 40), NULL);
    if (seconds > 18 && seconds < 19.5) {
        sfRenderWindow_drawSprite(window,
        set_fire(global->sprites.cinematic_fire, global), NULL);
        do_fire_sound(global);
    }
}

void cinematic_part_one(sfRenderWindow *window,
t_global *global, float seconds)
{
    sfRenderWindow_drawSprite(window,
    set_bg(global->sprites.cinematic_bg, global), NULL);
    sfRenderWindow_drawSprite(window,
    get_first_planet(global->sprites.cinematic_planet, global), NULL);
    sfRenderWindow_drawSprite(window,
    get_first_planet(global->sprites.cinematic_planet, global), NULL);
    if (seconds < 19)
        sfRenderWindow_drawSprite(window,
        set_spaceship(global->sprites.cinematic_spaceship, middle_pos), NULL);
    else
        sfRenderWindow_drawSprite(window,
        set_zooming_out(global->sprites.cinematic_spaceship, middle_pos,
        global), NULL);
    draw_cinematic_two(window, global, seconds);
}

void draw_cinematic(sfRenderWindow *window, t_global *global)
{
    float seconds =
    sfTime_asSeconds(sfClock_getElapsedTime(global->clocks.cinematic));

    if (seconds > 25)
        draw_texts_cinematic(window, global);
    else
        cinematic_part_one(window, global, seconds);
}