/*
** EPITECH PROJECT, 2021
** inventory_menu.c
** File description:
** file to handle scne of inventory
*/

#include "my.h"
#include "inventory.h"

void events_inventory(sfRenderWindow *window, t_global *global)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1) {
            global[0].bools.exit = 1;
        }
    }
}

char ***do_inventory(void)
{
    char ***inventory = malloc(sizeof(char *)* 3);
    inventory[0] = malloc(sizeof(char *)* 4);
    inventory[0][0] = "begin";
    inventory[0][1] = "begin";
    inventory[0][2] = "begin";
    inventory[0][3] = "here is the descriptions";
    inventory[1] = malloc(sizeof(char *)* 4);
    inventory[1][0] = "saber";
    inventory[1][1] = "./assets/images/saber.png";
    inventory[1][2] = "attack";
    inventory[1][3] = "here is the descritions";
    inventory[2] = malloc(sizeof(char *)* 4);
    inventory[2][0] = "blade";
    inventory[2][1] = "assets/images/blade.png";
    inventory[2][2] = "attack";
    inventory[2][3] = "here is the descritions";
    return (inventory);
}

void inventory_create(t_global *global)
{
    char ***inventory = do_inventory();
    char **third = malloc(sizeof(char *)* 4);

    third[0] = "fuel";
    third[1] = "assets/images/fuel.png";
    third[2] = "fuel";
    third[3] = "here is the descritions";
    global->inventory = create_inventory(inventory[0], 0, 0, 0);
    add_to_list(global->inventory, create_inventory(inventory[1], 70, 0, 1));
    add_to_list(global->inventory, create_inventory(inventory[2], 30, 0, 2));
    add_to_list(global->inventory, create_inventory(third, 0, 0, 3));
}

void handle_loop_inventory(sfRenderWindow *window, t_global *global)
{
    sfSprite *bg_s = set_sprite_bg();
    char *text = malloc(sizeof(char)* 50);
    sfText *description = declare_text();
    sfText *stats = set_stats(global);

    global[0].bools.exit = 0;
    while (sfRenderWindow_isOpen(window) && !global[0].bools.exit) {
        sfRenderWindow_clear(window, sfBlack);
        events_inventory(window, global);
        sfRenderWindow_drawSprite(window, bg_s, NULL);
        text = draw_inventory(window, global);
        sfText_setString(description, text);
        sfRenderWindow_drawText(window, description, NULL);
        sfRenderWindow_drawText(window, stats, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(bg_s);
    sfClock_restart(global->clock);
}