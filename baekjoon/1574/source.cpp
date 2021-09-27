#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[310];
int a[310];
int b[310];
int visited[310];

int dfs(int l){
	visited[l] = 1;
	for(int r : v[l]){
		if(!b[r] || (!visited[b[r]] && dfs(b[r]))){
			a[l] = r;
			b[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(void){
	int r, c, n;
	int rc[310][310] = {0};
	scanf("%d %d %d", &r, &c, &n);
	for(int i=0;i<n;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		rc[x][y] = 1;
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(!rc[i][j]) v[i].push_back(j);
		}
	}
	
	int ans = 0;
	for(int i=1;i<=r;i++){
		if(!a[i]){
			fill(visited, visited+309, 0);
			if(dfs(i)) ans++;
		}
	}
	printf("%d", ans);
    return 0;
}