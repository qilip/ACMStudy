#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int nn[50'0010][3];
vector<pair<int, pair<int, int>>> v;
int tree[100'0010];

void update(int pos, int val){
	int idx = pos + n;
	tree[idx] = val;
	idx >>= 1;
	while(idx){
		tree[idx] = min(tree[idx<<1], tree[idx<<1|1]);
		idx>>=1;
	}
}

int query(int c){
	int l = 0, r = c;
	int cur = 9999'9999;
	for(l+=n, r+=n;l<=r; l>>=1, r>>=1){
		if(l&1) cur = min(cur, tree[l]);
		if(~r&1) cur = min(cur, tree[r]);
		l++; r--;
	}
	return cur;
}

int main(void){
	scanf("%d", &n);
	fill(tree, tree+100'0008, 9999'9999);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			int a;
			scanf("%d", &a);
			nn[a-1][i] = j;
		}
	}
	for(int i=0;i<n;i++){
		v.push_back({nn[i][0], {nn[i][1], nn[i][2]}});
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(auto cur : v){
		auto [b, c] = cur.second;
		if(query(b) > c) ans++;
		update(b, c);
	}
	printf("%d", ans);
    return 0;
}