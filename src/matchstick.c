/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick main file
*/

#include "../include/matchstick.h"

/* read, write, malloc, free, time, getpid, random, srandom, getline */

void my_remove(matchstick_t match, int line, int matches)
{
    int i = 0;
    int j = 0;

    while (match->map[line][i] != '|') {
        i++;
    }
    j = i;
    while (match->map[line][j + 1] == '|') {
        j++;
    }
    while (matches != 0) {
        if (match->map[line][j] == '|') {
            match->map[line][j] = ' ';
            j--;
            matches--;
        }
    }
}

void ai_turn(matchstick_t match)
{
    int line;
    int matche;
    srand(time(NULL));

    if (how_many_matches(match) == 0) {
        match->ia_lose = 0;
        return;
    }
    my_printf("\nAI's turn...\n");
    line = rand() % (match->numb_lines + 1 - 1) + 1;
    while (how_many_matches_line(match, line) == 0)
        line = rand() % (match->numb_lines + 1 - 1) + 1;
    matche = rand() % (how_many_matches_line(match, line) + 1 - 1) + 1;
    while (matche > match->offset)
        matche = rand() % (how_many_matches_line(match, line) + 1 - 1) + 1;
    my_printf("AI removed %d match(es) from line %d\n", matche, line);
    my_remove(match, line, matche);
    match->match_left -= matche;
    if (how_many_matches(match) == 0)
        match->ia_lose = 1;
}

void game(matchstick_t match)
{
    int matches = 0;
    match->ia_lose = 3;
    match->match_left = how_many_matches(match);

    display_map(match->map);
    while (match->match_left > 0) {
        if (input(match) == -1)
            return;
        display_map(match->map);
        ai_turn(match);
        if (match->ia_lose == 0) {
            my_printf("You lost, too bad...\n");
            return;
        }
        display_map(match->map);
    }
    if (match->ia_lose == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    matchstick_t match = malloc(sizeof(*match));
    match->numb_lines = my_getnbr(av[1]);
    match->offset = my_getnbr(av[2]);
    if (match->numb_lines < 2 || match->numb_lines > 99)
        return (84);
    match->len_line = (match->numb_lines * 2 + 1);
    match->len_map = match->len_line * (match->numb_lines + 2);
    match->height = (match->numb_lines + 2);
    my_square(match);
    game(match);
    if (match->ia_lose == 1) {
        return (1);
    } else if (match->ia_lose == 0) {
        return (2);
    }
    return (0);
}