/*
** EPITECH PROJECT, 2021
** linked_list_tools.s
** File description:
** tools for linked list in inventory
*/

#include "my.h"
#include "inventory.h"

inventory_t *create_inventory(char **data, int damage, int main, int id)
{
    inventory_t *new = malloc(sizeof(inventory_t));
    if (new == NULL)
        return (NULL);
    new->name = data[0];
    new->filename = data[1];
    new->type = data[2];
    new->description = data[3];
    new->damage = damage;
    new->main = main;
    new->next = NULL;
    new->have = 0;
    new->id = id;
    return (new);
}

inventory_t *add_to_list(inventory_t *inventory, inventory_t *new_item)
{
    while (inventory->next != NULL)
        inventory = inventory->next;
    inventory->next = new_item;
    new_item->next = NULL;
    return (new_item);
}

inventory_t *add_to_list_between(inventory_t *before,
inventory_t *new_item, inventory_t *after)
{
    before->next = new_item;
    new_item->next = after;
    return (new_item);
}

void delete_to_list_between(inventory_t *before,
inventory_t *new_item, inventory_t *after)
{
    before->next = after;
    new_item->next = NULL;
    free(new_item);
    return;
}

void delete_to_list(inventory_t *before, inventory_t *new_item)
{
    before->next = NULL;
    free(new_item);
    return;
}