/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** init
*/

#include "my.h"
#include "scenes.h"

void hard_resize(sfSprite* sprite, sfVector2f target_size)
{
    sfFloatRect rect = sfSprite_getLocalBounds(sprite);
    sfVector2f new_scale = {
        target_size.x / rect.width,
        target_size.y / rect.height
    };

    sfSprite_setScale(sprite, new_scale);
}

void initialize_button(button_t *button, sfVector2f position, sfVector2f size,
char *filename)
{
    button->rect = init_button(position, size, filename);
}