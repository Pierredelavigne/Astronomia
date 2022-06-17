/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** snow for the myrpg
*/

#include "my.h"

sfRectangleShape **declare_snow_particle(t_global *global)
{
    sfVector2f pos = {0, 0};
    sfRectangleShape **snow = malloc(sizeof(sfRectangleShape *)* 450);
    for (int i = 0; i <= 450; i++) {
        snow[i] = define_particle();
        pos.x = rand() % 1300;
        sfRectangleShape_setFillColor(snow[i], sfWhite);
        sfRectangleShape_setPosition(snow[i], pos);
        if (i % 20 == 0)
            pos.y -= 40;
    }
    return (snow);
}

sfVector2f set_color_snow(sfRectangleShape *snow, sfVector2f pos)
{
    if (pos.y >= 720) {
        pos.y = 0;
        sfRectangleShape_setFillColor(snow,
        sfColor_fromRGBA(255, 255, 255, rand() % 255));
    }
    if (pos.y >= rand() % 180)
        sfRectangleShape_setFillColor(snow,
        sfColor_fromRGBA(255, 255, 255, rand() % 200));
    if (pos.y >= rand() % 360)
        sfRectangleShape_setFillColor(snow,
        sfColor_fromRGBA(255, 255, 255, rand() % 150));
    if (pos.y >= rand() % 540)
        sfRectangleShape_setFillColor(snow,
        sfColor_fromRGBA(255, 255, 255, rand() % 50));
    return (pos);
}

void draw_snow(sfRenderWindow *window, t_global *global,
sfRectangleShape **snow, sfClock *clock)
{
    sfVector2f pos;
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    for (int i = 0; i <= 450; i++) {
        pos = sfRectangleShape_getPosition(snow[i]);
        if (seconds > 0.2) {
            sfClock_restart(clock);
            pos.y += 20;
        }
        pos = set_color_snow(snow[i], pos);
        sfRectangleShape_setPosition(snow[i], pos);
        sfRenderWindow_drawRectangleShape(window, snow[i], NULL);
    }
}