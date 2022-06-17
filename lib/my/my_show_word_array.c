/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** DIsplay the contentof an array of words
*/
#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str);

int my_arraylen(char * const *tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}

void print_those_number(int ac, char * const *av)
{
    int count = 0;
    for (int i = 0; i < ac; i++)
    {
        for (int j = 0; j < my_strlen(av[i]); j++)
        {
            my_putchar(av[i][j]);
            count++;
        }
        my_putchar('\n');
        count++;
    }
}

int  my_show_word_array(char * const *tab)
{
    int nb_of_words = my_arraylen(tab);
    print_those_number(nb_of_words, tab);
}
