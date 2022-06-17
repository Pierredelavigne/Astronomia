/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** update_inventory for myrpg
*/

#include "my.h"

void update_inventory(sfRenderWindow *window, t_global *global, int id)
{
    inventory_t *begin = global->inventory->next;

    while (begin->id != id)
        begin = begin->next;
    begin->have = 1;
    begin->main = 1;
}