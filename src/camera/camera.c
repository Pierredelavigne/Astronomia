/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** camera
*/

#include "my.h"

void move_all_blocks(t_global *global, float to_move, sfKeyCode key)
{
    sfVector2f pos;

    for (int i = 0; global->blocks_map[i].sprite != NULL; i++) {
        if (key == sfKeyDown)
            global->blocks_map[i].pos.y -= to_move;
        if (key == sfKeyUp)
            global->blocks_map[i].pos.y += to_move;
        if (key == sfKeyLeft)
            global->blocks_map[i].pos.x += to_move;
        if (key == sfKeyRight)
            global->blocks_map[i].pos.x -= to_move;
    }
}

sfVector2f move_entity(sfVector2f pos, sfKeyCode key, float to_move)
{
    sfVector2f new_pos = {pos.x, pos.y};

    if (key == sfKeyUp)
        new_pos.y += to_move;
    if (key == sfKeyDown)
        new_pos.y -= to_move;
    if (key == sfKeyRight)
        new_pos.x -= to_move;
    if (key == sfKeyLeft)
        new_pos.x += to_move;
    return (new_pos);
}

void move_it_all(t_global *global, float to_move, sfKeyCode key)
{
    move_all_blocks(global, to_move, key);
    global->pos.trader = move_entity(global->pos.trader, key, to_move);
    global->pos.thief = move_entity(global->pos.thief, key, to_move);
    global->pos.saber = move_entity(global->pos.saber, key, to_move);
    global->pos.blade = move_entity(global->pos.blade, key, to_move);
}