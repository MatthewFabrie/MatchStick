/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

void check_match(ad_t *all, int matches, int line)
{
    if (matches > all->max_nbr) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(all->max_nbr);
        my_putstr(" matches per turn\n");
        all->worked = 0;
        return;
    } else if (matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        all->worked = 0;
        return;
    }
    if (matches < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        all->worked = 0;
        return;
    } else if (matches > all->matches[line - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        all->worked = 0;
        return;
    }
}

void rm_matches(ad_t *all, int lines, int matches)
{
    if (all->turn != 1)
        my_putstr("Player ");
    else
        my_putstr("AI ");
    if (matches > all->max_nbr)
        matches = all->max_nbr;
    if (matches > all->matches[lines - 1])
        matches = all->matches[lines - 1];
    all->matches[lines - 1] = all->matches[lines - 1] - matches;
    my_putstr("removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(lines);
    my_putchar('\n');
    print_board(all);
}

int print_win(ad_t *all)
{
    if (all->turn == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
}

int win(ad_t *all)
{
    for (int i = 0; i < all->lines; i++) {
        if (all->matches[i] != 0)
            return (0);
    }
    return (1);
}