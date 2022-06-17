/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** hero_collide
*/

#include "my.h"

const float hero_size = 25;

int block_touches_entity(sfVector2f entity_pos, sfVector2f block_pos)
{
    float size = 32.0;

    if (entity_pos.x <= block_pos.x + size &&
    entity_pos.x + size >=  block_pos.x &&
    entity_pos.y <= block_pos.y + size &&
    entity_pos.y + size >= block_pos.y){
        return (1);
    }
    return (0);
}

int hero_can_move(t_global *global, sfVector2f new_pos)
{
    if (global->bools.in_trader_conv != 0 || global->bools.in_thief_conv != 0)
        return (0);
    for (int i = 0; global->blocks_map[i].sprite != NULL; i++)
        if (global->blocks_map[i].colisable == sfTrue &&
        block_touches_entity(new_pos, global->blocks_map[i].pos))
            return (0);
    if (block_touches_entity(new_pos, global->pos.trader))
        return (0);
    if (block_touches_entity(new_pos, global->pos.thief))
        return (0);
    return (1);
}
