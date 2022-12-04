#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        char elf1_start_str[BUF_SIZE];
        char elf1_end_str[BUF_SIZE];
        char elf2_start_str[BUF_SIZE];
        char elf2_end_str[BUF_SIZE];

        int buf_i = 0;
        int i = 0;

        while (buf[buf_i] != '-') {
            elf1_start_str[i] = buf[buf_i];
            i++;
            buf_i++;
        }
        elf1_start_str[i] = '\0';
        buf_i++;
        i = 0;

        while (buf[buf_i] != ',') {
            elf1_end_str[i] = buf[buf_i];
            i++;
            buf_i++;
        }
        elf1_end_str[i] = '\0';
        buf_i++;
        i = 0;

        while (buf[buf_i] != '-') {
            elf2_start_str[i] = buf[buf_i];
            i++;
            buf_i++;
        }
        elf2_start_str[i] = '\0';
        buf_i++;
        i = 0;

        while (buf[buf_i] != '\0') {
            elf2_end_str[i] = buf[buf_i];
            i++;
            buf_i++;
        }
        elf2_end_str[i] = '\0';

        int elf1_start = atoi(elf1_start_str);
        int elf1_end = atoi(elf1_end_str);
        int elf2_start = atoi(elf2_start_str);
        int elf2_end = atoi(elf2_end_str);

        if (elf1_end >= elf2_start && elf2_end >= elf1_start) {
            result++;
        }
    }


    printf("Result: %d\n", result);
    return 0;
}