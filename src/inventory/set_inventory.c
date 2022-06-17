/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** set_inventory for myrpg
*/

#include "my.h"

sfText *declare_text(void)
{
    sfText *description = sfText_create();
    sfVector2f pos = {580, 630};
    sfFont *font = sfFont_createFromFile(path_font);
    sfText_setFont(description, font);
    sfText_setFillColor (description, sfBlack);
    sfText_setPosition(description, pos);

    return (description);
}

sfTexture **load_texture(t_global *global)
{
    inventory_t *begin = global->inventory;
    sfTexture **data;
    int i = 0;

    for (i = 0; global->inventory != NULL; i++)
        global->inventory = global[0].inventory->next;
    data = malloc(sizeof(sfTexture *)* i + 1);
    if (data == NULL)
        exit (84);
    global[0].inventory = begin;
    global[0].inventory = global[0].inventory->next;
    for (i = 0; global[0].inventory != NULL; i++) {
        data[i] = sfTexture_createFromFile(global[0].inventory->filename, NULL);
        global[0].inventory = global[0].inventory->next;
    }
    global[0].inventory = begin;
    return (data);
}

sfSprite *set_sprite_bg(void)
{
    sfSprite *bg_s = sfSprite_create();
    sfTexture *bg = sfTexture_createFromFile
    ("assets/images/inventory.png", NULL);
    sfVector2f position = {300, 50};

    sfSprite_setTexture(bg_s, bg, sfTrue);
    sfSprite_setPosition(bg_s, position);
    return (bg_s);
}

sfText *set_stats(t_global *global)
{
    sfText *stats = declare_text();
    sfVector2f position = {555, 75};
    char *text = str_append("Level : ", nbr_to_str(global->stats.level));
    char *strength = str_append("Strength : ",
    nbr_to_str(global->stats.strength));
    char *lp = str_append("Lp : ", nbr_to_str(global->stats.lp));
    char *lp_max = str_append("Lp max : ", nbr_to_str(global->stats.lp_max));

    sfText_setPosition(stats, position);
    sfText_setCharacterSize(stats, 23);
    sfText_setLineSpacing(stats, 2.5);
    text = str_append(text, "\n");
    text = str_append(text, strength);
    text = str_append(text, "\n");
    text = str_append(text, lp);
    text = str_append(text, "\n");
    text = str_append(text, lp_max);

    sfText_setString(stats, text);
    return (stats);
}

sfSprite *set_weapon(const char *filename, int x, int y, sfVector2f *pos)
{
    sfSprite *weapon = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);

    pos->x = x;
    pos->y = y;
    sfSprite_setTexture(weapon, texture, sfTrue);
    sfSprite_setPosition(weapon, *pos);
    return (weapon);
}