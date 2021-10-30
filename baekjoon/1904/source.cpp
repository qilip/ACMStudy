#include <bits/stdc++.h>

using namespace std;
const int MOD = 15746;

int dp[1000010] = {0};

int main(void){
	int n;
	dp[1] = 1;
	dp[2] = 2;
	scanf("%d", &n);
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MOD;
	}
	printf("%d\n", dp[n]);
	return 0;
}
