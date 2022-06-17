/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** main
*/

#include <stdlib.h>
#include "../include/my.h"

t_global *create_const(t_global *global)
{
    global->clock = sfClock_create();
    init_level_text(global);
    create_character_textures(global);
    return (global);
}

int main(void)
{
    t_global *global = malloc(sizeof(t_global));

    if (global == NULL)
        return (84);
    global = create_const(global);
    return (start_game(global));
}