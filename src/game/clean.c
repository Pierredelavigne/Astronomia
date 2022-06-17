/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** clean
*/

#include <stdlib.h>
#include "../include/my.h"

void clean(sfRenderWindow *window, t_global *global)
{
    sfClock_destroy(global->clock);
    sfRenderWindow_destroy(window);
    free(global);
}