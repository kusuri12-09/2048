//
// Created by user on 25. 5. 27.
//
#include "board.h"
#include "move.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>


void init_board(Board board) {
    srand(time(NULL));

    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void spawn_tile(Board board) {
    // 1. 빈칸 좌표 수집
    int emptyTile[BOARD_SIZE*BOARD_SIZE][2];
    int count = 0;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                emptyTile[count][0] = i;
                emptyTile[count][1] = j;
                count++;
            }
        }
    }
    if (count == 0) return;

    // 2. 빈칸 중 랜덤 선택
    int index = rand() % count;
    int row = emptyTile[index][0];
    int col = emptyTile[index][1];

    // 3. 90% 확률로 2, 10% 확률로 4
    board[row][col] = (rand() % 10 == 0) ? 4 : 2;
}

void print_board(const Board board) {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            printf("%5d", board[i][j]);
        }
        printf("\n\n");
    }
}

int is_game_over(const Board board) {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 0;
}

// void print_board(const Board board) {
//     char buffer[1024] = "";  // 충분히 큰 버퍼
//     char line[64];
//
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         line[0] = '\0'; // 라인 초기화
//         for (int j = 0; j < BOARD_SIZE; j++) {
//             char tile[16];
//             sprintf(tile, "\t%d", board[i][j]);
//             strcat(line, tile);
//         }
//         strcat(line, "\n\n"); // 줄 간격 2줄로 줄이기
//         strcat(buffer, line);
//     }
//
//     printf("%s", buffer); // 한번에 출력
// }  //지피티가 만들어준 버퍼로 문자열 모아서 한번에 출력하는 방법