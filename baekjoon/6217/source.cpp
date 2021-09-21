#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, i, h, r;
	scanf("%d %d %d %d", &n, &i, &h, &r);
	vector<pair<int, int>> v;
    vector<pair<int, int>> vq;
	for(int a=0;a<r;a++){
		int q, p;
		scanf("%d %d", &q, &p);
		if(q > p) swap(q, p);
		if(q+1 < p){
			vq.emplace_back(q+1, p);
		}
	}
    sort(vq.begin(), vq.end());
    vq.erase(unique(vq.begin(), vq.end()), vq.end());
    for(auto c : vq){
        v.emplace_back(c.first, 0);
        v.emplace_back(c.second, 1);
    }
	sort(v.begin(), v.end());
	int cnt = 0;
	int vp = 0;
	for(int a=1;a<=n;a++){
		for(;vp<(int)v.size()&&a == v[vp].first;vp++){
			if(v[vp].second) cnt--;
			else cnt++;
		}
		printf("%d\n", h-cnt);
	}
    return 0;
}