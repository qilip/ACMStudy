#include <stdio.h>

int sum = 0;

void dc(int n, int r, int c){
    int flgx = 0, flgy = 0;
    if(n==1) { printf("%d", sum); return; }
    n/=2;
    if(r>=n) { flgx++; r-=n; }
    if(c>=n) { flgy++; c-=n; }
    sum += n*n*(flgx*2 + flgy);
    dc(n, r, c);
}

int main(void){
    int n, in, r, c;
    scanf("%d %d %d", &in, &r, &c);
    n = 1 << in;
    dc(n, r, c);
}
