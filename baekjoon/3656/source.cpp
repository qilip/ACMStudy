#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cap[2600][2600];
int flo[2600][2600];

int main(void){
	int T;
	scanf("%d", &T);
	int dh[] = {-1, 0, 1, 0};
	int dw[] = {0, 1, 0, -1};
	while(T--){
		int w, h;
		char hw[60][60] = {0};
		int nc[60][60] = {0};
		scanf("%d %d", &w, &h);
		int d, f, b;
		scanf("%d %d %d", &d, &f, &b);
		int ans = 0;
		int st = 1, ed = 2;
		int ncnt = 3;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf(" %c", &hw[i][j]);
				if(i==1 || i==h || j==1 || j==w){
					if(hw[i][j] == '.'){
						ans += f;
						hw[i][j] = '#';
					}
				}
				nc[i][j] = ncnt++;
			}
		}
		vector<int> g[2600];
		fill(cap[0], cap[2600], 0);
		fill(flo[0], flo[2600], 0);
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				int se = 1;
				if(hw[i][j] == '.') se = 2;
				g[se].push_back(nc[i][j]);
				g[nc[i][j]].push_back(se);
				if(se==2) cap[nc[i][j]][se] = f;
				else if(i==1 || i==h || j==1 || j==w) cap[se][nc[i][j]] = b;
				else cap[se][nc[i][j]] = d;
				for(int k=0;k<4;k++){
					if(hw[i+dh[k]][j+dw[k]]){
						g[nc[i][j]].push_back(nc[i+dh[k]][j+dw[k]]);
						cap[nc[i][j]][nc[i+dh[k]][j+dw[k]]] = b;
					}
				}
			}
		}
		while(1){
			int prev[2600] = {0};
			queue<int> q;
			q.push(st);
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				for(int nxt : g[cur]){
					if(!prev[nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
						prev[nxt] = cur;
						q.push(nxt);
						if(nxt == ed) break;
					}
				}
			}
			if(!prev[ed]) break;
			int flow = 9999'9999;
			for(int i=ed; i!=st; i=prev[i]){
				flow = min(flow, cap[prev[i]][i] - flo[prev[i]][i]);
			}
			for(int i=ed; i!=st; i=prev[i]){
				flo[prev[i]][i] += flow;
				flo[i][prev[i]] -= flow;
			}
			ans += flow;
		}
		printf("%d\n", ans);
	}
	return 0;
}