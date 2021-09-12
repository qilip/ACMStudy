#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> g[10'0010];
pair<int, int> e[10'0010];

ll fenwick[10'0010];

int dcnt = 0;
void dfs(int cur){
	e[cur].first = ++dcnt;
	for(auto nxt : g[cur]){
		dfs(nxt);
	}
	e[cur].second = dcnt;
}

void update(int i, int k){
	while(i <= n){
		fenwick[i] += k;
		i += (i & -i);
	}
}

ll query(int i){
	ll ans = 0;
	while(i){
		ans += fenwick[i];
		i -= (i & -i);
	}
	return ans;
}

int main(void){
	scanf("%d %d", &n, &m);
	int o;
	scanf("%d", &o);
	for(int i=2;i<=n;i++){
		int a;
		scanf("%d", &a);
		g[a].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		int d;
		scanf("%d", &d);
		if(d == 1){
			int a, x;
			scanf("%d %d", &a, &x);
			update(e[a].first, x);
			update(e[a].second + 1, -x);
		}else{
			int a;
			scanf("%d", &a);
			printf("%lld\n", query(e[a].first));
		}
	}
	
    return 0;
}
