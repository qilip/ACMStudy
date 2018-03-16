#include <stdio.h>
#include <math.h>

void mov(int n, int a, int b, int c){
    if(n==0) return;    
    mov(n-1, a, c, b);
    printf("%d %d\n", a, b);
    mov(n-1, c, b, a);
}

int main(void){
    int N;
    scanf("%d", &N);
    printf("%d\n", (int)pow(2, N)-1);
    mov(N, 1, 3, 2);
}
