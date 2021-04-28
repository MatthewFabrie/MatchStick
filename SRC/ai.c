/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

int shorten(ad_t *all)
{
    int x = all->matches[0];

    for (int i = 1; i < all->lines; i++) {
        x = x ^ all->matches[i];
    }
    return (x);
}

void anti_crash(ad_t *all)
{
    int x = 0;
    int line;

    srandom(time(NULL));
    while (!x) {
        line = (random() % all->lines);
        if (all->matches[line] != 0)
            x = 1;
    }
    rm_matches(all, (line + 1), 1);
}

void ai_play(ad_t *all)
{
    int x = 0;

    all->turn = 1;
    for (int i = 0; i < all->lines; i++) {
        for (int j = 0; j < all->matches[i] || j < all->max_nbr; j++) {
            all->matches[i] = all->matches[i] - j;
            x = shorten(all);
            all->matches[i] = all->matches [i] + j;
            if (x == 1 && j != 0) {
                rm_matches(all, (i + 1), j);
                return ;
            }
        }
    }
    anti_crash(all);
}

void shortener(ad_t *all, int line)
{
    all->worked = 1;
    all->turn = 2;
    rm_matches(all, line, all->nbr_matches);
}