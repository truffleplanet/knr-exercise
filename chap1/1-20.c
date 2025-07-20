// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
// every n columns. Should n be a variable or a symbolic parameter?

// I think n should be a symbolic parameter to make the program more flexible
// and adaptable.

// Implementation Idea
// if (c == '\t') blank = tabsize - (i % tabize)
// if (c == '\n') getnextline

#include <stdio.h>
#define MAXLINE 1000

void detab(char from[], char to[], int tabsize);

int main(void) {
    char inputLine[MAXLINE];
    char outputLine[MAXLINE];
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || i >= MAXLINE - 1) {
            inputLine[i] = '\0';
            detab(inputLine, outputLine, 4);
            i = 0;
            printf("%s\n", outputLine);
        } else {
            inputLine[i++] = c;
        }
    }
    return 0;
}

void detab(char from[], char to[], int tabsize) {
    int i = 0;
    int j = 0;
    int k;

    while (from[i] != '\0' && j < MAXLINE - 1) {
        if (from[i] == '\t') {
            int blank = tabsize - (j % tabsize);
            for (k = 0; k < blank && j < MAXLINE - 1; k++) {
                to[j++] = ' ';
            }
        } else {
            to[j++] = from[i];
        }
        i++;
    }
    to[j] = '\0';
}

// 초기 시도에서는 입력을 각 문자로 받으면서, 처리는 라인으로 해서, 조건 분기가
// 더 복잡했었음. 통일 시키니 훨씬 깔끔해짐.