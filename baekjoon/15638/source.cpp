#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int notPrime[10'0010];

int main(void){
	int n;
	scanf("%d", &n);
	notPrime[0] = 1;
	notPrime[1] = 1;
	for(int i=2;i<=sqrt(n);i++){
		if(notPrime[i]) continue;
		for(int j=i*i;j<=n;j+=i){
			notPrime[j] = 1;
		}
	}
	if(notPrime[n]) printf("No\n");
	else printf("Yes\n");
}
