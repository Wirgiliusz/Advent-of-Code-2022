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

    char buf[BUF_SIZE];
    int letters_left[NUM_LETTERS];
    int letters_right[NUM_LETTERS];
    int score = 0;

    while (fgets(buf, BUF_SIZE, fd) != NULL)  {
        unsigned int len = strlen(buf);
        
        for (int i=0; i<NUM_LETTERS; i++) {
            letters_left[i] = 0;
            letters_right[i] = 0;
        }

        for (unsigned int i=0; i<len; i++) {
            char c = buf[i];

            int offset = 0;
            if (c < 97) {
                offset = 65 - 26;
            } else {
                offset = 97;
            }

            if (i < len/2) {
                letters_left[c - offset] += 1;
            } else {
                letters_right[c - offset] += 1;
            }
        }
        
        for (unsigned int i=0; i<NUM_LETTERS; i++) {
            if (letters_left[i] != 0 && letters_right[i] != 0) {
                score += i+1;
            }
        }
    }

    printf("Total score: %d\n", score);

    return 0;
}
