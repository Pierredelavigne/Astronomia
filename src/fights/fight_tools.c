/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** fight_tools for myrpg
*/

#include "my.h"

int button_is_clicked(sfRectangleShape *button, sfVector2f click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button);
    sfVector2f button_size = sfRectangleShape_getSize(button);
    if (click_position.x < (button_pos.x + button_size.x) &&
        click_position.x > button_pos.x) {
        if (click_position.y < (button_pos.y + button_size.y) &&
            click_position.y > button_pos.y) {
            return (1);
        }
    }
    return (0);
}

int mouse_click_sprite(sfSprite *sprite, sfEvent event, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2i mouse;
    if (event.type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if ((float)mouse.x >= pos.x &&
        (float)mouse.x <= pos.x + sfSprite_getLocalBounds(sprite).width &&
        (float)mouse.y <= pos.y + sfSprite_getLocalBounds(sprite).height &&
        (float)mouse.y >= pos.y)
            return (1);
    }
    return (0);
}

sfRectangleShape *init_button(sfVector2f position, sfVector2f size,
                char *filename)
{
    sfTexture* texture = sfTexture_createFromFile(filename, NULL);
    sfRectangleShape *button = sfRectangleShape_create();
    sfRectangleShape_setSize(button, size);
    sfRectangleShape_setPosition(button, position);
    sfRectangleShape_setTexture(button, texture, sfTrue);
    return (button);
}

void set_main_to_zero(t_global *global)
{
    inventory_t *begin = global->inventory;
    while (global->inventory != NULL && global->inventory->main != 1)
        global->inventory = global->inventory->next;
    if (global->inventory != NULL)
        global->inventory->main = 0;
    global->inventory = begin;
    return;
}

int draw_fight_inventory(sfRenderWindow *window, t_global *global)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture **data = load_texture(global);
    inventory_t *begin = global->inventory->next;
    sfVector2f position = {300 + 29, 393};

    for (int i = 0; begin != NULL; i++) {
        if (begin->have == 1) {
            sfSprite_setTexture(sprite, data[i] , sfTrue);
            sfSprite_setPosition(sprite, position);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            position = set_position(position);
        }
        if (mouse_click_sprite(sprite, global->event, window) == 1) {
            set_main_to_zero(global);
            begin->main = 1;
            return (1);
        }
        begin = begin->next;
    }
    return (0);
}