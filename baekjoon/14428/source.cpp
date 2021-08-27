#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int n, m;
pair<int, int> nn[30'0000];

void build() {
	for(int i=n-1;i>0;i--){
		nn[i] = min(nn[i<<1], nn[i<<1|1]);
	}
}

pair<int, int> query(int l, int r){
	pair<int, int> ret = {1e9+7, 1e9+7};
	for(l+=n,r+=n;l<=r;l>>=1, r>>=1){
		if(l&1) ret = min(ret, nn[l]);
		if(!(r&1)) ret = min(ret, nn[r]);
		l++; r--;
	}
	return ret;
}

void update (int val, int idx){
	idx += n;
	nn[idx].first = val;
	idx>>=1;
	while(idx){
		nn[idx] = min(nn[idx<<1], nn[idx<<1|1]);
		idx>>=1;
	}
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &nn[i+n].first);
		nn[i+n].second = i;
	}
	build();
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==1) update(c, b-1);
		else printf("%d\n", query(b-1, c-1).second+1);
	}
	return 0;
}