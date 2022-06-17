/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** inventory_get for myrpg
*/

#include "my.h"

sfSprite *get_weapon_main_sprite(t_global *global)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1150, 430};
    inventory_t *begin = global->inventory;
    sfSprite *weapon = sfSprite_create();
    sfTexture  *texture;
    while (begin != NULL) {
        if (begin->main == 1)
            break;
        begin = begin->next;
    }
    if (begin != NULL)
        texture = sfTexture_createFromFile(begin->filename, NULL);
    if (begin == NULL)
        texture = sfTexture_createFromFile("assets/images/fist.png", NULL);
    sfSprite_setTexture(weapon, texture, sfTrue);
    sfSprite_setScale(weapon, scale);
    sfSprite_setPosition(weapon, pos);
    return (weapon);
}

int get_weapon_damage(t_global *global)
{
    inventory_t *begin = global->inventory;
    if (global->inventory->next == NULL) {
        begin->damage = 2;
    } else {
        while (begin != NULL) {
            if (begin->main == 1)
                break;
            begin = begin->next;
        }
    }
    if (begin == NULL)
        return (0);
    return (begin->damage);
}