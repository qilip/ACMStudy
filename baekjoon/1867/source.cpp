#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[510];
int a[510];
int b[510];
int visited[510];

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
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=k;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		if(!a[i]){
			fill(visited, visited+509, 0);
			if(dfs(i)) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}