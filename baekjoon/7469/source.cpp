#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int bor;
vector<int> tree[60'0010];

void build(){
	for(int i=bor-1;i>0;i--){
		tree[i].resize(tree[i<<1].size() + tree[i<<1|1].size());
		merge(tree[i<<1].begin(), tree[i<<1].end(), tree[i<<1|1].begin(), tree[i<<1|1].end(), tree[i].begin());
	}
}

int query(int l, int r, int k, int nc, int nl, int nr){
	if(nl == nr) return nl;
	int lcnt = upper_bound(tree[nc*2].begin(), tree[nc*2].end(), r) - lower_bound(tree[nc*2].begin(), tree[nc*2].end(), l);
	// int rcnt = upper_bound(tree[nc*2+1].begin(), tree[nc*2+1].end(), r) - lower_bound(tree[nc*2+1].begin(), tree[nc*2+1].end(), l);
	// printf("[%d %d]", lcnt, rcnt);
	int mid = (nl+nr)>>1;
	if(k <= lcnt) return query(l, r, k, nc*2, nl, mid);
	else return query(l, r, k-lcnt, nc*2+1, mid+1, nr);
}

int main(void){
	scanf("%d %d", &n, &m);
	// int o[10'0010] = {0};
	pair<int, int> a[10'0010];
	// map<int, int> mm;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		// o[i] = x;
		a[i] = {x, i+1};
	}
	sort(a, a+n);
	bor = 1;
	while(bor<n) bor<<=1;
	for(int i=0;i<n;i++){
		// printf("|%d:%d=%d|", i, a[i].first, a[i].second);
		// mm[a[i].first] = i;
		tree[bor+i].push_back(a[i].second);
	}
	// printf("\n");
	build();
	for(int i=1;i<=m;i++){
		int ca, cb, k;
		scanf("%d %d %d", &ca, &cb, &k);
		// printf("<%d,%d>", ca, cb);
		printf("%d\n", a[query(ca, cb, k, 1, 0, bor-1)].first);
	}
	return 0;
}
