#include <stdio.h>

int main(void){
    int N;
    int pibo[21] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 };
    scanf("%d", &N);
    printf("%d", pibo[N]);
}