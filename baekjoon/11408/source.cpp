#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int cap[810][810];
int cost[810][810];
int flo[810][810];
vector<int> v[810];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int st = 1, ed = n+m+2;
	for(int i=2;i<=n+1;i++){
		v[st].push_back(i);
		v[i].push_back(st);
		cap[st][i] = 1;
		int can = 0;
		scanf("%d", &can);
		for(int j=0;j<can;j++){
			int nu, cs;
			scanf("%d %d", &nu, &cs);
			v[i].push_back(n+1+nu);
			v[n+1+nu].push_back(i);
			cap[i][n+1+nu] = 1;
			cost[i][n+1+nu] = cs;
			cost[n+1+nu][i] -= cs;
		}
	}
	for(int i=n+2;i<=n+m+1;i++){
		v[i].push_back(ed);
		v[ed].push_back(i);
		cap[i][ed] = 1;
	}
	
	int maxf = 0, minc = 0;
	while(1){
		int visited[810] = {0};
		int dist[810];
		bool in_q[810] = {0};
		queue<int> q;
		fill(dist, dist+808, 9999'9999);
		q.push(st);
		dist[st] = 0;
		in_q[st] = true;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			in_q[cur] = false;
			for(int nxt : v[cur]){
				if(cap[cur][nxt] - flo[cur][nxt] > 0 && dist[nxt] > dist[cur] + cost[cur][nxt]){
					dist[nxt] = dist[cur] + cost[cur][nxt];
					visited[nxt] = cur;
					if(!in_q[nxt]){
						q.push(nxt);
						in_q[nxt] = true;
					}
				}
			}
		}
		if(!visited[ed]) break;
		
		int flow = 9999'9999;
		for(int i=ed;i!=st;i=visited[i]){
			flow = min(flow, cap[visited[i]][i] - flo[visited[i]][i]);
		}
		for(int i=ed;i!=st;i=visited[i]){
			minc += cost[visited[i]][i] * flow;
			flo[visited[i]][i] += flow;
			flo[i][visited[i]] -= flow;
		}
		maxf += flow;
	}
	printf("%d\n%d", maxf, minc);
    return 0;
}
