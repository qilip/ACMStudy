#include <bits/stdc++.h>

using namespace std;

vector<int> g[1010];
stack<int> s;
int num[1010];
int fin[1010];
int cnt;
vector<vector<int>> sccs;

int scc(int cur){
	num[cur] = ++cnt;
	s.push(cur);
	int res = num[cur];
	for(int nxt : g[cur]){
		if(!num[nxt]) res = min(res, scc(nxt));
		else if(!fin[nxt]) res = min(res, num[nxt]);
	}
	if(res == num[cur]){
		vector<int> cscc;
		while(1){
			int c = s.top();
			s.pop();
			cscc.push_back(c);
			fin[c] = 1;
			if(c==cur) break;
		}
		if(cscc.size()>1)
			sccs.push_back(cscc);
	}
	return res;
}

int visited[1010];
int dfs(int cur){
	int dcnt = 1;
	for(auto nxt : g[cur]){
		if(!visited[nxt]){
			visited[nxt] = 1;
			dcnt += dfs(nxt);
		}
	}
	return dcnt;
}

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d", &a);
		g[a].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!num[i]) scc(i);
	}
	vector<pair<int, int>> vp;
	int sum = 0;
	for(auto &c : sccs){
		int st = c[0];
		visited[st] = 1;
		int ccnt = dfs(st);
		sum += ccnt;
		vp.emplace_back((int)c.size(), ccnt-(int)c.size());
	}
	vp.emplace_back(0, n-sum);
	int dp[1010] = {0};
	fill(dp, dp+1010, -1);
	dp[0] = 1;
	for(auto c : vp){
		for(int i=k;i>=0;i--){
			if(dp[i]<0) continue;
			for(int j=c.first; j<=c.first+c.second; j++){
				if(i+j>k) continue;
				dp[i+j] = 1;
			}
		}
	}
	for(int i=k;i>=0;i--){
		if(dp[i]>0){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
