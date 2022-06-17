/*
** EPITECH PROJECT, 2020
**  my_compute_square_root
** File description:
** Compute a square root operation
*/

int  my_compute_square_root(int nb)
{
    int i = 0;
    for (i = 0; i * i != nb; i++)
    {
        if (i*i > nb)
            return (0);
    }
    return (i);
}
