#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int cap[210][210];
int cost[210][210];
int flo[210][210];
vector<int> v[210];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int st = 1, ed = n+m+2;
	for(int i=m+2;i<=m+n+1;i++){
		scanf("%d", &cap[i][ed]);
		v[i].push_back(ed);
		v[ed].push_back(i);
	}
	for(int i=2;i<=m+1;i++){
		scanf("%d", &cap[st][i]);
		v[i].push_back(st);
		v[st].push_back(i);
	}
	for(int i=2;i<=m+1;i++){
		for(int j=m+2;j<=n+m+1;j++){
			int a;
			scanf("%d", &a);
			v[i].push_back(j);
			v[j].push_back(i);
			cap[i][j] = a;
		}
	}
	for(int i=2;i<=m+1;i++){
		for(int j=m+2;j<=n+m+1;j++){
			int a;
			scanf("%d", &a);
			cost[i][j] = a;
			cost[j][i] -= a;
		}
	}
	
	int maxf = 0, minc = 0;
	while(1){
		int visited[210] = {0};
		int dist[210];
		bool in_q[210] = {0};
		queue<int> q;
		fill(dist, dist+208, 9999'9999);
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
