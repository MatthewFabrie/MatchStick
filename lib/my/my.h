/*
** EPITECH PROJECT, 2020
** my h header
** File description:
** this file cointains all file prototypes
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct ad_s {
    int max_nbr;
    int lines;
    int *matches;
    int worked;
    int turn;
    int nbr_matches;
    int line;
}ad_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **my_str_to_word_array(const char *str, const char *separator);
int my_strcmp(char const *s1, char const *s2);
int matchstick(ad_t *all);
void check_match(ad_t *all, int matches, int line);
void rm_matches(ad_t *all, int lines, int matches);
void print_board(ad_t *all);
void ai_play(ad_t *all);
int win(ad_t *all);
int print_win(ad_t *all);
void shortener(ad_t *all, int line);