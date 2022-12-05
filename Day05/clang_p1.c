#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 128

#define STACK_SIZE 128
#define NUM_OF_STACKS 9

typedef struct stack {
    char data[STACK_SIZE];
    int size;
} stack;

void print_stack(stack *s) {
    for (int i=0; i<s->size; i++) {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

void push(stack *s, char val) {
    if (s->size < STACK_SIZE-1) {
        s->data[s->size] = val;
        s->size += 1;
    }
}

void push_front(stack *s, char val) {
    if (s->size < STACK_SIZE-1) {
        for (int i=s->size; i>0; i--) {
            s->data[i] = s->data[i-1];
        }
        s->data[0] = val;
        s->size += 1;
    }
}

char pop(stack *s) {
    char val = ' ';
    if (s->size > 0) {
        val = s->data[s->size-1];
        s->size -= 1;
    }

    return val;
}

char pop_front(stack *s) {
    char val = ' ';
    if (s->size > 0) {
        val = s->data[0];
        for (int i=0; i<s->size-1; i++) {
            s->data[i] = s->data[i+1];
        }
        s->size -= 1;
    }

    return val;
}

int main() {
    FILE *fd = fopen("input.txt", "r");
    if (!fd) {
        puts("Error: Can not open the file!\n");
        return 1;
    }

    char buf[BUF_SIZE];
    stack stacks[NUM_OF_STACKS];
    for (int i=0; i<NUM_OF_STACKS; i++) {
        stacks[i].size = 0;
    }

    while (fgets(buf, BUF_SIZE, fd) != NULL)  {
        if (buf[1] != '1') {
            int buf_i = 1;
            for (int i=0; i<NUM_OF_STACKS; i++) {
                char c = buf[buf_i];
                if (isalpha(c)) {
                    push(&stacks[i], c);
                }
                buf_i += 4;
            }
        } else {
            fgets(buf, BUF_SIZE, fd);
            break;
        }
    }

    int num = 0;
    int from = 0;
    int to = 0;
    while (fscanf(fd, "%*s %d %*s %d %*s %d", &num, &from, &to) != EOF) {
        for (int i=0; i<num; i++) {
            char c = pop_front(&stacks[from-1]);
            push_front(&stacks[to-1], c);
        }
    }

    printf("Result: ");
    for (int i=0; i<NUM_OF_STACKS; i++) {
        printf("%c", pop_front(&stacks[i]));
    }
    printf("\n");

    return 0;
}