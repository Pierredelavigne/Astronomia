/*
** EPITECH PROJECT, 2020
** my_putstr_error
** File description:
** Write in error
*/
#include <stdio.h>

// my_putchar_error is not standard, replacing its usage directly.
// If my_putchar_error was intended to be a public function of the lib,
// it should be declared in a header and its definition kept.
// For now, making my_putstr_error self-contained with stdio.

void my_putstr_error(char const *str) // Changed return type to void
{
    if (str) { // Added a null check
        fputs(str, stderr);
    }
}
