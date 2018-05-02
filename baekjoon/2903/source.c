#include <stdio.h>

int main(void) {
    int N, dot = 4, line = 1;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        dot += line * (line + 1) * 2;
        dot += line*line;
        line *=2;
    }
    printf("%d", dot);
}
