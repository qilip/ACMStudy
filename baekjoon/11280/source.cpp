#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> g[20010];
stack<int> s;
int num[20010];
int fin[20010];
int sccn[20010];
int cnt, scnt;

int rev(int a){
	if(a>n+1) return a - (n+1);
	return a + n + 1;
}

int dfs(int cur){
	num[cur] = ++cnt;
	s.push(cur);
	int res = num[cur];
	for(int nxt : g[cur]){
		if(!num[nxt]) res = min(res, dfs(nxt));
		else if(!fin[nxt]) res = min(res, num[nxt]);
	}
	if(res == num[cur]){
		scnt++;
		while(1){
			int c = s.top();
			s.pop();
			fin[c] = 1;
			sccn[c] = scnt;
			if(c == cur) break;
		}
	}
	return res;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a<0) a = -a + n + 1;
		if(b<0) b = -b + n + 1;
		g[rev(a)].push_back(b);
		g[rev(b)].push_back(a);
	}
	for(int i=1;i<=n*2+1;i++){
		if(i==n+1) continue;
		if(!num[i]) dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(sccn[i] == sccn[rev(i)]){
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
    return 0;
}
