#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> g[510];
int a[510];
int b[510];
int visited[510];

char hv[2010][2010] = {0};
int hvn[2010][2010] = {0};

int dfs(int l){
	visited[l] = 1;
	for(int r : g[l]){
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
	while(T--){
		for(int i=1;i<=509;i++) g[i].clear();
		fill(a, a+509, 0);
		fill(b, b+509, 0);
		fill(hv[0], hv[2010], 0);
		fill(hvn[0], hvn[2010], 0);
		int h, v;
		scanf("%d %d", &h, &v);
		for(int i=1;i<=h;i++){
			int x, y;
			char s[1010] = {0};
			scanf("%d %d %s", &x, &y, s);
			int len = strlen(s);
			for(int j=0;j<len;j++){
				hv[x+j][y] = s[j];
				hvn[x+j][y] = i;
			}
		}
		for(int i=1;i<=v;i++){
			int x, y;
			char s[1010] = {0};
			scanf("%d %d %s", &x, &y, s);
			int len = strlen(s);
			for(int j=0;j<len;j++){
				if(hv[x][y+j] && hv[x][y+j] != s[j]){
					g[hvn[x][y+j]].push_back(i);
				}
			}
		}
		
		int cnt = 0;
		for(int i=1;i<=h;i++){
			if(!a[i]){
				fill(visited, visited+509, 0);
				if(dfs(i)) cnt++;
			}
		}
		printf("%d\n", h+v-cnt);
	}
	return 0;
}