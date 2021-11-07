#include <bits/stdc++.h>

using namespace std;

int dp[40][40];

int fd(int a, int b){
	if(!a || !b) return dp[a][b] = 1;
	if(dp[a][b]!=-1) return dp[a][b];
	dp[a][b] = fd(a-1, b);
	dp[a][b] += fd(a-1, b-1);
	return dp[a][b];
}

void track(int a, int b, int c){
	if(!a){
		printf("\n");
		return;
	}
	if(!b){
		printf("0");
		track(a-1, b, c);
		return;
	}
	int p = fd(a-1, b);
	if(p>c){
		printf("0");
		track(a-1, b, c);
	}else{
		printf("1");
		track(a-1, b-1, c-p);
	}
}

int main(void){
	int n, l, k;
	scanf("%d %d %d", &n, &l, &k);
	fill(dp[0], dp[0]+40*40, -1);
	track(n, l, k-1);
	return 0;
}
