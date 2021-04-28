/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

int get_input(void)
{
    char *str = malloc(sizeof(char) * 1024);
    size_t line;
    int lines;

    my_putstr("Line: ");
    if (getline(&str, &line, stdin) == -1)
        return (-3);
    if (!str)
        return (-2);
    lines = my_getnbr(str);
    return (lines);
}

int get_matches(void)
{
    char *str = malloc(sizeof(char) * 1024);
    size_t match;
    int matches;

    my_putstr("Matches: ");
    if (getline(&str, &match, stdin) == -1)
        return (-3);
    if (!str)
        return (-2);
    matches = my_getnbr(str);
    return (matches);
}

void check_line(ad_t *all, int line)
{
    if (line == 0 || line > all->lines) {
        my_putstr("Error: this line is out of range\n");
        all->worked = 0;
        return;
    } else if (line < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        all->worked = 0;
        return;
    }
}

int get_turn(ad_t *all)
{
    if (all->worked == 0)
        all->worked = 1;
    all->line = get_input();
    if (all->line == -2)
        return (-2);
    if (all->line == -3)
        return (-3);
    check_line(all, all->line);
    if (all->worked == 0)
        return (-1);
    all->nbr_matches = get_matches();
    if (all->nbr_matches == -3)
        return (-3);
    if (all->nbr_matches == -2)
        return (-2);
    check_match(all, all->nbr_matches, all->line);
    if (all->worked == 0)
        return (1);
    shortener(all, all->line);
    return (0);
}

int matchstick(ad_t *all)
{
    int end = 0;
    int player_turn = 0;

    while (player_turn != -2 && !end) {
        if (!all->worked) {
            player_turn = get_turn(all);
            if (player_turn == -3)
                return (0);
        } else if (all->turn == 1) {
            my_putstr("\nYour turn:\n");
            player_turn = get_turn(all);
            if (player_turn == -3)
                return (0);
        } else {
            my_putstr("\nAI's turn...\n");
            ai_play(all);
        }
        end = win(all);
    }
    return ((player_turn == (-2)) ? 0 : print_win(all));
}