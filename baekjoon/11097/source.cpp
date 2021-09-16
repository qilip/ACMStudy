#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> g[310];
stack<int> s;
int num[310];
int fin[310];
int sccn[310];
int rscn[310];
int cnt, scnt;
vector<pair<int, int>> ans;

int dfs(int cur){
	num[cur] = ++cnt;
	s.push(cur);
	int res = num[cur];
	for(int nxt : g[cur]){
		if(!num[nxt]) res = min(res, dfs(nxt));
		else if(!fin[nxt]) res = min(res, num[nxt]);
	}
	if(res == num[cur]){
		vector<int> cur_scc;
		scnt++;
		while(1){
			int c = s.top();
			s.pop();
			cur_scc.push_back(c);
			fin[c] = 1;
			sccn[c] = scnt;
			rscn[scnt] = c;
			if(c == cur) break;
		}
		int bef = cur_scc.back();
		for(int c : cur_scc){
			if(bef == c) break;
			ans.emplace_back(bef, c);
			bef = c;
		}
	}
	return res;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int m;
		scanf("%d", &m);
		for(int i=1;i<=m;i++){
			g[i].clear();
			for(int j=1;j<=m;j++){
				char a;
				scanf(" %c", &a);
				if(i==j) continue;
				if(a=='1') g[i].push_back(j);
			}
		}
		fill(num, num+308, 0);
		fill(fin, fin+308, 0);
		fill(sccn, sccn+308, 0);
		fill(rscn, rscn+308, 0);
		cnt = 0, scnt = 0;
		ans.clear();
		for(int i=1;i<=m;i++){
			if(!num[i]) dfs(i);
		}
		int ng[310][310] = {0};
		for(int i=1;i<=m;i++){
			for(int j : g[i]){
				if(sccn[i] != sccn[j]) ng[sccn[i]][sccn[j]] = 1;
			}
		}
		for(int i=1;i<=scnt;i++){
			for(int j=1;j<=scnt;j++){
				for(int k=1;k<=scnt;k++){
					if(ng[j][i] && ng[i][k]) ng[j][k] = 0;
				}
			}
		}
		for(int i=1;i<=scnt;i++){
			for(int j=1;j<=scnt;j++){
				if(ng[i][j]) ans.emplace_back(rscn[i], rscn[j]);
			}
		}
		printf("%d\n", (int)ans.size());
		for(auto i : ans){
			printf("%d %d\n", i.first, i.second);
		}
		printf("\n");
	}
    return 0;
}
