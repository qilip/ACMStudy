#include <bits/stdc++.h>

using namespace std;

int dp[51][50'0001];

int main(void){
	int n;
	scanf("%d", &n);
	fill(&dp[0][0], &dp[50][50'0000], -1);
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		int cur;
		scanf("%d", &cur);
		for(int j=0;j<=50'0000;j++){
			dp[i][j] = dp[i-1][j];
			if(j+cur<=50'0000 && dp[i-1][j+cur]>-1) dp[i][j] = max(dp[i][j], dp[i-1][j+cur]);
			if(j-cur>=0 && dp[i-1][j-cur]>-1) dp[i][j] = max(dp[i][j], dp[i-1][j-cur]+cur);
			if(cur>j && dp[i-1][cur-j]>-1) dp[i][j] = max(dp[i][j], dp[i-1][cur-j]+j);
		}
	}
	if(dp[n][0]>0) printf("%d", dp[n][0]);
	else printf("-1");
    return 0;
}
