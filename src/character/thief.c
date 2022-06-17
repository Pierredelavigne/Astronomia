/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** thieves
*/

#include "my.h"

const char *thief = "assets/character/enemy5.png";
const char *thief_talk_path = "npc/thief.talk";
const char *thief_talk_path_before = "npc/thief_before.talk";
const char *thief_talk_path_after = "npc/thief_after.talk";
const sfVector2f spawn_thief = {1394, 630};

void create_npc_thief(t_global *global)
{
    global->sprites.thief = sfSprite_create();
    sfSprite_setTexture(global->sprites.thief,
    create_texture_from_path(thief), sfFalse);
    global->pos.thief.x = spawn_thief.x;
    global->pos.thief.y = spawn_thief.y;
    global->sprites.thief = get_standing_char(sfKeyDown,
    global->sprites.thief, global->pos.thief);
    global->clocks.thief = sfClock_create();
    global->talks.thief_before = load_talk(thief_talk_path_before);
    global->talks.thief = load_talk(thief_talk_path);
    global->talks.thief_after = load_talk(thief_talk_path_after);
    global->bools.in_thief_conv = 0;
}

void draw_thief(t_global *global, sfRenderWindow *window, sfKeyCode key)
{
    if (key == 0)
        global->sprites.thief = get_standing_char(key,
        global->sprites.thief, global->pos.thief);
    if (is_an_arrow_key(key))
        global->sprites.thief = get_walking_char(key,
        global->sprites.thief, global->pos.thief, global->clocks.hero);
    sfRenderWindow_drawSprite(window, global->sprites.thief, NULL);
}

sfVector2f move_npc(t_global *global, sfKeyCode key, sfVector2f pos)
{
    float to_move = sfTime_asSeconds(global->time_clock) * npc_speed;
    sfVector2f new_pos = {pos.x, pos.y};

    if (key == sfKeyUp)
        new_pos.y -= to_move;
    if (key == sfKeyDown)
        new_pos.y += to_move;
    if (key == sfKeyRight)
        new_pos.x += to_move;
    if (key == sfKeyLeft)
        new_pos.x -= to_move;
    if (trader_can_move(global, new_pos)) {
        pos.x = new_pos.x;
        pos.y = new_pos.y;
    }
    return (pos);
}

void handle_thief(sfRenderWindow *window, t_global *global)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime
    (global->clocks.trader));
    sfKeyCode mykey = 0;
    if (seconds < 3)
        mykey = sfKeyUp;
    if (seconds >= 6 && seconds < 9)
        mykey = sfKeyDown;
    if (seconds > 12)
        sfClock_restart(global->clocks.trader);
    if (global->bools.in_thief_conv != 0)
        sfRenderWindow_drawSprite(window, get_standing_char(sfKeyDown,
        global->sprites.thief, global->pos.thief), NULL);
    else {
        global->pos.thief = move_npc(global, mykey, global->pos.thief);
        draw_thief(global, window, mykey);
    }
}