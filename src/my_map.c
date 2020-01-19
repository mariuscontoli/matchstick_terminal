/*
** EPITECH PROJECT, 2020
** str_to_word_array.c
** File description:
** source file str split
*/

#include "../include/matchstick.h"

void fill_with_matches(matchstick_t match)
{
    int matches = match->len_line - 2;
    int i;
    int c;
    int offset = 1;

    for (int i = match->numb_lines; i != 0; i--) {
        for (int matcho = matches, j = offset; matcho > 0; matcho--, j++) {
            match->map[i][j] = '|';
        }
        matches -= 2;
        offset += 1;
    }
}

void my_square(matchstick_t match)
{
    int height = (match->numb_lines + 2);
    int line = 0;
    int x = 0;
    int y = 0;
    match->map = malloc(sizeof(char *) * (match->len_map + 1));

    while (line < height) {
        match->map[line] = malloc(sizeof(char) * (match->len_line));
        while (y != match->len_line) {
            if (y > 0 && y < match->len_line - 1 && line != 0 &&
            line != height - 1 ) {
                match->map[line][y] = ' ';
                y++;
            } else {
                match->map[line][y] = '*';
                y++;
            }
        }
        match->map[line][y] = '\0';
        line += 1;
        y = 0;
    }
    match->map[match->len_map] = NULL;
    fill_with_matches(match);
}