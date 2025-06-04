//
// Created by user on 25. 5. 27.
//

#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 4

typedef int Board[BOARD_SIZE][BOARD_SIZE];

void init_board(Board board);

void spawn_tile(Board board);

void print_board(const Board board);

int is_game_over(const Board board);

#endif //BOARD_H
