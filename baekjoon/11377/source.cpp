#include <bits/stdc++.h>

using namespace std;

signed main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout<<setprecision(8)<<fixed;
    
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> v[2010];
	int cap[2010][2010] = {0};
	int flo[2010][2010] = {0};
	int st = 1, br = 2, ed = n+m+3;
	v[st].push_back(br);
	v[br].push_back(st);
	cap[st][br] = k;
	for(int i=3;i<=n+2;i++){
		v[st].push_back(i);
		v[i].push_back(st);
		cap[st][i] = 1;
		//bridge
		v[br].push_back(i);
		v[i].push_back(br);
		cap[br][i] = 1;
		int a;
		scanf("%d", &a);
		for(int j=0;j<a;j++){
			int b;
			scanf("%d", &b);
			b += n+2;
			v[i].push_back(b);
			v[b].push_back(i);
			cap[i][b] = 1;
		}
	}
	for(int i=n+3;i<ed;i++){
		v[i].push_back(ed);
		v[ed].push_back(i);
		cap[i][ed] = 1;
	}
	
	int ans = 0;
	while(1){
		int visited[2010] = {0};
		queue<int> q;
		q.push(st);
		while(!q.empty() && !visited[ed]){
			int cur = q.front();
			q.pop();
			for(auto nxt : v[cur]){
				if(!visited[nxt] && cap[cur][nxt]-flo[cur][nxt]>0){
					q.push(nxt);
					visited[nxt] = cur;
					if(nxt == ed) break;
				}
			}
		}
		if(!visited[ed]) break;
		int flow = 9999'9999;
		for(int i=ed;i!=st;i=visited[i]){
			flow = min(flow, cap[visited[i]][i] - flo[visited[i]][i]);
		}
		for(int i=ed;i!=st;i=visited[i]){
			flo[visited[i]][i] += flow;
			flo[i][visited[i]] -= flow;
		}
		ans += flow;
	}
	printf("%d", ans);
    return 0;
}
