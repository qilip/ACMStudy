#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> g[100'0010];
int visited[100'0010];
int dp[2][100'0000];

void dfs(int cur, int color){
	visited[cur] = 1;
	for(auto next : g[cur]){
		if(visited[next]) continue;
		dfs(next, color^1);
		dp[0][cur] += dp[1][next];
		dp[1][cur] += min(dp[0][next], dp[1][next]);
	}
	dp[1][cur]++;
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n-1;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d", min(dp[0][1], dp[1][1]));
	return 0;
}