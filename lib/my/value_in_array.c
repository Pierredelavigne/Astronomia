/*
** EPITECH PROJECT, 2020
** value_in_array.c
** File description:
** Returns 1 if value is in a given array
*/

int value_in_array(char *array, char c)
{
    int i;
    for (i = 0; i < sizeof(array); i++){
        if (array[i] == c)
            return (1);
    }
    return (0);
}