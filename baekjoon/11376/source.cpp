#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[2010];
int a[2010];
int b[1010];
int visited[2010];

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
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		for(int j=0;j<x;j++){
			int y;
			scanf("%d", &y);
			v[i*2].push_back(y);
			v[i*2+1].push_back(y);
		}
	}
	int ans = 0;
	for(int i=2;i<=n*2+1;i++){
		if(!a[i]){
			fill(visited, visited+2009, 0);
			if(dfs(i)) ans++;
		}
	}
	printf("%d", ans);
    return 0;
}