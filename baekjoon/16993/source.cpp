#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MINT = -10'0000'0000;

int n, m;

typedef struct Node {
	ll lmax;
	ll rmax;
	ll tmax;
	ll sum;
} node;

node tree[40'0010];

void update(int idx, int val, int n, int nl, int nr){
	if(idx < nl || nr < idx) return;
	if(idx==nl && nr==idx){
		tree[n].lmax = val;
		tree[n].rmax = val;
		tree[n].tmax = val;
		tree[n].sum = val;
		return;
	}
	int mid = (nl+nr)>>1;
	update(idx, val, n*2, nl, mid);
	update(idx, val, n*2+1, mid+1, nr);
	tree[n].lmax = max(tree[n*2].lmax, tree[n*2].sum + tree[n*2+1].lmax);
	tree[n].rmax = max(tree[n*2+1].rmax, tree[n*2].rmax + tree[n*2+1].sum);
	tree[n].tmax = max({tree[n*2].tmax, tree[n*2+1].tmax, tree[n*2].rmax + tree[n*2+1].lmax});
	tree[n].sum = tree[n*2].sum + tree[n*2+1].sum;
}

node query(int l, int r, int n, int nl, int nr){
	if(r < nl || nr < l) return { MINT, MINT, MINT, MINT };
	if(l <= nl && nr <= r) return tree[n];
	int mid = (nl+nr)>>1;
	node left = query(l, r, n*2, nl, mid);
	node right = query(l, r, n*2+1, mid+1, nr);
	node cur;
	cur.lmax = max(left.lmax, left.sum + right.lmax);
	cur.rmax = max(right.rmax, left.rmax + right.sum);
	cur.tmax = max({left.tmax, right.tmax, left.rmax + right.lmax});
	cur.sum = left.sum + right.sum;
	return cur;
}

int main(void){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d", &a);
		update(i, a, 1, 1, n);
	}
	scanf("%d", &m);
	for(int i=1;i<=m;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", query(a, b, 1, 1, n).tmax);
	}
	
	return 0;
}