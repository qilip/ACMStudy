#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[60];
int a[60];
int b[60];
int visited[60];
int only;

int dfs(int l){
	visited[l] = 1;
	for(int r : v[l]){
		if(l==1 && r!=only) continue;
		if(!b[r] || (!visited[b[r]] && dfs(b[r]))){
			a[l] = r;
			b[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(void){
	int n;
	scanf("%d", &n);
	vector<int> va;
	vector<int> vb;
	va.push_back(0);
	vb.push_back(0);
	int f = 0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d", &a);
		if(i==1 && !(a%2)){
			f = 1;
		}
		if((a+f)%2) va.push_back(a);
		else vb.push_back(a);
	}
	if(va.size()!=vb.size()){
		printf("-1\n");
		return 0;
	}
	int notPrime[3000] = { 0 };
	notPrime[1] = 1;
	for(int i=2;i<60;i++){
		if(notPrime[i]) continue;
		for(int j=i+i;j<3000;j+=i) notPrime[j] = 1;
	}
	for(int i=1;i<va.size();i++){
		for(int j=1;j<vb.size();j++){
			if(!notPrime[va[i]+vb[j]])
				v[i].push_back(j);
		}
	}
	vector<int> ans;
	for(int t=0;t<v[1].size();t++){
		only = v[1][t];
		fill(a, a+59, 0);
		fill(b, b+59, 0);
		int cnt = 0;
		for(int i=1;i<va.size();i++){
			if(!a[i]){
				fill(visited, visited+59, 0);
				if(dfs(i)) cnt++;
			}
		}
		if(cnt == n/2) ans.push_back(vb[only]);
	}
	if(ans.empty()){
		printf("-1\n");
		return 0;
	}
	sort(ans.begin(), ans.end());
	for(auto x : ans){
		printf("%d ", x);
	}
	return 0;
}