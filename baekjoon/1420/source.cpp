#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, m;
int st, ed;
int sx, sy, ex, ey;
int nm[110][110];
vector<int> v[20010];
map<pair<int, int>, int> cap, flo;

void addEdge(int a, int b){
	v[a].push_back(b);
	v[b].push_back(a);
	cap[{a, b}] = 1;
	cap[{b, a}] = 0;
}

int main(void){
	scanf("%d %d", &n, &m);
	int cp = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cp += 2;
			char cur;
			addEdge(cp, cp+1);
			scanf(" %c", &cur);
			if(cur == 'K'){
				nm[i][j] = 1;
				st = cp+1;
				sx = i, sy = j;
			}
			if(cur == 'H'){
				nm[i][j] = 2;
				ed = cp;
				ex = i, ey = j;
			}
			if(cur == '.') nm[i][j] = 3;
			if(!nm[i][j]) continue;
			if(nm[i-1][j]){
				addEdge(cp+1, cp-m*2);
				addEdge(cp-m*2+1, cp);
			}
			if(nm[i][j-1]){
				addEdge(cp+1, cp-2);
				addEdge(cp-2+1, cp);
			}
		}
	}
	if(n+m == 2 || abs(sx-ex)+abs(sy-ey)==1 || !st || !ed){
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	while(1){
		int visited[20010] = {0};
		queue<int> q;
		q.push(st);
		while(!q.empty() && !visited[ed]){
			int cur = q.front();
			q.pop();
			for(int nxt : v[cur]){
				if(!visited[nxt] && cap[{cur, nxt}] - flo[{cur, nxt}] > 0){
					visited[nxt] = cur;
					q.push(nxt);
					if(nxt == ed) break;
				}
			}
		}
		if(!visited[ed]) break;
		int flow = 9999'9999;
		for(int i=ed; i!=st; i=visited[i]){
			flow = min(flow, cap[{visited[i], i}] - flo[{visited[i], i}]);
		}
		for(int i=ed; i!=st; i=visited[i]){
			flo[{visited[i], i}] += flow;
			flo[{i, visited[i]}] -= flow;
		}
		ans += flow;
	}
	printf("%d\n", ans);
    return 0;
}
