#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int tree[50'0010];
int lazy[50'0010];

void propagate(int nc, int nl, int nr){
	if(lazy[nc]){
		tree[nc] = (nr-nl+1) - tree[nc];
		if(nl != nr){
			lazy[nc*2] ^= lazy[nc];
			lazy[nc*2+1] ^= lazy[nc];
		}
		lazy[nc] = 0;
	}
}

void update(int l, int r, int val, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return;
	if(l <= nl && nr <= r){
		lazy[nc] ^= val;
		propagate(nc, nl, nr);
		return;
	}
	int mid = (nl+nr)>>1;
	update(l, r, val, nc*2, nl, mid);
	update(l, r, val, nc*2+1, mid+1, nr);
	tree[nc] = tree[nc*2] + tree[nc*2+1];
}

int query(int l, int r, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return 0;
	if(l <= nl && nr <= r) return tree[nc];
	int mid = (nl+nr)>>1;
	return query(l, r, nc*2, nl, mid) + query(l, r, nc*2+1, mid+1, nr);
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int o, s, t;
		scanf("%d %d %d", &o, &s, &t);
		if(!o){
			update(s, t, 1, 1, 1, n);
		}else{
			printf("%d\n", query(s, t, 1, 1, n));
		}
	}
	return 0;
}
