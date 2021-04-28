/*
** EPITECH PROJECT, 2021
** main
** File description:
** matchstick main
*/

#include "../include/my.h"

void print_bottom(int width)
{
    for (int p = 0; p < width; p++)
        my_putchar('*');
    my_putchar('\n');
}

void print_board(ad_t *all)
{
    int width = (2 * all->lines) - 1;
    int spaces;

    for (int i = 0; i < (width + 2); i++)
        my_putchar('*');
    my_putchar('\n');
    for (int j = 0; j < all->lines; j++) {
        spaces = (width - ((2 * j) + 1)) / 2;
        my_putchar('*');
        for (int x = 0; x < spaces; x++)
            my_putchar(' ');
        for (int y = 0; y < all->matches[j]; y++)
            my_putchar('|');
        spaces = width - spaces - all->matches[j];
        for (int s = 0; s < spaces; s++)
            my_putchar(' ');
        my_putstr("*\n");
    }
    print_bottom(width + 2);
}

void ini_map(ad_t *all, char **argv)
{
    all->lines = my_getnbr(argv[1]);
    all->max_nbr = my_getnbr(argv[2]);
    all->worked = 1;
    all->turn = 1;
    all->matches = malloc(sizeof(int) * all->lines);
    if (!all->matches) {
        all->worked = 0;
        return;
    }
    for (int i = 0; i < all->lines; i++)
        all->matches[i] = (2 * i) + 1;
}

int main(int argc, char **argv)
{
    ad_t *all = malloc(sizeof(ad_t));
    int ret = 0;

    if (argc != 3)
        return (84);
    if (my_getnbr(argv[1]) > 100)
        return (84);
    ini_map(all, argv);
    print_board(all);
    ret = matchstick(all);
    return (ret);
}