/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** interactions
*/

#include "my.h"
#include "map.h"

const int char_max = 100;
sfVector2f text_pos = {10, 520};

sfText *create_text_interaction(char const *text)
{
    sfText *mytext = sfText_create();
    sfVector2f my_vector;
    int size = 82 - (my_strlen(text) * 0.7);

    sfText_setFont(mytext, sfFont_createFromFile(path_font));
    sfText_setOutlineColor(mytext, sfColor_fromRGB(0, 0, 0));
    sfText_setOutlineThickness(mytext, size * 0.05);
    sfText_setFillColor(mytext, sfColor_fromRGB(255, 255, 255));
    sfText_setCharacterSize(mytext, size);
    sfText_setString(mytext, text);
    my_vector.x = width / 2 - (sfText_getGlobalBounds(mytext).width / 2);
    my_vector.y = 600;
    sfText_setPosition(mytext, my_vector);
    return (mytext);
}

sfText **load_talk(char const *path)
{
    char *line = NULL;
    sfText **result;
    int line_nb = 0;
    FILE *stream = test_stream(path);
    size_t len = 0;
    size_t nread;

    while ((nread = getline(&line, &len, stream)) != -1) {
        line = fix_line(line);
        if (line_nb == 0)
            result = malloc(sizeof(sfText *) * (my_getnbr(line) + 1) );
        else
            result[line_nb- 1] = create_text_interaction(line);
        line_nb++;
    }
    result[line_nb - 1] = NULL;
    fclose(stream);
    return (result);
}

void interactions(t_global *global)
{
    global->bools.in_trader_conv += 1;
    if (str_compare(global->current_quest.name, "Beat the Thief")) {
        global->text_to_draw =
        global->talks.trader_after[global->bools.in_trader_conv - 1];
    }
    if (global->bools.in_trader_conv != 0 &&
    global->talks.trader[global->bools.in_trader_conv - 1] == NULL) {
        global->bools.in_trader_conv = 0;
        global->text_to_draw = NULL;
        change_quest(global, "Beat the Thief",
        "Beat the thieves to gather propulsor fuel");
    }
    if (global->bools.in_trader_conv != 0) {
        global->text_to_draw =
        global->talks.trader[global->bools.in_trader_conv - 1];
    }
}

void after_talk(sfRenderWindow *window, t_global *global)
{
    if (global->bools.in_thief_conv != 0 &&
    global->talks.thief[global->bools.in_thief_conv - 1] == NULL) {
        global->current_scene = 3;
        global->bools.in_thief_conv = 0;
        global->text_to_draw = NULL;
    }
    if (global->bools.in_thief_conv != 0) {
        global->text_to_draw =
        global->talks.thief[global->bools.in_thief_conv - 1];
    }
}

void interaction_thief(sfRenderWindow *window, t_global *global)
{
    global->bools.in_thief_conv += 1;
    if (str_compare(global->current_quest.name, "Beat the Thief"))
        after_talk(window, global);
    else {
        if (global->bools.in_thief_conv != 0 &&
            global->talks.thief_before[global->bools.in_thief_conv - 1]
            == NULL) {
            global->bools.in_thief_conv = 0;
            global->text_to_draw = NULL;
        }
        if (global->bools.in_thief_conv != 0) {
            global->text_to_draw =
            global->talks.thief_before[global->bools.in_thief_conv - 1];
        }
    }
}