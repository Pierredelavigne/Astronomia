/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** character of the string
*/
#include <stdio.h>

// Declaration of my_strlen if it's not in a common header from this lib
// int my_strlen(const char *str);
// It is declared in "my.h" which is likely included by files using my_putstr

void my_putstr(char const *str) // Changed return type to void to match common practice
{
    if (str) { // Added a null check
        fputs(str, stdout);
    }
}
