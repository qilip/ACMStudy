#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
	int n;
	scanf("%d", &n);
	int nn[10010] = {0};
	int su = 0;
	for(int i=0;i<n;i++){
		scanf("%d", &nn[i]);
		su += nn[i];
	}
	sort(nn, nn+n, greater<int>());
	int flg = 1;
	if(su != n*(n-1)/2) flg = -1;
	if(!nn[n-1] && !nn[n-2]) flg = -1;
	int q = n-1, p = 1;
	for(int i=0;i<n;i++){
		if(nn[i] > q) flg = -1;
		while(nn[i] < q) q--, p+=2;
		if(nn[i] == q){
			p--;
			if(!p) q--, p = 1;
		}
	}
	printf("%d\n", flg);
}
