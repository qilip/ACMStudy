#include <stdio.h>

typedef long long ll;

int ccw(int a, int b, int c, int d, int e, int f){
	ll p = (ll)a*d + (ll)c*f + (ll)e*b;
	p -= (ll)b*c + (ll)d*e + (ll)f*a;
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
	int cda = ccw(x[2], y[2], x[3], y[3], x[0], y[0]);
	int cdb = ccw(x[2], y[2], x[3], y[3], x[1], y[1]);
	if(abc*abd < 0 && cda*cdb < 0) printf("1");
	else printf("0");
    return 0;
}