#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> tree[20'0000];

void build(){
	for(int i=n-1;i>0;i--){
		tree[i].resize(tree[i<<1].size() + tree[i<<1|1].size());
		merge(tree[i<<1].begin(), tree[i<<1].end(), tree[i<<1|1].begin(), tree[i<<1|1].end(), tree[i].begin());
	}
}

int query(int s, int e, int k){
	int cnt = 0;
	for(s+=n, e+=n; s<=e; s>>=1, e>>=1){
		if(s & 1) cnt += tree[s].end() - upper_bound(tree[s].begin(), tree[s].end(), k);
		if(~e & 1) cnt += tree[e].end() - upper_bound(tree[e].begin(), tree[e].end(), k);
		s++; e--;
	}
	return cnt;
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int c;
		scanf("%d", &c);
		tree[n+i].push_back(c);
	}
	build();
	int m;
	scanf("%d", &m);
	int bef = 0;
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a ^= bef;
		b ^= bef;
		c ^= bef;
		bef = query(a-1, b-1, c);
		printf("%d\n", bef);
	}
	
    return 0;
}
