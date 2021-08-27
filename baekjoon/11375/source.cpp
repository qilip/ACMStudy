#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v[1010];
int visited[1010] = {0};
int nn[1010] = {0};
int mm[1010] = {0};

int dfs(int cur){
	visited[cur] = 1;
	for(auto nxt : v[cur]){
		if(!mm[nxt] || (!visited[mm[nxt]] && dfs(mm[nxt]))){
			nn[cur] = nxt;
			mm[nxt] = cur;
			return 1;
		}
	}
	return 0;
}

signed main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout<<setprecision(8)<<fixed;
    
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d", &a);
		for(int j=0;j<a;j++){
			int w;
			scanf("%d", &w);
			v[i].push_back(w);
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		fill(visited, visited+1005, 0);
		if(dfs(i)) ans++;
	}
	printf("%d", ans);
    return 0;
}
