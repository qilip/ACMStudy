#include <bits/stdc++.h>

using namespace std;

int nxt[400'0010];

int zip(int cur){
	if(nxt[cur] == cur) return cur;
	return nxt[cur] = zip(nxt[cur]);
}

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> v;
	for(int i=0;i<m;i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
		nxt[i] = i;
	}
	nxt[m] = m;
	sort(v.begin(), v.end());
	for(int i=0;i<k;i++){
		int a;
		scanf("%d", &a);
		int f = upper_bound(v.begin(), v.end(), a) - v.begin();
		zip(f);
		int ans = nxt[f];
		nxt[f] = nxt[f]+1;
		printf("%d\n", v[ans]);
	}
	return 0;
}
