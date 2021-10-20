#include <bits/stdc++.h>

using namespace std;

long double dist(pair<int, int> a, pair<int, int> b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		pair<int, int> nn[600];
		for(int i=1;i<=n;i++){
			scanf("%d %d", &nn[i].first, &nn[i].second);
		}
		long double dp[600][600];
		fill(dp[0], dp[0]+600*600, 9999999999);
		dp[1][2] = dist(nn[1], nn[2]);
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i-2;j++)
				dp[i-1][i] = min(dp[i-1][i], dp[j][i-1] + dist(nn[j], nn[i]));
			for(int j=1;j<=i-2;j++)
				dp[j][i] = min(dp[j][i], dp[j][i-1] + dist(nn[i-1], nn[i]));
		}
		long double ans = 9999999999;
		for(int i=1;i<n;i++){
			ans = min(ans, dp[i][n] + dist(nn[i], nn[n]));
		}
		printf("%.31Lf\n", ans);
	}
	return 0;
}
