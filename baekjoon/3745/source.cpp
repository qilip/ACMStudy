#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	while(scanf("%d", &n)==1){
		int nn[10'0010] = {0};
		int lis[10'0010] = {0};
		int lcnt = 0;
		for(int i=1;i<=n;i++){
			scanf("%d", &nn[i]);
		}
		lis[0] = nn[1];
		lcnt = 1;
		for(int i=2;i<=n;i++){
			lis[lower_bound(lis, lis+lcnt, nn[i]) - lis] = nn[i];
			if(lis[lcnt]) lcnt++;
		}
		printf("%d\n", lcnt);
	}
	return 0;
}
