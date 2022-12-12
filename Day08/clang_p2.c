#include <stdio.h>
#include <string.h>

#define BUF_SIZE 128
#define GRID_SIZE 99

int main() {
    int result = 0;
    int grid[GRID_SIZE][GRID_SIZE];

    FILE *fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char buf[BUF_SIZE];
    int row = 0;
    while (fgets(buf, BUF_SIZE, fd) != NULL)  {
        for (int col=0; col<GRID_SIZE; col++) {
            grid[row][col] = buf[col] - '0';
        }

        row++;
    }

    int tree_height = 0;

    for (int row=1; row<GRID_SIZE-1; row++) {
        for (int col=1; col<GRID_SIZE-1; col++) {
            tree_height = grid[row][col];

            int i = 0;

            // Look left
            int score_left = 0;
            i = 1;
            while (col - i >= 0 && grid[row][col-i] < tree_height) {
                score_left++;
                i++;
            }
            if (grid[row][col-i] == tree_height) {
                score_left++;
            }

            // Look right
            int score_right = 0;
            i = 1;
            while (col + i < GRID_SIZE && grid[row][col+i] < tree_height) {
                score_right++;
                i++;
            }
            if (grid[row][col+1] == tree_height) {
                score_right++;
            }

            // Look up
            int score_up = 0;
            i = 1;
            while (row - i >= 0 && grid[row-i][col] < tree_height) {
                score_up++;
                i++;
            }
            if ( grid[row-i][col] == tree_height) {
                score_up++;
            }

            // Look down
            int score_down = 0;
            i = 1;
            while (row + i < GRID_SIZE && grid[row+i][col] < tree_height) {
                score_down++;
                i++;
            }
            if ( grid[row+i][col] == tree_height) {
                score_down++;
            }
            
            int scenic_score = score_left * score_right * score_up * score_down;
            if (scenic_score > result) {
                result = scenic_score;
            }
        }
    }
    
    printf("Result: %d\n", result);
    return 0;
}