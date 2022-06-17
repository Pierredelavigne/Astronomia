/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** movements
*/

#include "my.h"

const float speed_fire = 400;

sfSprite *set_zooming_out(sfSprite *sprite,
sfVector2f position, t_global *global)
{
    sfIntRect rect;
    sfVector2f scale = {4, 4};
    if (global->cinematic.scale > 0)
        global->cinematic.scale -= sfTime_asSeconds(global->time_clock);
    scale.x = global->cinematic.scale;
    scale.y = global->cinematic.scale;
    global->cinematic.angle -= 25 * sfTime_asSeconds(global->time_clock);

    rect.left = 256;
    rect.width = 64;
    rect.height = 64;
    rect.top = 128;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    sfSprite_setRotation(sprite, global->cinematic.angle);
    return (sprite);
}

sfSprite *set_enemy_ship(sfSprite *sprite, t_global *global, float speed)
{
    sfIntRect rect;
    sfVector2f scale = {4, 4};
    sfVector2f position = {0, 300};

    global->cinematic.enemy_x -= speed * sfTime_asSeconds(global->time_clock);
    position.x = global->cinematic.enemy_x;
    rect.left = 0;
    rect.width = 165;
    rect.height = 74;
    rect.top = 0;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfSprite *set_fire(sfSprite *sprite, t_global *global)
{
    sfIntRect rect;
    sfVector2f scale = {4, 4};
    if (sfTime_asSeconds(
    sfClock_getElapsedTime(global->clocks.fire_cinematic)) > 0.3) {
        sfClock_restart(global->clocks.fire_cinematic);
        global->cinematic.fire_animation++;
    }
    if (global->cinematic.fire_animation >= 4)
        global->cinematic.fire_animation = 0;
    global->cinematic.pos_fire.x -= speed_fire *
    sfTime_asSeconds(global->time_clock);
    rect.top = 0;
    rect.width = 40;
    rect.height = 120;
    rect.left = 38 * global->cinematic.fire_animation;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, global->cinematic.pos_fire);
    sfSprite_setScale(sprite, scale);
    sfSprite_setRotation(sprite, 90);
    return (sprite);
}