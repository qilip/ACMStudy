#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> v[2010];
map<pair<int, int>, int> cap, cost, flo;

void addEdge(int a, int b, int c, int d){
	v[a].push_back(b);
	v[b].push_back(a);
	cap[{a, b}] = c;
	cap[{b, a}] = 0;
	cost[{a, b}] = d;
	cost[{b, a}] -= d;
}

int main(void){
	int n, m;
	while(scanf("%d %d", &n, &m)!=-1){
		for(int i=0;i<2010;i++) v[i].clear();
		cap.clear(); cost.clear(); flo.clear();
		int st = 2, ed = n*2;
		addEdge(st, st+1, 2, 0);
		for(int i=2;i<n;i++){
			addEdge(2*i, 2*i+1, 1, 0);
		}
		for(int i=0;i<m;i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			addEdge(2*a+1, 2*b, 1, c);
		}

		int minc = 0;
		while(1){
			int visited[2010] = {0};
			int dist[2010];
			bool in_q[2010] = {0};
			queue<int> q;
			fill(dist, dist+2008, 9999'9999);
			q.push(st);
			dist[st] = 0;
			in_q[st] = true;
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				in_q[cur] = false;
				for(int nxt : v[cur]){
					if(cap[{cur,nxt}] - flo[{cur,nxt}] > 0 && dist[nxt] > dist[cur] + cost[{cur,nxt}]){
						dist[nxt] = dist[cur] + cost[{cur,nxt}];
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
				flow = min(flow, cap[{visited[i],i}] - flo[{visited[i],i}]);
			}
			for(int i=ed;i!=st;i=visited[i]){
				minc += cost[{visited[i],i}] * flow;
				flo[{visited[i],i}] += flow;
				flo[{i,visited[i]}] -= flow;
			}
		}
		printf("%d\n", minc);
	}
	
    return 0;
}
