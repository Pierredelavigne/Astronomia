/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** touch
*/

#include "my.h"

int is_in_range(sfVector2f first, sfVector2f second, float range)
{
    sfVector2f pos_first = {first.x - 8, first.y - 8};
    sfVector2f pos_second = {second.x - 8, second.y - 8};
    sfFloatRect rect_first = {0, 0, 56, 56};
    sfFloatRect rect_second = {0, 0, 56, 56};
    if (pos_first.x <= pos_second.x + rect_second.width &&
    pos_first.x + rect_first.width >=  pos_second.x &&
    pos_first.y <= pos_second.y + rect_second.height &&
    pos_first.y + rect_first.height >= pos_second.y) {
        return (1);
    }
    return (0);
}