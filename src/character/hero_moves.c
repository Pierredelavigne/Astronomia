/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** hero_moves
*/

#include "my.h"

const float max_time = 0.6;

int is_an_arrow_key(sfKeyCode code)
{
    if (code == sfKeyUp ||
        code == sfKeyDown ||
        code == sfKeyRight ||
        code == sfKeyLeft)
        return (1);
    return (0);
}

int get_left(float secs, sfClock *clock)
{
    int left = 0;

    if (secs <= max_time)
        left = 64;
    if (secs <= (max_time / 3) * 2)
        left = 32;
    if (secs <= max_time / 3)
        left = 0;
    return (left);
}

void handle_moving_clock(t_global *global)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(global->clocks.hero))
    >= max_time)
        sfClock_restart(global->clocks.hero);
}

sfSprite *get_walking_char(sfKeyCode code, sfSprite *sprite,
sfVector2f position, sfClock *clock)
{
    sfIntRect rect;
    float secs = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    rect.left = get_left(secs, clock);
    rect.width = 32;
    rect.height = 32;
    rect.top = 0;
    if (code == sfKeyUp)
        rect.top = 96;
    if (code == sfKeyRight)
        rect.top = 64;
    if (code == sfKeyLeft)
        rect.top = 32;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}

void draw_walking_hero(sfRenderWindow *window, t_global *global, sfKeyCode code)
{
    global->sprites.hero = get_walking_char(code,
    global->sprites.hero, global->pos.hero, global->clocks.hero);
    sfRenderWindow_drawSprite(window, global->sprites.hero, NULL);
}