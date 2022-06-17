/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** set_two_fight
*/

#include "my.h"

void set_button(t_battle *battle)
{
    sfVector2f pos = {650, 600};
    sfVector2f size = {140, 56};

    battle->attack = init_button(pos, size, "assets/images/attack_button.png");
    pos.y = 600;
    pos.x = 900;
    size.x = 285;
    size.y = 56;
    battle->weapon = init_button(pos, size, "assets/images/weapon_button.png");
}