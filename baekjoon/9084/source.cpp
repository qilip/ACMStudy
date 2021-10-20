#include <bits/stdc++.h>

using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int coin[30] = {0};
		int dp[10010] = {0};
		for(int i=0;i<n;i++){
			scanf("%d", &coin[i]);
		}
		int won;
		scanf("%d", &won);
		dp[0] = 1;
		for(int j=0;j<n;j++){
			for(int i=1;i<=won;i++){
				if(i-coin[j]<0 || !dp[i-coin[j]]) continue;
				dp[i] += dp[i-coin[j]];
			}
		}
		printf("%d\n", dp[won]);
	}
	return 0;
}
