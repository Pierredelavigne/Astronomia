/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** quest
*/

#include "my.h"

const float size = 25;

void set_text_parameters(t_global *global, char *str)
{
    sfText_setString(global->current_quest.text, str);
    sfText_setFont(global->current_quest.text,
    sfFont_createFromFile(path_font));
    sfText_setOutlineColor(global->current_quest.text,
    sfColor_fromRGB(0, 0, 0));
    sfText_setOutlineThickness(global->current_quest.text, size * 0.1);
    sfText_setFillColor(global->current_quest.text,
    sfColor_fromRGB(255, 255, 255));
    sfText_setCharacterSize(global->current_quest.text, size);
}

void set_quest(t_global *global, char *name, char *description)
{
    sfVector2f pos;
    sfFloatRect bounds;
    char *str = my_strcat("Current quest:\n", name);

    if (global->current_quest.name != NULL)
        free(global->current_quest.name);
    if (global->current_quest.description != NULL)
        free(global->current_quest.description);
    global->current_quest.name = my_strdup(name);
    global->current_quest.description = my_strdup(description);
    set_text_parameters(global, str);
    bounds = sfText_getGlobalBounds(global->current_quest.text);
    pos.x = margin;
    pos.y = margin;
    sfText_setPosition(global->current_quest.text, pos);
}

void init_quest(t_global *global)
{
    global->current_quest.text = NULL;
    global->current_quest.name = NULL;
    global->current_quest.description = NULL;
}

void change_quest(t_global *global, char *name, char *description)
{
    if (global->current_quest.text == NULL) {
        global->current_quest.text = sfText_create();
        global->current_quest.name = NULL;
        global->current_quest.description = NULL;
    }
    set_quest(global, name, description);
}

void display_quest(sfRenderWindow *window, t_global *global)
{
    if (global->current_quest.text != NULL)
        sfRenderWindow_drawText(window, global->current_quest.text, NULL);
}