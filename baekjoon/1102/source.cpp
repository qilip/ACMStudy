#include <bits/stdc++.h>

using namespace std;

int n, p;
int nn[20][20];
int poe;
int dp[1<<16];

int dfs(int po){
	if(__builtin_popcount(po)>=p) return 0;
	if(dp[po]) return dp[po];
	int pdp = 9999'9999;
	for(int j=0;j<n;j++){
		if(~po & 1<<n-j-1){
			int minp = 9999'9999;
			for(int i=0;i<n;i++){
				if(po & 1<<n-i-1){
					minp = min(minp, nn[i][j]);
				}
			}
			if(pdp <= minp) continue;
			int nxt = po | 1<<n-j-1;
			pdp = min(pdp, dfs(nxt) + minp);
		}
	}
	return dp[po] = pdp;
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &nn[i][j]);
		}
	}
	char s[20];
	scanf(" %s", s);
	for(int i=0;i<n;i++){
		if(s[i]=='Y') poe |= 1<<n-i-1;
	}
	scanf("%d", &p);
	if(!poe && p) printf("-1\n");
	else printf("%d\n", dfs(poe));
	return 0;
}
