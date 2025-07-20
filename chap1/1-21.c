// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve  the same spacing. Use the same tab stops as
// for detab. When either a tab or a single blank would suffice to reach a tab
// stop, which should be given preference?

// Implementation Idea
// If the next tab stop can be reached and two or more spaces are needed → use
// \t If the next tab stop can be reached but only one space is needed → use ' '

// 다음에 다시 해볼 것
// - 공백이 감지되면 공백이 나오지 않을 때까지 바로 쭉 순회 후 처리하는
// 방식으로도 구현해보기
// - 공백으로 끝났을 때 처리 더 깔끔하게 만들어보기

#include <stdio.h>
#define MAXLINE 1000

void entab(char from[], char to[], int tabsize);

int main(void)
{
    char inputLine[MAXLINE];
    char outputLine[MAXLINE];
    int c;
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || i >= MAXLINE - 1)
        {
            inputLine[i] = '\0';
            entab(inputLine, outputLine, 4);
            i = 0;
            printf("%s\n", outputLine);
        }
        else
        {
            inputLine[i++] = c;
        }
    }
    return 0;
}

// tab stop
void entab(char from[], char to[], int tabsize)
{
    int i = 0;
    int j = 0;
    int col = 0;
    int count = 0;
    int dist;

    while (from[i] != '\0' && j < MAXLINE - 1)
    {
        if (from[i] == ' ')
        {
            count++;
            i++;
            continue;
        }

        while (count > 0 && j < MAXLINE - 1)
        {
            dist = tabsize - col % tabsize;
            if (dist == 1)
            { // when one space is enough
                to[j++] = ' ';
                col++;
                count--;
            }
            else if (dist <= count)
            { // next tab <= count + col
                to[j++] = '\t';
                col += dist;
                count -= dist;
            }
            else
            {
                to[j++] = ' ';
                col++;
                count--;
            }
        }

        // 문자 입력
        if (j < MAXLINE - 1)
        {
            to[j++] = from[i];
            if (from[i] == '\t')
            {
                col += tabsize - col % tabsize;
            }
            else
            {
                col++;
            }
            i++;
        }
    }

    // 공백으로 끝났을 시.
    while (count > 0 && j < MAXLINE - 1)
    {
        dist = tabsize - col % tabsize;
        if (dist == 1)
        { // when one space is enough
            to[j++] = ' ';
            col++;
            count--;
        }
        else if (dist <= count)
        {
            to[j++] = '\t';
            col += dist;
            count -= dist;
        }
        else
        {
            to[j++] = ' ';
            col++;
            count--;
        }
    }
    to[j] = '\0';
}

// Modern tab
// void entab(char from[], char to[], int tabsize){
//     int i = 0;
//     int j = 0;
//     int count = 0;
//     int k;

//     while (from[i] != '\0' && j < MAXLINE - 1) {
//         if (from[i] == ' ') {
//             count++;
//             if (count == tabsize) {
//                 to[j++] = '\t';
//                 count = 0;
//             }
//         } else {
//             if (count > 0) {
//                 for (k=0; k < count; k++) {
//                     to[j++] = ' ';
//                 }
//                 count = 0;
//             }
//             to[j++] = from[i];

//         }
//         i++;
//     }
//     to[j] = '\0';
// }
