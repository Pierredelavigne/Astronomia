/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** events
*/

#include "my.h"

void events_cinematic(sfRenderWindow *window, t_global *global)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (global->event.type == sfEvtKeyPressed)
            global->current_scene = 2;
    }
}