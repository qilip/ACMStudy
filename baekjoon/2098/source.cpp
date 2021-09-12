#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int w[16][16];
int dp[16][1<<16];

int tsp(int cur, int visited){
	if(dp[cur][visited] != -1) return dp[cur][visited];
	if(visited == (1<<n)-1){
		return w[cur][0] ? w[cur][0] : 1e9;
	}
	dp[cur][visited] = 1e9;
	for(int i=0;i<n;i++){
		if(visited & (1<<i) || !w[cur][i]) continue;
		dp[cur][visited] = min(dp[cur][visited], tsp(i, visited | (1<<i)) + w[cur][i]);
	}
	return dp[cur][visited];
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		fill(dp[i], dp[i]+(1<<16), -1);
		for(int j=0;j<n;j++){
			scanf("%d", &w[i][j]);
		}
	}
	printf("%d", tsp(0, 1));
    return 0;
}
