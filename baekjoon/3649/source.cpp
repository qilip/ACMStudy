#include <bits/stdc++.h>

using namespace std;

int main(void){
	int x;
	while(scanf("%d", &x)==1){
		x *= 1000'0000;
		int n;
		scanf("%d", &n);
		int nn[100'0010] = {0};
		for(int i=0;i<n;i++) scanf("%d", &nn[i]);
		sort(nn, nn+n);
		int f = 0;
		for(int i=0;i<n;i++){
			if(binary_search(nn+i+1, nn+n, x-nn[i])){
				printf("yes %d %d\n", nn[i], x-nn[i]);
				f = 1;
				break;
			}
		}
		if(!f) printf("danger\n");
	}
	return 0;
}
