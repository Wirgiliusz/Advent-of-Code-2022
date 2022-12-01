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
    int max_calories = 0;

    while (fgets(buf, MAX_DIGITS, fd) != NULL)  {
        if (buf[0] != '\n') {
            calories = atoi(buf);
            printf("cal: %d\n", calories);
            calories_sum += calories;
        } else {
            printf("sum: %d\n\n", calories_sum);
            if (calories_sum > max_calories) {
                max_calories = calories_sum;
            }
            calories_sum = 0;
        }
    }

    printf("Max calories: %d\n", max_calories);

    return 0;
}