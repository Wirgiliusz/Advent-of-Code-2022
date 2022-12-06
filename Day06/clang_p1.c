#include <stdio.h>
#include <string.h>

// Bad hard-coded solution
// But fast to implement
// Part 2 has way better solution to this problem
// but I am keeping this one here.
int last_four_different(char *arr) {
    if (arr[0] != arr[1] &&
        arr[0] != arr[2] &&
        arr[0] != arr[3]) {

        if (arr[1] != arr[2] &&
            arr[1] != arr[3]) {
            
            if (arr[2] != arr[3]) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    FILE *fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char last_four[4] = {0};
    char c;
    int i = 0;
    while ((c = fgetc(fd)) != EOF) {
        last_four[i % 4] = c;
        if (last_four_different(last_four) && i > 3) {
            break;
        }
    
        i++;
    }


    printf("Result: %d\n", i+1);
    return 0;
}