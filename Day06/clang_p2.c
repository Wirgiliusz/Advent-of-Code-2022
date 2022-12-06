#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1028 * 4
#define MARKER_LEN 14

// Checks whether there exists a char "c"
// between index "start" and index "end"
// in array "arr"
// Returns the index where char appears
// or -1 if no char in the range.
int char_between_indexes(char c, int start, int end, char *arr) {
    while (start != end) {
        if (arr[start] == c) {
            return start;
        }

        start++;
    }
    
    return -1;
}

int main() {
    FILE *fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char buf[BUF_SIZE];
    int i = 0;
    int start = 0;
    int end = 0;

    fgets(buf, BUF_SIZE, fd);

    while (end - start < MARKER_LEN && end < BUF_SIZE) {
        char c = buf[i];
        int offset = char_between_indexes(c, start, end, buf); 
        
        if (offset != -1) {
            start = offset+1;
        }
        end++;
    
        i++;
    }
    
    printf("Result: %d\n", end);
    return 0;
}
