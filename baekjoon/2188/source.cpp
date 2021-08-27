#include <bits/stdc++.h>

using namespace std;

signed main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout<<setprecision(8)<<fixed;
    
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> v[410];
	int to[410][410] = {0};
	int cu[410][410] = {0};
	int st = 1, ed = n+m+2;
	for(int i=2;i<=n+1;i++){
		v[1].push_back(i);
		v[i].push_back(1);
		to[1][i] = 1;
		to[i][1] = 0;
		int t;
		scanf("%d", &t);
		for(int j=0;j<t;j++){
			int a;
			scanf("%d", &a);
			a += n+1;
			to[i][a] = 1;
			to[a][i] = 0;
			v[i].push_back(a);
			v[a].push_back(i);
		}
	}
	for(int i=n+2;i<ed;i++){
		v[i].push_back(ed);
		v[ed].push_back(i);
		to[i][ed] = 1;
		to[ed][i] = 0;
	}
	
	int ans = 0;
	
	while(1){
		queue<int> q;
		q.push(st);
		int visit[410] = {0};
		while(!q.empty() && !visit[ed]){
			int cur = q.front();
			q.pop();
			for(auto nxt : v[cur]){
				if(!visit[nxt] && to[cur][nxt] - cu[cur][nxt] > 0){
					q.push(nxt);
					visit[nxt] = cur;
					if(nxt == ed) break;
				}
			}
		}
		if(!visit[ed]) break;
		
		int flow = 9999'9999;
		for(int i=ed; i!=st; i=visit[i]){
			flow = min(flow, to[visit[i]][i] - cu[visit[i]][i]);
		}
		for(int i=ed; i!=st; i=visit[i]){
			cu[visit[i]][i] += flow;
			cu[i][visit[i]] -= flow;
		}
		ans += flow;
	}
	printf("%d", ans);
    return 0;
}
