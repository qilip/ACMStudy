#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;

int dp[1010] = {0};

int main(void){
	int n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;
	scanf("%d", &n);
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1] + 2*dp[i-2];
		dp[i] %= MOD;
	}
	printf("%d\n", dp[n]);
	return 0;
}
