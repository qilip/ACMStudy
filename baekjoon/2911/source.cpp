#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
	int n, m;
	vector<pair<int, int>> v;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		int p, c;
		scanf("%d %d", &p, &c);
		v.emplace_back(p, c);
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	int bef = 0;
	for(auto cur : v){
		if(cur.second > bef) ans += cur.second - bef;
		bef = cur.second;
	}
	printf("%lld", ans);
    return 0;
}