/*
** EPITECH PROJECT, 2020
** my_putstr_error
** File description:
** Write in error
*/
#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int  my_putstr_error(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
}
