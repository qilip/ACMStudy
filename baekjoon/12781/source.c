#include <stdio.h>

int ccw(int a, int b, int c, int d, int e, int f){
	int p = a*d + c*f + e*b;
	p -= b*c + d*e + f*a;
	if(p>0) return 1;
	else if(p<0) return -1;
	return 0;
}

int main(void){
    int x[4], y[4];
	for(int i=0;i<4;i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	int abc = ccw(x[0], y[0], x[1], y[1], x[2], y[2]);
	int abd = ccw(x[0], y[0], x[1], y[1], x[3], y[3]);
	if(abc*abd < 0) printf("1");
	else printf("0");
    return 0;
}