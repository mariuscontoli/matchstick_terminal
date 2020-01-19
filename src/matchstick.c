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
    if (how_many_matches(match) == 0) {
        my_printf("You lost, too bad...\n");
        return;
    }
    my_printf("AI's turn...\n");


}

void game(matchstick_t match)
{
    int matches = 0;
    match->match_left = how_many_matches(match);
    
    display_map(match->map);
    while (match->match_left > 0) {
        input(match);
        display_map(match->map);
        //ai_turn(match);
        //display_map(match->map);
    }
}

int main(int ac, char **av)
{
    matchstick_t match = malloc(sizeof(*match));
    match->numb_lines = my_getnbr(av[1]);
    match->offset = my_getnbr(av[2]);
    match->len_line = (match->numb_lines * 2 + 1);
    match->len_map = match->len_line * (match->numb_lines + 2);
    match->height = (match->numb_lines + 2);
    my_square(match);

    if (ac != 3)
        return (84);
    game(match);
    return 0;
}