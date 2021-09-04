#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, m;
ll tree[20'0010];

void build(){
	for(int i=n-1;i>0;i--){
		tree[i] = tree[i<<1] + tree[i<<1|1];
	}
}

void update(int idx, int val){
	idx += n;
	tree[idx] = val;
	idx >>= 1;
	while(idx){
		tree[idx] = tree[idx<<1] + tree[idx<<1|1];
		idx >>= 1;
	}
}

ll query(int l, int r){
	ll ans = 0;
	for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
		if(l&1) ans += tree[l];
		if(~r&1) ans += tree[r];
		l++; r--;
	}
	return ans;
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &tree[i+n]);
	}
	build();
	scanf("%d", &m);
	vector<pair<int, int>> vu;
	vector<pair<pair<int, int>, pair<int, int>>> vq;
	vector<pair<int, ll>> v;
	for(int i=0;i<m;i++){
		int a;
		scanf("%d", &a);
		if(a==1){
			int x, k;
			scanf("%d %d", &x, &k);
			vu.emplace_back(x, k);
		}else{
			int k, s, e;
			scanf("%d %d %d", &k, &s, &e);
			vq.push_back({{k, i}, {s, e}});
		}
	}
	sort(vq.begin(), vq.end());
	int cur_u = 0;
	for(auto cur : vq){
		int k, i, s, e;
		tie(k, i) = cur.first;
		tie(s, e) = cur.second;
		while(k > cur_u){
			update(vu[cur_u].first-1, vu[cur_u].second);
			cur_u++;
		}
		v.emplace_back(i, query(s-1, e-1));
	}
	sort(v.begin(), v.end());
	for(auto cur : v){
		printf("%lld\n", cur.second);
	}
    return 0;
}
