/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** npc
*/

#include "my.h"

void draw_npc(sfRenderWindow *window, t_global *global)
{
    handle_trader(window, global);
    handle_thief(window, global);
}