#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void){
	int n, k;
	int nw[110] = {0};
	int nv[110] = {0};
	int nk[10'0010];
	fill(nk, nk+10'0008, -1);
	nk[0] = 0;
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d %d", &nw[i], &nv[i]);
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=k-nw[i];j>=0;j--){
			if(nk[j]>-1) nk[j+nw[i]] = max(nk[j+nw[i]], nk[j] + nv[i]);
			ans = max(ans, nk[j+nw[i]]);
		}
	}
	printf("%d", ans);
    return 0;
}
