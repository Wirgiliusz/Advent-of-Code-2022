#include <stdio.h>

#define BUF_SIZE 8

#define P_ROCK 1
#define P_PAPER 2
#define P_SCISSORS 3

#define P_LOSE 0
#define P_DRAW 3
#define P_WIN 6

int main() {
    FILE *fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char buf[BUF_SIZE];
    char player_move;
    char opponent_move;
    int points = 0;

    while (fgets(buf, BUF_SIZE, fd) != NULL)  {
        opponent_move = buf[0];
        player_move = buf[2];
        printf("%c %c\n", player_move, opponent_move);

        if (player_move == 'X') {
            points += P_ROCK;
            if (opponent_move == 'A') {
                points += P_DRAW;
            } else if (opponent_move == 'B') {
                points += P_LOSE;
            } else {
                points += P_WIN;
            }
        } else if (player_move == 'Y') {
            points += P_PAPER;
            if (opponent_move == 'A') {
                points += P_WIN;
            } else if (opponent_move == 'B') {
                points += P_DRAW;
            } else {
                points += P_LOSE;
            }
        } else {
            points += P_SCISSORS;
            if (opponent_move == 'A') {
                points += P_LOSE;
            } else if (opponent_move == 'B') {
                points += P_WIN;
            } else {
                points += P_DRAW;
            }
        }
    }

    printf("Total score: %d\n", points);

    return 0;
}