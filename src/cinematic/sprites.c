/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** sprites
*/

#include "my.h"

const float speed_bg = 5.0;
const float speed_planet = 11.0;
const float speed_planet_two = 7.0;

sfSprite *set_spaceship(sfSprite *sprite,
sfVector2f position)
{
    sfIntRect rect;
    sfVector2f scale = {4, 4};

    rect.left = 256;
    rect.width = 64;
    rect.height = 64;
    rect.top = 128;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfSprite *set_bg(sfSprite *sprite, t_global *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = sfSprite_getPosition(sprite);
    float to_move = sfTime_asSeconds(global->time_clock) * speed_bg;

    pos.x -= to_move;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfSprite *get_first_planet(sfSprite *sprite, t_global *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = sfSprite_getPosition(sprite);
    float to_move = sfTime_asSeconds(global->time_clock) * speed_planet;
    sfIntRect rect;

    rect.left = 0;
    rect.width = 105;
    rect.height = 106;
    rect.top = 0;
    sfSprite_setTextureRect(sprite, rect);
    pos.x -= to_move;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfSprite *get_second_planet(sfSprite *sprite, t_global *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = sfSprite_getPosition(sprite);
    float to_move = sfTime_asSeconds(global->time_clock) * speed_planet_two;
    sfIntRect rect;

    rect.left = 0;
    rect.width = 105;
    rect.height = 106;
    rect.top = 0;
    sfSprite_setTextureRect(sprite, rect);
    pos.x -= to_move;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}