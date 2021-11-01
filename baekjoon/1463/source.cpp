#include <bits/stdc++.h>

using namespace std;

int dp[1000010] = {0};

int f(int c){
	if(dp[c]) return dp[c];
	if(c==1) return 0;
	int a = dp[c-1] = f(c-1);
	int b = 99999999, d = 99999999;
	if(!(c%2)) b = dp[c/2] = f(c/2);
	if(!(c%3)) d = dp[c/3] = f(c/3);
	return min({a, b, d}) + 1;
}

int main(void){
	int n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}
