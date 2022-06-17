/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** click
*/

#include "my.h"
#include "scenes.h"

int mouse_touches_rect(sfVector2i mouse, sfVector2f pos, sfFloatRect rect)
{
    if ((float)mouse.x >= pos.x &&
    (float)mouse.x <= pos.x + rect.width &&
    (float)mouse.y <= pos.y + rect.height &&
    (float)mouse.y >= pos.y) {
        return (1);
    }
    return (0);
}

int button_clicked(button_t *button, sfVector2f click_position, sfMusic *sound)
{
    sfFloatRect rectangle = { 0, 0, button->size[0].x, button->size[0].y };
    if (button_is_clicked(button->rect, click_position)) {
        sfMusic_play(sound);
        return (1);
    }
        return (1);
}
