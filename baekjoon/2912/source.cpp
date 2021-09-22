#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
	int n, c;
	scanf("%d %d", &n, &c);
	srand((unsigned int)(n+c));
	int nn[30'0010] = {0};
	vector<vector<int>> v(c+1);
	for(int i=1;i<=n;i++){
		scanf("%d", &nn[i]);
		v[nn[i]].push_back(i);
	}
	int m;
	scanf("%d", &m);
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a==b){
			printf("yes %d\n", nn[a]);
			continue;
		}
		int ans = 0;
		for(int i=0;i<50;i++){
			int c = nn[a+rand()%(b-a)];
			int cnt = upper_bound(v[c].begin(), v[c].end(), b) - lower_bound(v[c].begin(), v[c].end(), a);
			if(cnt>(b-a+1)/2) ans = c;
		}
		if(ans == 0) printf("no\n");
		else printf("yes %d\n", ans);
	}
	
    return 0;
}