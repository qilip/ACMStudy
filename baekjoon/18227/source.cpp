#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, c, q;
vector<int> g[20'0010];
pair<int, int> e[20'0010];
int depth[20'0010];

int dcnt = 0;
void dfs(int cur, int p, int dep){
	depth[cur] = dep;
	e[cur].first = ++dcnt;
	for(auto nxt : g[cur]){
		if(nxt != p)
			dfs(nxt, cur, dep+1);
	}
	e[cur].second = dcnt;
}

ll tree[40'0010];

void update(int p){
	p += n;
	tree[p] += 1;
	p >>= 1;
	while(p){
		tree[p] = tree[p<<1] + tree[p<<1|1];
		p>>=1;
	}
}

ll query(int l, int r){
	ll ans = 0;
	for(l += n, r += n; l<=r; l>>=1, r>>=1){
		if(l&1) ans += tree[l];
		if(~r&1) ans += tree[r];
		l++; r--;
	}
	return ans;
}

int main(void){
	scanf("%d %d", &n, &c);
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(c, 0, 1);
	scanf("%d", &q);
	for(int i=0;i<q;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 1){
			update(e[b].first-1);
		}else{
			printf("%lld\n", query(e[b].first-1, e[b].second-1)*depth[b]);
		}
	}
	
    return 0;
}
