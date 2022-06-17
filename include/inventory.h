/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** inventory
*/
#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "my.h"
#include <stdlib.h>

// Struct for the inventory
typedef struct inventory_s {
    char *name;
    char *filename;
    char *type;
    char *description;
    int damage;
    int main;
    int have;
    int id;
    struct inventory_s *next;
} inventory_t;

inventory_t *create_inventory(char **data, int damage, int main, int id);

inventory_t *add_to_list(inventory_t *head, inventory_t *new_item);

inventory_t *add_to_list_between(inventory_t *before,
inventory_t *new_item, inventory_t *after);

void delete_to_list_between(inventory_t *before,
inventory_t *new_item, inventory_t *after);

void delete_to_list(inventory_t *before, inventory_t *new_item);

void print_inventory(inventory_t *head);

sfText *declare_text(void);

sfVector2f set_position(sfVector2f position);

sfSprite *set_sprite_bg(void);

#endif /* !INVENTORY_H_ */
