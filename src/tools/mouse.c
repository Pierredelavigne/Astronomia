/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** mouse
*/

#include "my.h"

int mouse_touches_sprite(sfVector2i mouse, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    if ((float)mouse.x >= pos.x &&
    (float)mouse.x <= pos.x + sfSprite_getLocalBounds(sprite).width &&
    (float)mouse.y <= pos.y + sfSprite_getLocalBounds(sprite).height &&
    (float)mouse.y >= pos.y) {
        return (1);
    }
    return (0);
}