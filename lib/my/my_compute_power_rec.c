/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** To the power of number and beyond (recursively).
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p < 0)
    {
        return (0);
    }
    if (p == 0)
    {
        return (1);
    }
    result = result * my_compute_power_rec(result, p-1);
    return (result);
}
