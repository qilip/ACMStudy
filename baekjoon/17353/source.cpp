#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q, bnd;
ll tree[60'0010];
ll lazy[60'0010];
ll lcnt[60'0010];

void propagate(int nc, int nl, int nr){
	if(lazy[nc]){
		if(nl != nr){
			lazy[nc*2] += lazy[nc];
			lcnt[nc*2] += lcnt[nc];
			lazy[nc*2+1] += lazy[nc] + (nr-nl+1)/2*lcnt[nc];
			lcnt[nc*2+1] += lcnt[nc];
		}else tree[nc] += lazy[nc];
		lazy[nc] = 0;
		lcnt[nc] = 0;
	}
}

void update(int l, int r, int val, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return;
	if(l <= nl && nr <= r){
		lazy[nc] += val;
		lcnt[nc]++;
		propagate(nc, nl, nr);
		return;
	}
	int mid = (nl+nr)>>1;
	update(l, r, val, nc*2, nl, mid);
	update(l, r, val+(nr-nl+1)/2, nc*2+1, mid+1, nr);
}

ll query(int l, int r, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return 0;
	if(l <= nl && nr <= r) return tree[nc];
	int mid = (nl+nr)>>1;
	return query(l, r, nc*2, nl, mid) + query(l, r, nc*2+1, mid+1, nr);
}

int main(void){
	scanf("%d", &n);
	bnd = 1;
	while(bnd < n) bnd<<=1;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		tree[bnd+i] = a;
	}
	scanf("%d", &q);
	for(int i=0;i<q;i++){
		int o;
		scanf("%d", &o);
		if(o==1){
			int a, b;
			scanf("%d %d", &a, &b);
			update(a, b, 1-a+1, 1, 1, bnd);
		}else{
			int a;
			scanf("%d", &a);
			printf("%lld\n", query(a, a, 1, 1, bnd));
		}
	}
	return 0;
}
