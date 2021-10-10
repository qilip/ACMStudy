#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int n, m, bnd;
ll tree[60'0010];
ll lazy[60'0010];
ll lbzy[60'0010];

void build(){
	for(int i=bnd-1;i>0;i--){
		tree[i] = (tree[i<<1] + tree[i<<1|1]) % MOD;
		lazy[i] = 1;
	}
}

void propagate(int nc, int nl, int nr){
	if(lazy[nc]!=1 || lbzy[nc]){
		tree[nc] = ((tree[nc]*lazy[nc]) % MOD + ((nr-nl+1) * lbzy[nc] % MOD)) % MOD;
		if(nl != nr){
			lazy[nc*2] = (lazy[nc*2] * lazy[nc]) % MOD;
			lbzy[nc*2] = (lbzy[nc*2] * lazy[nc] + lbzy[nc]) % MOD;
			lazy[nc*2+1] = (lazy[nc*2+1] * lazy[nc]) % MOD;
			lbzy[nc*2+1] = (lbzy[nc*2+1] * lazy[nc] + lbzy[nc]) % MOD;
		}
		lazy[nc] = 1;
		lbzy[nc] = 0;
	}
}

void update(int l, int r, int val, int op, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return;
	if(l <= nl && nr <= r){
		if(op==1) lbzy[nc] = (lbzy[nc] + val) % MOD;
		if(op==2) lazy[nc] = (lazy[nc] * val) % MOD, lbzy[nc] = (lbzy[nc] * val) % MOD;
		if(op==3) lazy[nc] = 0, lbzy[nc] = val;
		propagate(nc, nl, nr);
		return;
	}
	int mid = (nl+nr)>>1;
	update(l, r, val, op, nc*2, nl, mid);
	update(l, r, val, op, nc*2+1, mid+1, nr);
	tree[nc] = (tree[nc*2] + tree[nc*2+1]) % MOD;
}

ll query(int l, int r, int nc, int nl, int nr){
	propagate(nc, nl, nr);
	if(nr < l || r < nl) return 0;
	if(l <= nl && nr <= r) return tree[nc];
	int mid = (nl+nr)>>1;
	return (query(l, r, nc*2, nl, mid) + query(l, r, nc*2+1, mid+1, nr)) % MOD;
}

int main(void){
	scanf("%d", &n);
	bnd = 1;
	while(bnd < n) bnd<<=1;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		tree[bnd+i] = a;
		lazy[bnd+i] = 1;
	}
	build();
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int o;
		scanf("%d", &o);
		if(o==1){
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			update(x, y, v, 1, 1, 1, bnd);
		}
		if(o==2){
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			update(x, y, v, 2, 1, 1, bnd);
		}
		if(o==3){
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			update(x, y, v, 3, 1, 1, bnd);
		}
		if(o==4){
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(x, y, 1, 1, bnd));
		}
	}
	return 0;
}
