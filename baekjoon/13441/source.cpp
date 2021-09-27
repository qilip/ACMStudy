#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[60];
int a[60];
int b[60];
int visited[60];
int pvis[60];
int n;
int nn[60][60];

void pdfs(int cur){
	for(int nxt = 1; nxt<=n; nxt++){
		if(!nn[cur][nxt]) continue;
		if(!pvis[nxt]){
			pvis[nxt] = 1;
			pdfs(nxt);
			for(int i=1;i<=n;i++){
				if(nn[nxt][i]) nn[cur][i] = 1;
			}
		}
	}
}

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
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;
			scanf(" %c", &x);
			if(x=='1') nn[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			pvis[j] = 0;
		pdfs(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			// printf("%d", nn[i][j]);
			if(nn[i][j]) v[i].push_back(j);
		}
		// printf("\n");
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(!a[i]){
			fill(visited, visited+59, 0);
			if(dfs(i)) cnt++;
		}
	}
	printf("%d", n-cnt);
	return 0;
}