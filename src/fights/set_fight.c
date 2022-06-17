/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** set_fight for myrpg
*/

#include "my.h"

void draw_button(sfRenderWindow *window, t_global *global,
t_battle *battle)
{
    sfRenderWindow_drawRectangleShape(window, battle->attack, NULL);
    sfRenderWindow_drawRectangleShape(window, battle->weapon, NULL);
}

sfText *declare_damage_text(sfVector2f pos)
{
    sfText *description = sfText_create();
    sfFont *font = sfFont_createFromFile
    (path_font);
    sfText_setFont(description, font);
    sfText_setFillColor (description, sfBlack);
    sfText_setPosition(description, pos);

    return (description);
}

sfSprite *declare_background_fight(char *filename)
{
    sfSprite *bg_s = sfSprite_create();
    sfTexture *bg = sfTexture_createFromFile
    (filename, NULL);
    sfSprite_setTexture(bg_s, bg, sfTrue);
    return (bg_s);
}

void set_people(t_global *global)
{
    sfVector2f scale = {8, 8};
    sfVector2f scale_en = {5, 5};
    sfVector2f pos = {100, 500};
    sfVector2f pos_en = {1000, 140};
    sfTexture *text_enemy = sfTexture_createFromFile(
    "assets/character/enemy5.png", NULL);

    global->sprites.thief = sfSprite_create();
    sfSprite_setTexture(global->sprites.thief, text_enemy, sfTrue);
    sfSprite_setScale(global->sprites.hero, scale);
    sfSprite_setScale(global->sprites.thief, scale_en);
    global->sprites.hero = get_standing_char(sfKeyUp, global->sprites.hero,
    pos);
    global->sprites.thief = get_standing_char(sfKeyDown, global->sprites.thief,
    pos_en);
    declare_lp_fight(global);
    return ;
}

void draw_text_fight(sfRenderWindow *window, t_global *global)
{
    sfText_setString(global->texts.damage, str_append("DMG: ",
    nbr_to_str(get_weapon_damage(global))));
    sfText_setString(global->texts.hero_lv, str_append("Hero           lvl ",
    nbr_to_str(global->stats.level)));
    sfText_setString(global->texts.enemy_lv, "Mobius            lvl 3");
    sfRenderWindow_drawText(window, global->texts.damage, NULL);
    sfRenderWindow_drawText(window, global->texts.hero_lv, NULL);
    sfRenderWindow_drawText(window, global->texts.enemy_lv, NULL);
}