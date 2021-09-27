#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[4000];
int a[4000];
int b[4000];
int visited[4000];

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
	int T;
	scanf("%d", &T);
	int ni[] = {-1, 0, 1, 1, 0, -1};
	int nj[] = {1, 1, 1, -1, -1, -1};
	while(T--){
		for(int i=0;i<4000;i++) v[i].clear();
		fill(a, a+4000, 0);
		fill(b, b+4000, 0);
		int n, m;
		scanf("%d %d", &n, &m);
		int nm[90][90] = {0};
		int lcnt = 0;
		int rcnt = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char a;
				scanf(" %c", &a);
				if(a=='.' && j%2) nm[i][j] = ++lcnt;
				if(a=='.' && !(j%2)) nm[i][j] = ++rcnt;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j+=2){
				if(!nm[i][j]) continue;
				for(int k=0;k<6;k++){
					if(nm[i+ni[k]][j+nj[k]])
						v[nm[i][j]].push_back(nm[i+ni[k]][j+nj[k]]);
				}
			}
		}
		int ans = 0;
		for(int i=1;i<=lcnt;i++){
			if(!a[i]){
				fill(visited, visited+4000, 0);
				if(dfs(i)) ans++;
			}
		}
		printf("%d\n", lcnt+rcnt-ans);
	}
	return 0;
}