#include <stdio.h>
#include <string.h>

#define BUF_SIZE 128

int main() {
    int result = 0;

    FILE *fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, fd) != NULL)  {

    }


    printf("Result: %d\n", result);
    return 0;
}