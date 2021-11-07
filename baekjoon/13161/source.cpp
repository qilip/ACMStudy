#include <bits/stdc++.h>

using namespace std;

const int INF = 9'9999'9999;

int n;
int nn[510];

int s = 501, e = 502;
int cap[510][510], flo[510][510];
int level[510];
int nextv[510];
vector<int> g[510];

bool leveling(){
	fill(level, level+510, -1);
	level[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int nxt : g[cur]){
			if(level[nxt]==-1 && cap[cur][nxt]>flo[cur][nxt]){
				level[nxt] = level[cur]+1;
				q.push(nxt);
			}
		}
	}
	return level[e] != -1;
}

int flowing(int cur, int dst, int flow){
	if(cur==dst) return flow;
	for(int &i=nextv[cur]; i<(int)g[cur].size(); i++){
		int nxt = g[cur][i];
		if(level[cur]+1==level[nxt] && cap[cur][nxt]>flo[cur][nxt]){
			int resi = flowing(nxt, dst, min(flow, cap[cur][nxt]-flo[cur][nxt]));
			if(resi>0){
				flo[cur][nxt] += resi;
				flo[nxt][cur] -= resi;
				return resi;
			}
		}
	}
	return 0;
}

int main(void){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &nn[i]);
		if(nn[i]==1){
			cap[s][i] = INF;
			g[s].push_back(i);
			g[i].push_back(s);
		}else if(nn[i]==2){
			cap[i][e] = INF;
			g[i].push_back(e);
			g[e].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &cap[i][j]);
			if(i!=j) g[i].push_back(j);
		}
	}
	int ans = 0;
	while(leveling()){
		fill(nextv, nextv+510, 0);
		while(1){
			int flow = flowing(s, e, INF);
			if(!flow) break;
			ans += flow;
		}
	}
	bool pos[510] = {false};
	pos[s] = true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int nxt : g[cur]){
			if(!pos[nxt] && cap[cur][nxt]>flo[cur][nxt]){
				pos[nxt] = true;
				q.push(nxt);
			}
		}
	}
	printf("%d\n", ans);
	for(int i=1;i<=n;i++){
		if(pos[i]) printf("%d ", i);
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		if(!pos[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}
