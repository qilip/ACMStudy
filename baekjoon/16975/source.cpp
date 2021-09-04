#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
ll tree[20'0010];

void update(int l, int r, int k){
	for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
		if(l&1) tree[l] += k;
		if(~r&1) tree[r] += k;
		l++; r--;
	}
}

ll query(int q){
	q += n;
	ll ans = 0;
	while(q){
		ans += tree[q];
		q>>=1;
	}
	return ans;
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &tree[n+i]);
	}
	int m;
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int q;
		scanf("%d", &q);
		if(q==1){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			update(a-1, b-1, c);
		}else{
			int a;
			scanf("%d", &a);
			printf("%lld\n", query(a-1));
		}
	}
	
    return 0;
}
