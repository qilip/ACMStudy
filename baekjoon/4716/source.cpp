#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
	while(1){
		int n, a[2];
		scanf("%d %d %d", &n, &a[0], &a[1]);
		if(n==0) break;
		int ans = 0;
		vector<pair<pair<int ,int>, pair<int, int>>> v;
		for(int i=0;i<n;i++){
			int k, q, p;
			scanf("%d %d %d", &k, &q, &p);
			v.push_back({{abs(q-p), k}, {q, p}});
		}
		sort(v.begin(), v.end(), greater<pair<pair<int, int>, pair<int, int>>>());
		for(auto c : v){
			int qp, k, q, p;
			tie(qp, k) = c.first;
			tie(q, p) = c.second;
			int m = min(a[q>p], k);
			a[q>p] -= m;
			ans += m * (q>p ? p : q);
			k -= m;
			a[q<p] -= k;
			ans += k * (q<p ? p : q);
		}
		printf("%d\n", ans);
	}
}
