#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
	int n, k;
	int ar[110] = {0};
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		int m = ar[0];
		int mi = 0;
		for(int j=1;j<k;j++){
			if(m-a<0) continue;
			if(m-a > ar[j]-a) m = ar[j], mi = j;
		}
		if(m > a){
			printf("NO\n");
			return 0;
		}else{
			ar[mi] = a;
		}
	}
	printf("YES\n");
}
