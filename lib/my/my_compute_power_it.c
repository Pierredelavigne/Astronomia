/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** To the power of number and beyond
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p < 0)
        return (0);
    else if (p == 1)
        return (nb);
    else
        return (1);
    for (int count = 0; count < p-1; count++)
        result = result * nb;
    return (result);
}
