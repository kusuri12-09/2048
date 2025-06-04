#include <stdio.h>
#include "board.h"
#include "move.h"
#include "clearScreen.h"

int main(void) {
    Board board;
    init_board(board);

    int moved = 1;

    while (1) {
        if (moved) {

            spawn_tile(board);

            clearScreen();
            print_board(board);

            if (is_game_over(board)) {
                clearScreen();
                printf("Game Over!\n\n");
                print_board(board);

                break;
            }
        }

        switch (getMoveInput()) {
            case 'w':
            case 'W':
                moved = moveUp(board);
                break;
            case 's':
            case 'S':
                moved = moveDown(board);
                break;
            case 'a':
            case 'A':
                moved = moveLeft(board);
                break;
            case 'd':
            case 'D':
                moved = moveRight(board);
                break;
            default:
                moved = 0;
                continue;
        }
    }
}

// WASD 키 눌렀을 때 합쳐진 숫자가 없는데도 숫자 생성, 예외처리 필요
// -> move 함수들의 반환타입 int로 변경, 값이 원본과 바뀌었는지 비교하고 어떠한 이동/변환도 없었다면 spawn_tile을 건너뛰도록 변경
// 함수로 빼놨던 switch문을 main 내로 변경, spawn_tile() 함수를 위쪽에 배치하여 먼저 실행
// 하는김에 is_game_over() 함수도 사용
// moved 변수의 초깃값을 1로 지정
// 근데 ㅅㅂ 이것때문에 moved 값이 계속 1로 고정되는 상황 발생
// 그래서 while문 밖으로 뺌 -> 그래도 안됨 -> 정신이나감
// 왜 moveUp() 호출이 두번이나 되있는거야

// WASD 말고 다른 키 눌렀을 때 예외처리 필요 : input_board() 함수로 해결
// 하지만 continue;를 쓰면 되는 일이엇고... 그렇게 함수는 사라졋다

// 출력 오래걸림
// clearScreen 함수 만듦 (뭔지 모르겟어서 걍 지피티 돌림)0
