#include <stdio.h>

int mem[31][31] = {0};

long long sol(int n, int m){
	if(!n || n>m) return 0;
	if(n==1) return m;
	if(n==m) return 1;
	if(mem[n][m]) return mem[n][m];
	mem[n][m] = sol(n, m-1) + sol(n-1, m-1);
	return mem[n][m];
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        long long ans = 1;
        scanf("%d %d", &n, &m);
        printf("%lld\n", sol(n, m));
    }
    return 0;
}