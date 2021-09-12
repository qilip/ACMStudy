#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[50'0010];
int n, d;
int sa[50'0010];
int pos[50'0010];
int lcp[50'0010];

bool cmp(int a, int b){
	if(pos[a] != pos[b]) return pos[a] < pos[b];
	a += d;
	b += d;
	return (a<n&&b<n) ? (pos[a] < pos[b]) : (a>b);
}

int main(void){
	scanf(" %s", s);
	n = strlen(s);
	for(int i=0;i<n;i++){
		sa[i] = i;
		pos[i] = s[i];
	}
	d = 1;
	while(1){
		sort(sa, sa+n, cmp);
		int tmp[50'0010] = {0};
		for(int i=0;i<n-1;i++){
			tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
		}
		for(int i=0;i<n;i++){
			pos[sa[i]] = tmp[i];
		}
		if(tmp[n-1] == n-1) break;
		d*=2;
	}
	
	for(int i=0, k=0;i<n;i++,k=max(k-1, 0)){
		if(pos[i] == n-1) continue;
		int j = sa[pos[i]+1];
		while(s[i+k] == s[j+k]) k++;
		lcp[pos[i]] = k;
	}
	
	for(int i=0;i<n;i++){
		printf("%d ", sa[i]+1);
	}
	printf("\n");
	printf("x ");
	for(int i=0;i<n-1;i++){
		printf("%d ", lcp[i]);
	}
    return 0;
}
