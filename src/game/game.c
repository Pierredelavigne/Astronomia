/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** game
*/

#include "my.h"

int start_game(t_global *global)
{
    sfRenderWindow *window = create_window();
    global->clock = sfClock_create();
    global->current_scene = 0;
    void (*tabptr[8]) (sfRenderWindow *, t_global *) = {loop_menu_scene,
    handle_loop_cinematic, handle_loop_main_scene, loop_fight, loop_pause_scene,
    handle_loop_inventory, game_over_scene, handle_loop_end_cinematic};
    for (int i = 0; sfRenderWindow_isOpen(window); i++) {
        if (i == global->current_scene)
            tabptr[i](window, global);
        if (i == 7)
            i = -1;
    }
    clean(window, global);
    return (0);
}