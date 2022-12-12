#include <stdio.h>
#include <string.h>

#define BUF_SIZE 128
#define GRID_SIZE 99

int main() {
    int result = 0;
    int grid[GRID_SIZE][GRID_SIZE];
    int visibility_grid[GRID_SIZE][GRID_SIZE];
    for (int row=0; row<GRID_SIZE; row++) {
        for (int col=0; col<GRID_SIZE; col++) {
            if (row == 0 || row == GRID_SIZE-1 || col == 0 || col == GRID_SIZE-1) {
                visibility_grid[row][col] = 1;
            } else {
                visibility_grid[row][col] = 0;
            }
        }
    }

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

    // for (int row=0; row<GRID_SIZE; row++) {
    //     for (int col=0; col<GRID_SIZE; col++) {
    //         printf("%d", grid[row][col]);
    //     }
    //     printf("\n");
    // }

    int max_height = 0;

    // Left to Right
    for (int row=1; row<GRID_SIZE; row++) {
        max_height = 0;
        for (int col=0; col<GRID_SIZE; col++) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visibility_grid[row][col] += 1;
            }
        }
    }

    // Right to Left
    for (int row=1; row<GRID_SIZE; row++) {
        max_height = 0;
        for (int col=GRID_SIZE-1; col>=0; col--) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visibility_grid[row][col] += 1;
            }
        }
    }

    // Up to Down
    for (int col=1; col<GRID_SIZE; col++) {
        max_height = 0;
        for (int row=0; row<GRID_SIZE; row++) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visibility_grid[row][col] += 1;
            }
        }
    }

    // Down to Up
    for (int col=1; col<GRID_SIZE; col++) {
        max_height = 0;
        for (int row=GRID_SIZE-1; row>=0; row--) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visibility_grid[row][col] += 1;
            }
        }
    }


    for (int row=0; row<GRID_SIZE; row++) {
        for (int col=0; col<GRID_SIZE; col++) {
            if (visibility_grid[row][col] > 0) {
                result++;
            }
        }
    }


    printf("Result: %d\n", result);
    return 0;
}