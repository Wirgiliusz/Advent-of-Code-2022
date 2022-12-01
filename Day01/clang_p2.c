#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 8


int main() {
    FILE *fd;
    fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char buf[MAX_DIGITS];
    int calories = 0;
    int calories_sum = 0;
    int calories_top1 = 0;
    int calories_top2 = 0;
    int calories_top3 = 0;
    

    while (fgets(buf, MAX_DIGITS, fd) != NULL)  {
        if (buf[0] != '\n') {
            calories = atoi(buf);
            calories_sum += calories;
        } else {
            if (calories_sum > calories_top3) {
                calories_top3 = calories_sum;
                if (calories_sum > calories_top2) {
                    calories_top3 = calories_top2;
                    calories_top2 = calories_sum;
                    if (calories_sum > calories_top1) {
                        calories_top2 = calories_top1;
                        calories_top1 = calories_sum;
                    }
                }
            }

            calories_sum = 0;
        }
    }

    int top_calories_sum = calories_top1 + calories_top2 + calories_top3;
    printf("Top calories sum: %d\n", top_calories_sum);

    return 0;
}