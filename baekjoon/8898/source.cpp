#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[1010];
int a[1010];
int b[1010];
int visited[1010];

int n;
int ns[1010];
int nd[1010];

int aa[1010];
int bb[1010];

int dfs(int l){
	visited[l] = 1;
	for(int r : v[l]){
		if(!b[r] || (!visited[b[r]] && dfs(b[r]))){
			a[l] = r;
			b[r] = l;
			return 1;
		}
	}
	return 0;
}

void adfs(int l){
	aa[l] = 1;
	for(int r : v[l]){
		if(b[r] && !bb[r] && !aa[b[r]]){
			bb[r] = 1;
			adfs(b[r]);
		}
	}
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1;i<=n;i++) v[i].clear();
		fill(a, a+1009, 0);
		fill(b, b+1009, 0);
		fill(aa, aa+1009, 0);
		fill(bb, bb+1009, 0);
		for(int i=1;i<=n;i++) scanf("%d", &ns[i]);
		for(int i=1;i<=n;i++) scanf("%d", &nd[i]);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int t;
				scanf("%d", &t);
				if(ns[i]+nd[i]+t<=ns[j]) v[i].push_back(j);
				if(ns[j]+nd[j]+t<=ns[i]) v[j].push_back(i);
			}
		}
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				fill(visited, visited+1009, 0);
				if(dfs(i)) cnt++;
			}
		}
		printf("%d\n", n-cnt);
		// 실제 따라가면서 구하기
		for(int i=1;i<=n;i++){
			if(!a[i]) adfs(i);
		}
		
		for(int i=1;i<=n;i++){
			if(aa[i] && !bb[i]) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}