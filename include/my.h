/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "inventory.h"
#include "fight.h"
#include "scenes.h"

//STRUCUTURES

// Map block structure
typedef struct
{
    sfSprite *sprite;
    sfVector2f pos;
    sfBool colisable;
} t_map_block;

// Struct storing sprites
typedef struct
{
    sfSprite    *background;
    sfSprite    *menu_background;
    sfSprite    *hero;
    sfSprite    *enemy;
    sfSprite    *trader;
    sfSprite    *thief;
    sfSprite    *saber;
    sfSprite    *blade;
    sfSprite    *fuel;
    sfSprite    *cinematic_spaceship;
    sfSprite    *cinematic_bg;
    sfSprite    *cinematic_planet;
    sfSprite    *cinematic_planet_two;
    sfSprite    *cinematic_enemy;
    sfSprite    *cinematic_fire;
    sfSprite    *end_cinematic_trader;
    sfSprite    *end_cinematic_spaceship;
    sfSprite    *end_cinematic_hero;
    sfSprite    *bg_end;
} t_sprite;

typedef struct texts
{
    sfText *text_cinematic_up;
    sfText *text_cinematic_middle;
    sfText *text_cinematic_down;
    sfText *text_first_trader;
    sfText *text_second_trader;
    sfText *text_third_trader;
    sfText *how_to_play_text;
    sfText *damage;
    sfText *hero_lv;
    sfText *enemy_lv;
    sfText *end;
} t_texts;

// Struct to store map sprites
typedef struct
{
    sfSprite    *grass;
    sfSprite    *dirt;
    sfSprite    *water;
    sfSprite    *wall;
} t_map_sprites;

// Struct to store map textures
typedef struct
{
    sfTexture *main_texture;
} t_map_texture;

typedef struct hero_stats
{
    int level;
    float strength;
    int lp;
    int lp_max;
} t_hero_stats;

typedef struct enemy_stats
{
    int level;
    float strength;
    float lp;
    float lp_max;
} t_enemy_stats;

// Struct to store textures
typedef struct
{
    sfTexture *hero_texture;
} t_textures;

// Struct where boolean are store
typedef struct bool
{
    int menu_open;
    int exit;
    int default_scene;
    int skip_cinematic;
    int in_trader_conv;
    int in_thief_conv;
    int fire_sound;
    int exit_menu;
} t_bool;

//Storing positions
typedef struct pos
{
    sfVector2f hero;
    sfVector2f trader;
    sfVector2f thief;
    sfVector2f saber;
    sfVector2f blade;
    sfVector2f trader_end;
    sfVector2f hero_end;
    sfVector2f spaceship_end;
} t_positions;

//Storing clocks
typedef struct clock
{
    sfClock *hero;
    sfClock *cinematic;
    sfClock *end_cinematic;
    sfClock *fire_cinematic;
    sfClock *trader;
    sfClock *thief;
    sfClock *enemy;
    sfClock *win;
} t_clock;

typedef struct cinematic
{
    float enemy_x;
    float scale;
    float angle;
    int fire_animation;
    sfVector2f pos_fire;
} t_cinematic;

typedef struct npc
{
    sfVector2f pos;
    sfSprite *sprite;
} t_npc;

typedef struct talk
{
    sfText  **trader;
    sfText  **trader_after;
    sfText  **thief_before;
    sfText  **thief;
    sfText  **thief_after;
} t_talk;

typedef struct quest
{
    char *name;
    char *description;
    sfText  *text;
} t_quest;

typedef struct musics
{
    sfMusic *cinematic;
    sfMusic *main_menu_red_carpet;
    sfMusic *end;
} t_musics;

typedef struct sounds
{
    sfSound *cinmatic_enemy_fire;
} t_sounds;

typedef struct lp {
    sfRectangleShape *full;
    sfRectangleShape *lp;
} t_lp;

// Struct where everything is stored
typedef struct gl
{
    int current_scene;
    t_sounds sounds;
    sfText *text_to_draw;
    t_talk talks;
    t_cinematic cinematic;
    sfEvent event;
    t_map_sprites map_sprites;
    t_map_texture map_textures;
    t_textures textures;
    t_sprite sprites;
    sfTime time_clock;
    sfClock *clock;
    t_bool bools;
    t_map_block *blocks_map;
    inventory_t *inventory;
    sfKeyCode key_holding;
    sfKeyCode character_facing;
    t_positions pos;
    t_clock clocks;
    sfText *text;
    sfText *stats_text;
    sfFont *font;
    int dialogue;
    int dialogue2;
    int dialogue3;
    int guide;
    t_hero_stats stats;
    t_enemy_stats en_stats;
    t_texts texts;
    t_quest current_quest;
    t_musics musics;
    int win;
    t_lp lp_hero;
    t_lp lp_enemy;
    float fade_value;
} t_global;

//LIB FUNCTIONS

void my_putstr(char *str);

void my_putstr_error(char *str);

char *str_append(char *str, const char *str2);

int my_strlen(char const *str);

int my_getnbr(char *str);

char *my_strdup(char const *str);

int my_strcmp(const char *string_one, const char *string_two);

int str_compare(const char *string_one, const char *string_two);

char *nbr_to_str(int nb);

//GAME FUNCTIONS

int start_game(t_global *global);

void clean(sfRenderWindow *window, t_global *global);

void handle_loop_main_menu(sfRenderWindow *window, t_global *global);

sfRenderWindow *create_window(void);

void load_map(t_global *global);

void handle_loop_main_scene(sfRenderWindow *window, t_global *global);

void handle_loop_inventory(sfRenderWindow *window, t_global *global);

int mouse_touches_sprite(sfVector2i mouse, sfSprite *sprite);

void loop_fight(sfRenderWindow *window, t_global *global);

sfTexture *create_texture_from_path(const char *line);

void create_character_textures(t_global *global);

sfSprite *get_standing_char(sfKeyCode code, sfSprite *sprite,
sfVector2f position);

void draw_hero(t_global *global, sfRenderWindow *window);

int is_an_arrow_key(sfKeyCode code);

void draw_walking_hero(sfRenderWindow *window, t_global *global,
sfKeyCode code);

int hero_can_move(t_global *global, sfVector2f new_pos);

void move_hero(t_global *global);

char *draw_inventory(sfRenderWindow *window, t_global *global);

int get_weapon_damage(t_global *global);

sfSprite *get_weapon_main_sprite(t_global *global);

int is_weapon_in_inventory(t_global *global, int id);

sfTexture **load_texture(t_global *global);

void handle_loop_cinematic(sfRenderWindow *window, t_global *global);

void events_cinematic(sfRenderWindow *window, t_global *global);

void draw_cinematic(sfRenderWindow *window, t_global *global);

sfSprite *set_zooming_out(sfSprite *sprite,
sfVector2f position, t_global *global);

sfSprite *set_zooming_out(sfSprite *sprite,
sfVector2f position, t_global *global);

void init_level_text(t_global *global);

void set_level_text(t_global *global, const char *string);

void display_stats(sfRenderWindow *window, t_global *global);

char *my_strcat(char *str1, char const *str2);

sfSprite *set_enemy_ship(sfSprite *sprite, t_global *global, float speed);

sfSprite *set_fire(sfSprite *sprite, t_global *global);

void create_texts_cinematic(t_global *global);

void draw_texts_cinematic(sfRenderWindow *window, t_global *global);

void free_cinematic(t_global *global);

sfSprite *set_spaceship(sfSprite *sprite,
sfVector2f position);

sfSprite *set_bg(sfSprite *sprite, t_global *global);

sfSprite *get_first_planet(sfSprite *sprite, t_global *global);

void create_npc_trader(t_global *global);

void draw_npc(sfRenderWindow *window, t_global *global);

void handle_moving_clock(t_global *global);

sfSprite *get_walking_char(sfKeyCode code, sfSprite *sprite,
sfVector2f position, sfClock *clock);

int block_touches_entity(sfVector2f entity_pos, sfVector2f block_pos);

void handle_trader(sfRenderWindow *window, t_global *global);

void draw_standing_hero(sfRenderWindow *window, t_global *global,
sfKeyCode code);

void create_main_scene(t_global *global);

void declare_lp_fight( t_global *global);

void move_all_blocks(t_global *global, float to_move, sfKeyCode key);

void move_it_all(t_global *global, float to_move, sfKeyCode key);

int is_in_range(sfVector2f pos_first, sfVector2f pos_second, float range);

void set_stat_player(t_global *global);

void draw_button(sfRenderWindow *window, t_global *global,
t_battle *battle);

void set_people(t_global *global);

void draw_text_fight(sfRenderWindow *window, t_global *global);

sfText **load_talk(char const *path);

int draw_fight_inventory(sfRenderWindow *window, t_global *global);

void choose_weapon(sfRenderWindow *window, t_global *global, t_battle *battle);

void analyse_fight_mouse_event(sfRenderWindow *window,
t_global *global, t_battle *battle);

void draw_dialogues_trader(sfRenderWindow *window, t_global *global);

void interactions(t_global *global);

void free_main_scene(t_global *global);

void draw_main_scene(sfRenderWindow *window, t_global *global);

void init_quest(t_global *global);

void display_quest(sfRenderWindow *window, t_global *global);

void change_quest(t_global *global, char *name, char *description);

void create_and_start_cinematic_music(t_global *global);

void stop_and_destroy_cinematic_music(t_global *global);

int trader_can_move(t_global *global, sfVector2f new_pos);

void create_npc_thief(t_global *global);

void handle_thief(sfRenderWindow *window, t_global *global);

void create_and_start_main_music(t_global *global);

void stop_and_destroy_main_music(t_global *global);

void interaction_thief(sfRenderWindow *window, t_global *global);

void attack_enemy(sfRenderWindow *window, t_global *global, t_battle *battle);

void clock_manage(sfRenderWindow *window, t_global *global, t_battle *battle);

sfText *set_stats(t_global *global);

sfSprite *set_weapon(const char *filename, int x, int y, sfVector2f *pos);

void update_inventory(sfRenderWindow *window, t_global *global, int id);

void set_main_to_zero(t_global *global);

void win_animation(sfRenderWindow *window, t_global *global);

void set_fuel_and_text(t_global *global);

void check_victory(sfRenderWindow *window, t_global *global, sfMusic **music);

void unset_fight(t_global *global, t_battle *battle,
sfMusic **music, sfSprite *bg_s);

void game_over_scene(sfRenderWindow *window, t_global *global);

void loop_pause_scene(sfRenderWindow *window, t_global *global);

int manage_pause_mouse_click(sfRenderWindow *window,
t_global *global, sfRectangleShape **button, sfMusic *music);

int analyse_pause_events(sfRenderWindow* window, t_global *global,
sfRectangleShape **button, sfMusic *music);

int manage_menu_mouse_click(sfRenderWindow *window,
t_global *global, sfRectangleShape **button, sfMusic *music);

int analyse_menu_events(sfRenderWindow* window, t_global *global,
sfRectangleShape **button, sfMusic *music);

void loop_menu_scene(sfRenderWindow *window, t_global *global);

void loop_htp_scene(sfRenderWindow *window, t_global *global);

void inventory_create(t_global *global);

void init_variables(t_global *global);

void draw_people_fight(sfRenderWindow *window, t_global *global);

void set_button(t_battle *battle);

void draw_snow(sfRenderWindow *window, t_global *global,
sfRectangleShape **snow, sfClock *clock);

sfRectangleShape **declare_snow_particle(t_global *global);
void init_fight(t_global *global);

void handle_loop_end_cinematic(sfRenderWindow *window, t_global *global);

sfVector2f move_entity_end(t_global *global,
sfVector2f current_pos, sfKeyCode key);

void draw_end_cinematic(sfRenderWindow *window, t_global *global);

void set_end_cinematic(t_global *global);


//global variables

extern const int width;

extern const int height;

extern const float margin;

extern const char *path_font;

extern const float npc_speed;

extern const char *spaceship_path;

extern const char *trader_path;

extern const char *hero_path;

extern const float hero_speed;

extern const char *font_it;

#endif /* !MY_H_ */