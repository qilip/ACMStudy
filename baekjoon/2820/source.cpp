#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> g[50'0010];
int money[50'0010];
pair<int, int> e[50'0010];

ll fenwick[50'0010];

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
	scanf("%d", &money[1]);
	for(int i=2;i<=n;i++){
		int a, b;
		scanf("%d %d", &a, &b);\
		money[i] = a;
		g[b].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		update(e[i].first, money[i]);
		update(e[i].first + 1, -money[i]);
	}
	for(int i=1;i<=m;i++){
		char c;
		scanf(" %c", &c);
		if(c == 'p'){
			int a, x;
			scanf("%d %d", &a, &x);
			update(e[a].first + 1, x);
			update(e[a].second + 1, -x);
		}else{
			int a;
			scanf("%d", &a);
			printf("%lld\n", query(e[a].first));
		}
	}
	
    return 0;
}
