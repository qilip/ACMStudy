#include <bits/stdc++.h>

using namespace std;

int nn[100'0010];

int main(void){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		v.emplace_back(a, i);
	}
	sort(v.begin(), v.end());
	int cnt = -1;
	int bef = -11'0000'0000;
	for(auto c: v){
		if(bef != c.first){
			bef = c.first;
			cnt++;
		}
		nn[c.second] = cnt;
	}
	for(int i=0;i<n;i++){
		printf("%d ", nn[i]);
	}
	return 0;
}
