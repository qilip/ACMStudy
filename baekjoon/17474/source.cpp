#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Segment Tree Beats

typedef struct Node {
	ll fmx; // 첫번째로 큰 value
	ll smx; // 두번째로 큰 value
	ll cmx; // max value count
	ll sum; // 합
} node;

node tree[400'0010];
int n, m;
int nn[100'0010];

// Merge node
node mg(node a, node b){
	if(a.fmx == b.fmx) return {a.fmx, max(a.smx, b.smx), a.cmx + b.cmx, a.sum + b.sum};
	if(a.fmx > b.fmx) swap(a, b);
	return {b.fmx, max(a.fmx, b.smx), b.cmx, a.sum + b.sum};
}

node build(int nc, int nl, int nr){
	if(nl == nr) return tree[nc] = {nn[nl], -1, 1, nn[nl]};
	int mid = (nl+nr)>>1;
	return tree[nc] = mg(build(nc*2, nl, mid), build(nc*2+1, mid+1, nr));
}

void propagate(int nc, int nl, int nr){
	if(nl == nr) return;
	if(tree[nc].fmx < tree[nc*2].fmx){
		tree[nc*2].sum -= tree[nc*2].cmx * (tree[nc*2].fmx - tree[nc].fmx);
		tree[nc*2].fmx = tree[nc].fmx;
	}
	if(tree[nc].fmx < tree[nc*2+1].fmx){
		tree[nc*2+1].sum -= tree[nc*2+1].cmx * (tree[nc*2+1].fmx - tree[nc].fmx);
		tree[nc*2+1].fmx = tree[nc].fmx;
	}
}

void update(int l, int r, int val, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl || tree[nc].fmx <= val) return; // break condition
	if(l <= nl && nr <= r && tree[nc].smx < val){ // tag condition
		tree[nc].sum -= tree[nc].cmx * (tree[nc].fmx - val);
		tree[nc].fmx = val;
		propagate(nc, nl, nr);
		return;
	}
	int mid = (nl+nr)>>1;
	update(l, r, val, nc*2, nl, mid);
	update(l, r, val, nc*2+1, mid+1, nr);
	tree[nc] = mg(tree[nc*2], tree[nc*2+1]);
}

ll get_max(int l, int r, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return 0;
	if(l <= nl && nr <= r) return tree[nc].fmx;
	int mid = (nl+nr)>>1;
	return max(get_max(l, r, nc*2, nl, mid), get_max(l, r, nc*2+1, mid+1, nr));
}

ll get_sum(int l, int r, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return 0;
	if(l <= nl && nr <= r) return tree[nc].sum;
	int mid = (nl+nr)>>1;
	return get_sum(l, r, nc*2, nl, mid) + get_sum(l, r, nc*2+1, mid+1, nr);
}

int main(void){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &nn[i]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int o;
		scanf("%d", &o);
		if(o==1){
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			update(l, r, x, 1, 1, n);
		}
		if(o==2){
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", get_max(l, r, 1, 1, n));
		}
		if(o==3){
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", get_sum(l, r, 1, 1, n));
		}
	}	
	return 0;
}
