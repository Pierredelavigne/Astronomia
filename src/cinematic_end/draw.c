/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** draw
*/

#include "my.h"

const float speed_hero_end = 200;
const float ship_speed = 200;

void move_ship(t_global *global)
{
    float angle =
    sfSprite_getRotation(global->sprites.end_cinematic_spaceship) +
    (sfTime_asSeconds(global->time_clock) * 10);
    sfVector2f pos_ship =
    sfSprite_getPosition(global->sprites.end_cinematic_spaceship);
    float to_move = sfTime_asSeconds(global->time_clock) * ship_speed;
    pos_ship.y -= to_move;
    sfSprite_setPosition(global->sprites.end_cinematic_spaceship, pos_ship);
    sfSprite_setRotation(global->sprites.end_cinematic_spaceship, angle);
}

void fade_text(t_global *global)
{
    if (global->fade_value < 255)
        global->fade_value = global->fade_value +
        sfTime_asSeconds(global->time_clock) * 50;
    sfText_setFillColor(global->texts.end,
    sfColor_fromRGBA(255, 255, 255, global->fade_value));
}

void draw_two(sfRenderWindow *window, t_global *global, float seconds)
{
    if (seconds > 5)
        move_ship(global);
    if (seconds > 8) {
        global->pos.trader_end =
        move_entity_end(global, global->pos.trader_end, sfKeyRight);
        sfRenderWindow_drawSprite(window, get_walking_char(sfKeyRight,
        global->sprites.end_cinematic_trader,
        global->pos.trader_end, global->clocks.hero), NULL);
        fade_text(global);
        sfRenderWindow_drawText(window, global->texts.end, NULL);
    }
}

void draw_end_cinematic_one(sfRenderWindow *window,
t_global *global, float seconds)
{
    sfRenderWindow_drawSprite(window,
    global->sprites.end_cinematic_spaceship, NULL);
    if (seconds < 8)
        sfRenderWindow_drawSprite(window, get_standing_char(sfKeyLeft,
        global->sprites.end_cinematic_trader, global->pos.trader_end), NULL);
    if (seconds < 4) {
        sfRenderWindow_drawSprite(window, get_walking_char(sfKeyRight,
        global->sprites.end_cinematic_hero,
        global->pos.hero_end, global->clocks.hero), NULL);
        global->pos.hero_end =
        move_entity_end(global, global->pos.hero_end, sfKeyRight);
    }
    draw_two(window, global, seconds);
}

void draw_end_cinematic(sfRenderWindow *window, t_global *global)
{
    float seconds =
    sfTime_asSeconds(sfClock_getElapsedTime(global->clocks.end_cinematic));

    draw_end_cinematic_one(window, global, seconds);
}