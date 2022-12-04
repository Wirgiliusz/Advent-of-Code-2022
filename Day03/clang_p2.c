#include <stdio.h>
#include <string.h>

#define BUF_SIZE 128
#define NUM_LETTERS 26 * 2

int main() {
    FILE *fd = fopen("input.txt", "r");

    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char elf1[BUF_SIZE];
    char elf2[BUF_SIZE];
    char elf3[BUF_SIZE];
    char letters1[NUM_LETTERS];
    char letters2[NUM_LETTERS];
    char letters3[NUM_LETTERS];

    int score = 0;

    while (fgets(elf1, BUF_SIZE, fd) != NULL)  {
        fgets(elf2, BUF_SIZE, fd);
        fgets(elf3, BUF_SIZE, fd);
        
        unsigned int len1 = strlen(elf1);
        unsigned int len2 = strlen(elf2);
        unsigned int len3 = strlen(elf3);
        
        for (int i=0; i<NUM_LETTERS; i++) {
            letters1[i] = 0;
            letters2[i] = 0;
            letters3[i] = 0;
        }

        for (unsigned int i=0; i<len1; i++) {
            char c = elf1[i];

            int offset = 0;
            if (c < 97) {
                offset = 65 - 26;
            } else {
                offset = 97;
            }

            if (c > 64) {
                letters1[c - offset] += 1;
            }
        }

        for (unsigned int i=0; i<len2; i++) {
            char c = elf2[i];

            int offset = 0;
            if (c < 97) {
                offset = 65 - 26;
            } else {
                offset = 97;
            }

            if (c > 64) {
                letters2[c - offset] += 1;
            }
        }

        for (unsigned int i=0; i<len3; i++) {
            char c = elf3[i];

            int offset = 0;
            if (c < 97) {
                offset = 65 - 26;
            } else {
                offset = 97;
            }

            if (c > 64) {
                letters3[c - offset] += 1;
            }
        }
        
        for (unsigned int i=0; i<NUM_LETTERS; i++) {
            if (letters1[i] > 0 && letters2[i] > 0 && letters3[i] > 0) {
                score += i+1;
            }
        }
    }

    printf("Total score: %d\n", score);

    return 0;
}
