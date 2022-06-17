/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** menu
*/

#include "my.h"
#include "scenes.h"

void events_menu(sfRenderWindow *window, t_global *global)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void handle_loop_main_menu(sfRenderWindow *window, t_global *global)
{
    sfColor color_clear = sfColor_fromRGB(0, 0, 0);
    global[0].bools.exit_menu = 0;

    while (sfRenderWindow_isOpen(window) && !global[0].bools.exit_menu)
    {
        global[0].time_clock = sfClock_getElapsedTime(global[0].clock);
        sfClock_restart(global[0].clock);
        sfRenderWindow_clear(window, color_clear);
        sfRenderWindow_display(window);
    }
}