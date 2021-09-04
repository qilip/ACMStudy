#include <bits/stdc++.h>

using namespace std;

typedef struct Shark {
	int a, b, c, d;
	
	bool operator >= (struct Shark &o){
		if( a==o.a&&b==o.b&&c==o.c )
			return d>=o.d;
		return ( a>=o.a&&b>=o.b&&c>=o.c );
	}
} shark;

int cap[110][110];
int flo[110][110];
shark shk[60];

int main(void){
	int n;
	scanf("%d", &n);
	vector<int> v[110];
	int st = 1, ed = n+n+2;
	for(int i=2;i<=n+1;i++){
		v[st].push_back(i);
		v[i].push_back(st);
		cap[st][i] = 2;
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		shk[i] = {a, b, c, -i};
	}
	for(int i=n+2;i<ed;i++){
		v[i].push_back(ed);
		v[ed].push_back(i);
		cap[i][ed] = 1;
	}
	//shark
	for(int i=2;i<=n+1;i++){
		for(int j=2;j<=n+1;j++){
			if(i != j && shk[i] >= shk[j]){
				v[i].push_back(j+n);
				v[j+n].push_back(i);
				cap[i][j+n] = 1;
			}
		}
	}
	
	int ans = n;
	while(1){
		int visited[110] = {0};
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
		ans -= flow;
	}
	printf("%d", ans);
    return 0;
}
