/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** inventory_tools for myrpg
*/

#include "my.h"
#include <string.h>

sfVector2f display_inventory(sfTexture **data, sfSprite *sprite,
sfVector2f position, int i)
{
    sfSprite_setTexture(sprite, data[i] , sfTrue);
    sfSprite_setPosition(sprite, position);
    position = set_position(position);
    return (position);
}

char *draw_inventory(sfRenderWindow *window, t_global *global)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture **data = load_texture(global);
    char *result = malloc(sizeof(char )* 50);
    inventory_t *begin = global->inventory;
    sfVector2f position = {300 + 29, 393};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (result == NULL)
        sfRenderWindow_close(window);
    result = NULL;
    begin = begin->next;
    for (int i = 0; begin != NULL; i++, begin = begin->next) {
        if (begin->have == 1) {
            position = display_inventory(data, sprite, position, i);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        if (mouse_touches_sprite(mouse, sprite) == 1)
            result = begin->name;
    }
    return (result);
}

sfVector2f set_position(sfVector2f position)
{
    if (position.x >= 913) {
        position.x = 329;
        position.y += 73;
    }
    else
        position.x += 73;
    return (position);
}

int is_weapon_in_inventory(t_global *global, int id)
{
    inventory_t *begin = global->inventory;
    while (begin != NULL) {
        if (begin->id == id && begin->have == 1)
            return (1);
        begin = begin->next;
    }
    return (0);
}