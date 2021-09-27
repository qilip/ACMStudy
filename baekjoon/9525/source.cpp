#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> v(10010);
int a[10010];
int b[10010];
int visited[10010];

int dfs(int l){
	visited[l] = 1;
	for(int r : v[l]){
		if(!b[r] || !visited[b[r]] && dfs(b[r])){
			a[l] = r;
			b[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(void){
	int n;
	char nn[110][110] = {0};
	int nv[110][110] = {0};
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf(" %c", &nn[i][j]);
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(nn[i][j] != '.') continue;
			if(nn[i][j-1] != '.') cnt++;
			nv[i][j] = cnt;
		}
	}
	cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(nn[j][i] != '.') continue;
			if(nn[j-1][i] != '.') cnt++;
			v[cnt].push_back(nv[j][i]);
		}
	}
	int ans = 0;
	for(int i=1;i<=cnt;i++){
		if(!a[i]){
			fill(visited, visited+10009, 0);
			if(dfs(i)) ans++;
		}
	}
	printf("%d", ans);
    return 0;
}