//
// Created by user on 25. 5. 27.
//
#include <conio.h>
#include "board.h"
#include "move.h"

char getMoveInput() {
    char input = getch();
    return input;  // 입력 즉시 문자 반환 (엔터 필요 없음)
}

int moveUp(Board board) {
    int changed = 0;

    for (int col = 0; col < BOARD_SIZE; col++) {
        int temp[BOARD_SIZE] = {0};
        int index = 0;

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        int ori[BOARD_SIZE] = {0};
        for (int i = 0; i < BOARD_SIZE; i++) {
            ori[i] = board[i][col]; // 원본 복사
        }

        // 1. 첫번째 열부터 0이 아닌 값 추출
        for (int row = 0; row < BOARD_SIZE; row++) {
             if (board[row][col] != 0) {  // 0이 아닐 때
                temp[index++] = board[row][col];  // temp[index]에 col번째 row의 값을 받아들임
            }
        }

        // 2. 추출한 값 중에서 같은 숫자끼리 합치기
        for (int i = 0; i < index-1; i++) {  // 만약 보드의 열이 0202 였다면 temp[0]=2, temp[1]=2일 것, 현재 index 값은 2
            if (temp[i] == temp[i+1]) {
                temp[i] *= 2;  // 제곱
                temp[i+1] = 0;  // 뒤쪽 값은 0으로 초기화
                i++; // 중복 제거
            }
        }

        // 3. 숫자 앞으로 모으기
        int result[BOARD_SIZE] = {0};
        index = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (temp[i] != 0) {
                result[index++] = temp[i];
            }
        }

        // 4. 원래 보드에 결과 반영
        for (int row = 0; row < BOARD_SIZE; row++) {
            board[row][col] = result[row];
        }

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        for (int i = 0;i < BOARD_SIZE;i++) {
            if (ori[i] != result[i]) {
                changed = 1;
            }
        }
    }
    return changed;
}

int moveDown(Board board) {
    int changed = 0;

    for (int col = 0; col < BOARD_SIZE; col++) {
        int temp[BOARD_SIZE] = {0};
        int index = 0;

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        int ori[BOARD_SIZE] = {0};
        for (int i = 0; i < BOARD_SIZE; i++) {
            ori[i] = board[i][col]; // 원본 복사
        }

        // 1. 첫번째 열부터 0이 아닌 값 추출
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] != 0) {  // 0이 아닐 때
                temp[index++] = board[row][col];  // temp[index]에 col번째 row의 값을 받아들임
            }
        }

        // 2. 추출한 값 중에서 같은 숫자끼리 합치기
        // 뒤쪽부터 합치기
        for (int i = index-1; i > 0; i--) {  // i > 0 : 3-2, 2-1, 1-0 0까지 내려가면 0--1되서 터짐
            // 만약 보드의 열이 0222 였다면 temp[0]=2, temp[1]=2, temp[2]=2일 것, index 값은 3
            if (temp[i-1] == temp[i]) { // temp[1] == temp[2]
                    temp[i] *= 2;  // temp[2] = 4
                    temp[i-1] = 0;  // 앞의 값은 0으로 초기화, temp[1] = 0
                    i--; // 중복 제거-ㅅ1바 조건 싹다 ++로 되어잇엇네 개갇다
            }  // temp에는 0204가 저장됨
        }

        // 3. 숫자 뒤로 모으기
        int result[BOARD_SIZE] = {0};
        index = BOARD_SIZE-1;
        for (int i = BOARD_SIZE-1; i >= 0; i--) {  // 뒤쪽부터
            if (temp[i] != 0) {
                result[index--] = temp[i];
            }
        }

        // 4. 원래 보드에 결과 반영
        for (int row = 0; row < BOARD_SIZE; row++) {
            board[row][col] = result[row];
        }

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        for (int i = 0;i < BOARD_SIZE;i++) {
            if (ori[i] != result[i]) {
                changed = 1;
            }
        }
    }
    return changed;
}

int moveLeft(Board board) {
    int changed = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {
        int temp[BOARD_SIZE] = {0};
        int index = 0;

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        int ori[BOARD_SIZE] = {0};
        for (int i = 0; i < BOARD_SIZE; i++) {
            ori[i] = board[row][i]; // 원본 복사
        }

        // 1. 첫번째 행부터 0이 아닌 값 추출
        for (int col = 0; col < BOARD_SIZE; col++) {
             if (board[row][col] != 0) {  // 0이 아닐 때
                temp[index++] = board[row][col];  // temp[index]에 row번째 col의 값을 받아들임
            }
        }

        // 2. 추출한 값 중에서 같은 숫자끼리 합치기
        for (int i = 0; i < index-1; i++) {  // 만약 보드의 행이 0202 였다면 temp[0]=2, temp[1]=2일 것, 현재 index 값은 2
            if (temp[i] == temp[i+1]) {
                temp[i] *= 2;  // 제곱
                temp[i+1] = 0;  // 뒤쪽 값은 0으로 초기화
                i++; // 중복 제거
            }
        }

        // 3. 숫자 앞으로 모으기
        int result[BOARD_SIZE] = {0};
        index = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (temp[i] != 0) {
                result[index++] = temp[i];
            }
        }

        // 4. 원래 보드에 결과 반영
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = result[col];
        }

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        for (int i = 0;i < BOARD_SIZE;i++) {
            if (ori[i] != result[i]) {
                changed = 1;
            }
        }
    }
    return changed;
}

int moveRight(Board board) {
    int changed = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {
        int temp[BOARD_SIZE] = {0};
        int index = 0;

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        int ori[BOARD_SIZE] = {0};
        for (int i = 0; i < BOARD_SIZE; i++) {
            ori[i] = board[row][i]; // 원본 복사
        }

        // 1. 첫번째 행부터 0이 아닌 값 추출
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != 0) {  // 0이 아닐 때
                temp[index++] = board[row][col];  // temp[index]에 row번째 col의 값을 받아들임
            }
        }

        // 2. 추출한 값 중에서 같은 숫자끼리 합치기
        // 뒤쪽부터 합치기
        for (int i = index-1; i > 0; i--) {  // i > 0 : 3-2, 2-1, 1-0 0까지 내려가면 0--1되서 터짐
            // 만약 보드의 행이 0222 였다면 temp[0]=2, temp[1]=2, temp[2]=2일 것, index 값은 3
            if (temp[i-1] == temp[i]) { // temp[1] == temp[2]
                temp[i] *= 2;  // temp[2] = 4
                temp[i-1] = 0;  // 앞의 값은 0으로 초기화, temp[1] = 0
                i--; // 중복 제거
            }  // temp에는 0204가 저장됨
        }

        // 3. 숫자 뒤로 모으기
        int result[BOARD_SIZE] = {0};
        index = BOARD_SIZE-1;
        for (int i = BOARD_SIZE-1; i >= 0; i--) {  // 뒤쪽부터
            if (temp[i] != 0) {
                result[index--] = temp[i];
            }
        }

        // 4. 원래 보드에 결과 반영
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = result[col];
        }

        // ex.움직임 없을 때 spawn_tile 함수 건너뛰기 값 반환용
        for (int i = 0;i < BOARD_SIZE;i++) {
            if (ori[i] != result[i]) {
                changed = 1;
            }
        }
    }
    return changed;  // 를 for문 안에 써놓아서 로직이 터져버림zzz; 한줄 변환/체크하고 바로 리턴;;
}