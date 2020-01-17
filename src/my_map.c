/*
** EPITECH PROJECT, 2020
** str_to_word_array.c
** File description:
** source file str split
*/

#include "../include/matchstick.h"

char **fill_with_matches(char **map, int length, int height, int len_map)
{
    int matches = length - 2;
    int i;
    int c;
    int offset = 1;

    for (int i = height; i != 0; i--) {
        for (int match = matches, j = offset; match > 0; match--, j++) {
            map[i][j] = '|';
        }
        matches -= 2;
        offset += 1;
    }
    return (map);
}

char **my_square(int number, int length)
{
    char **map = NULL;
    int len_map = 0;
    int height = (number + 2);
    int line = 0;
    int x = 0;
    int y = 0;
    len_map = length * (number + 2);
    map = malloc(sizeof(char *) * (len_map + 1));

    while (line < height) {
        map[line] = malloc(sizeof(char) * (length));
        while (y != length) {
            if (y > 0 && y < length - 1 && line != 0 && line != height - 1 ) {
                map[line][y] = ' ';
                y++;
            } else {
                map[line][y] = '*';
                y++;
            }
        }
        map[line][y] = '\0';
        line += 1;
        y = 0;
    }
    map[len_map] = NULL;
    map = fill_with_matches(map, length, number, len_map);
    return map;
}