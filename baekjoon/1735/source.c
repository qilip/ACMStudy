#include <stdio.h>

int e(int a, int b){
	return a%b ? e(b, a%b) : b;
}

int main(void){
    int a, b, c, d, q, w, k, t;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    q = a*d+c*b;
    w = b*d;
    k = e(q, w);
    printf("%d %d", q/k, w/k);
}
