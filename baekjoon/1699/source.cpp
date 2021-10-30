#include <bits/stdc++.h>

using namespace std;

int dp[100010] = {0};
vector<int> seed;

int main(void){
	int n;
	fill(dp, dp+100010, 99999999);
	scanf("%d", &n);
	for(int i=1;i*i<=n;i++){
		seed.push_back(i*i);
	}
	dp[0] = 0;
	for(int c : seed){
		for(int i=c;i<=n;i++){
			if(dp[i-c]==99999999) continue;
			dp[i] = min(dp[i], dp[i-c]+1);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
