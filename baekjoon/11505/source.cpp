#include <cstdio>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int n, m, k;
ll nn[300'0000];

void build() {
	for(int i=n-1;i>0;i--){
		nn[i] = nn[i<<1] * nn[i<<1|1] % MOD;
	}
}

int query(int l, int r){
	ll ret = 1;
	for(l+=n,r+=n;l<=r;l>>=1, r>>=1){
		if(l&1) ret = ret * nn[l] % MOD;
		if(!(r&1)) ret = ret * nn[r] % MOD;
		l++; r--;
	}
	return ret;
}

void update (int val, int idx){
	idx += n;
	nn[idx] = val;
	idx>>=1;
	while(idx){
		nn[idx] = nn[idx<<1] * nn[idx<<1|1] % MOD;
		idx>>=1;
	}
}

int main(void){
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<n;i++){
		scanf("%lld", &nn[i+n]);
	}
	build();
	for(int i=0;i<m+k;i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==1) update(c, b-1);
		else printf("%d\n", query(b-1, c-1));
	}
	return 0;
}