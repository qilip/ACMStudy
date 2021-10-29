#include <bits/stdc++.h>

using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int nn[40010] = {0};
		for(int i=1;i<=n;i++){
			scanf("%d", &nn[i]);
		}
		vector<int> v;
		v.push_back(nn[1]);
		for(int i=2;i<=n;i++){
			if(v.back() < nn[i]) v.push_back(nn[i]);
			else{
				auto c = lower_bound(v.begin(), v.end(), nn[i]);
				*c = nn[i];
			}
		}
		printf("%d\n", (int)v.size());
	}
	return 0;
}
