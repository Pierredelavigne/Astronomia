/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** stats
*/

#include "my.h"

const float margin = 5.0;
const char *path_font = "assets/font/squadron_2mew.ttf";

void set_level_text(t_global *global, const char *string)
{
    sfVector2f pos;
    sfFloatRect bounds;

    char *str = my_strcat("LVL: ", string);
    sfText_setString(global->stats_text, str);
    bounds = sfText_getGlobalBounds(global->stats_text);
    pos.x = 1280 - bounds.width - margin;
    pos.y = margin;
    sfText_setPosition(global->stats_text, pos);
}

void init_level_text(t_global *global)
{
    sfVector2f first_pos = {10, 0};
    global->stats_text = sfText_create();
    sfText_setFont(global->stats_text, sfFont_createFromFile(path_font));
    sfText_setOutlineColor(global->stats_text, sfColor_fromRGB(0, 0, 0));
    sfText_setOutlineThickness(global->stats_text, 5.0);
    sfText_setFillColor(global->stats_text, sfColor_fromRGB(255, 255, 255));
    sfText_setCharacterSize(global->stats_text, 30);
    set_level_text(global, "0");
}

void display_stats(sfRenderWindow *window, t_global *global)
{
    sfText_setString(global->stats_text, str_append("LVL: ",
    nbr_to_str(global->stats.level)));
    sfRenderWindow_drawText(window, global->stats_text, NULL);
}

void set_stat_player(t_global *global)
{
    global->stats.strength = 20;
    global->stats.lp = 500;
    global->stats.level = 1;
    global->stats.lp_max = 500;
    global->en_stats.strength = 60;
    global->en_stats.lp = 500;
    global->en_stats.lp_max = 500;
}