#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cap[60][60];
int flo[60][60];
int st = 51, ed = 52;

int main(void){
	int n;
	vector<vector<int>> g(60);
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char a;
			scanf(" %c", &a);
			if(a == '1'){
				g[i].push_back(j);
				cap[i][j] = 1;
			}
		}
	}
	int k;
	scanf("%d", &k);
	vector<int> src[60];
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d", &p);
		for(int j=0;j<p;j++){
			int a;
			scanf("%d", &a);
			src[a].push_back(i);
		}
	}
	vector<int> end[60];
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d", &p);
		int q[60] = {0};
		for(int j=0;j<p;j++){
			int a;
			scanf("%d", &a);
			q[a] = 1;
		}
		for(int j=0;j<k;j++){
			if(!q[j]) end[j].push_back(i);
		}
	}
	int ans = 0;
	for(int z=0;z<k;z++){
		// init graph
		auto cg = g;
		for(auto x : src[z]){
			cg[st].push_back(x);
			cg[x].push_back(st);
			cap[st][x] = 9999;
		}
		for(auto x : end[z]){
			cg[x].push_back(ed);
			cg[ed].push_back(x);
			cap[x][ed] = 9999;
		}
		
		while(1){
			int prev[60] = {0};
			queue<int> q;
			q.push(st);
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				for(int nxt : cg[cur]){
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
		
		// clear graph
		for(auto x : src[z]){
			cap[st][x] = 0;
		}
		for(auto x : end[z]){
			cap[x][ed] = 0;
		}
		fill(flo[0], flo[60], 0);
	}
	printf("%d\n", ans);
	return 0;
}