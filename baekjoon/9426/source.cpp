#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
int nn[25'0010];
int tree[25'0000];
ll ans;
const int MAXI = 65536;

void update(int pos, int val){
	int idx = pos + MAXI;
	tree[idx] += val;
	idx >>= 1;
	while(idx){
		tree[idx] = tree[idx<<1] + tree[idx<<1|1];
		idx>>=1;
	}
}

int query(){
	int l = 0, r = MAXI;
	int res = 0;
	int fk = (k+1)>>1;
	while(l<=r){
		int mid = (l+r)>>1;
		int cur = 0;
		int cl = 0, cr = mid;
		for(cl+=MAXI, cr+=MAXI;cl<=cr; cl>>=1, cr>>=1){
			if(cl&1) cur += tree[cl];
			if(~cr&1) cur += tree[cr];
			cl++; cr--;
		}
		if(cur < fk) l = mid + 1;
		if(cur >= fk){
			res = mid;
			r = mid - 1;
		}
	}
	return res;
}

int main(void){
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", &nn[i]);
	}
	for(int i=0;i<k;i++){
		update(nn[i], 1);
	}
	ans += query();
	for(int i=k;i<n;i++){
		update(nn[i-k], -1);
		update(nn[i], 1);
		ans += query();
	}
	printf("%lld", ans);
    return 0;
}