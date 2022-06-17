/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** trader
*/

#include "my.h"

const char *trader_path = "assets/character/trader.png";
const char *trader_talk_path = "npc/trader.talk";
const char *trader_talk_path_after = "npc/trader_after.talk";
const sfVector2f spawn_trader = {600, 300};
const float npc_speed = 50;

void create_npc_trader(t_global *global)
{
    global->sprites.trader = sfSprite_create();
    sfSprite_setTexture(global->sprites.trader,
    create_texture_from_path(trader_path), sfFalse);
    global->pos.trader.x = spawn_trader.x;
    global->pos.trader.y = spawn_trader.y;
    global->sprites.trader = get_standing_char(sfKeyDown,
    global->sprites.trader, global->pos.trader);
    global->clocks.trader = sfClock_create();
    global->talks.trader = load_talk(trader_talk_path);
    global->talks.trader_after = load_talk(trader_talk_path_after);
}

void draw_trader(t_global *global, sfRenderWindow *window, sfKeyCode key)
{
    if (key == 0)
        global->sprites.trader = get_standing_char(key,
        global->sprites.trader, global->pos.trader);
    if (is_an_arrow_key(key))
        global->sprites.trader = get_walking_char(key,
        global->sprites.trader, global->pos.trader, global->clocks.hero);
    sfRenderWindow_drawSprite(window, global->sprites.trader, NULL);
}

int trader_can_move(t_global *global, sfVector2f new_pos)
{
    for (int i = 0; global->blocks_map[i].sprite != NULL; i++)
        if (global->blocks_map[i].colisable == sfTrue &&
        block_touches_entity(new_pos, global->blocks_map[i].pos))
            return (0);
    if (block_touches_entity(new_pos, global->pos.hero))
        return (0);
    return (1);
}

void move_trader(t_global *global, sfKeyCode key)
{
    float to_move = sfTime_asSeconds(global->time_clock) * npc_speed;
    sfVector2f new_pos = {global->pos.trader.x, global->pos.trader.y};

    if (key == sfKeyUp)
        new_pos.y -= to_move;
    if (key == sfKeyDown)
        new_pos.y += to_move;
    if (key == sfKeyRight)
        new_pos.x += to_move;
    if (key == sfKeyLeft)
        new_pos.x -= to_move;
    if (trader_can_move(global, new_pos)) {
        global->pos.trader.x = new_pos.x;
        global->pos.trader.y = new_pos.y;
    }
}

void handle_trader(sfRenderWindow *window, t_global *global)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime
    (global->clocks.trader));
    sfKeyCode mykey = 0;
    if (seconds < 3)
        mykey = sfKeyLeft;
    if (seconds >= 6 && seconds < 9)
        mykey = sfKeyRight;
    if (seconds > 12)
        sfClock_restart(global->clocks.trader);
    if (global->bools.in_trader_conv != 0)
        sfRenderWindow_drawSprite(window, get_standing_char(sfKeyDown,
        global->sprites.trader, global->pos.trader), NULL);
    else {
        move_trader(global, mykey);
        draw_trader(global, window, mykey);
    }
}