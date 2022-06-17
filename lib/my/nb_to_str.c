/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** nb_to_str for myrpg
*/

char *str_append(char const *original, char const *to_append);

char *char_to_end_of_str(char *str, char c);

char *nbr_to_str(int nb)
{
    char *result = "";
    if (nb < 0) {
        result = str_append(result, "-");
        nb = nb * (-1);
    }
    if (nb >= 10) {
        result = str_append(result, nbr_to_str(nb / 10));
        result = char_to_end_of_str(result, (nb % 10) + 48);
    }
    else {
        result = char_to_end_of_str(result, nb + 48);
    }
}