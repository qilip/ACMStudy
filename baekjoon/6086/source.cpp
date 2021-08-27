#include <bits/stdc++.h>

using namespace std;

signed main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout<<setprecision(8)<<fixed;
    
	int n;
	scanf("%d", &n);
	vector<int> v[60];
	int to[60][60] = {0};
	int cu[60][60] = {0};
	for(int i=0;i<n;i++){
		char a, b;
		int c;
		scanf(" %c %c %d", &a, &b, &c);
		int aa = a <= 'Z' ? a - 'A' : a - 'a' + 26;
		int bb = b <= 'Z' ? b - 'A' : b - 'a' + 26;
		aa++, bb++; // 1 base
		to[aa][bb] = to[bb][aa] += c;
		v[aa].push_back(bb);
		v[bb].push_back(aa);
	}
	
	int ans = 0, st = 1, ed = 26;
	
	while(1){
		queue<int> q;
		q.push(st);
		int visit[60] = {0};
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
