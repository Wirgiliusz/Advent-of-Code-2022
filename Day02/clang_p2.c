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
    char needed_outcome;
    char opponent_move;
    int points = 0;

    while (fgets(buf, BUF_SIZE, fd) != NULL)  {
        opponent_move = buf[0];
        needed_outcome = buf[2];

        if (needed_outcome == 'X') {
            points += P_LOSE;
            if (opponent_move == 'A') {
                points += P_SCISSORS;
            } else if (opponent_move == 'B') {
                points += P_ROCK;
            } else {
                points += P_PAPER;
            }
        } else if (needed_outcome == 'Y') {
            points += P_DRAW;
            if (opponent_move == 'A') {
                points += P_ROCK;
            } else if (opponent_move == 'B') {
                points += P_PAPER;
            } else {
                points += P_SCISSORS;
            }
        } else {
            points += P_WIN;
            if (opponent_move == 'A') {
                points += P_PAPER;
            } else if (opponent_move == 'B') {
                points += P_SCISSORS;
            } else {
                points += P_ROCK;
            }
        }
    }

    printf("Total score: %d\n", points);

    return 0;
}