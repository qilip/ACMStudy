#include <bits/stdc++.h>

using namespace std;

int n, m;
// h는 짝수 w는 홀수
// 0 1 | 2 3 | 4 5 ...
vector<int> g[62];
stack<int> s;
int num[62];
int fin[62];
int sccn[62];
int cnt, scnt;

int rev(int a){
	if(a%2) return a-1;
	else return a+1;
}

int scc(int cur){
	num[cur] = ++cnt;
	s.push(cur);
	int res = num[cur];
	for(int nxt : g[cur]){
		if(!num[nxt]) res = min(res, scc(nxt));
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
	while(1){
		scanf("%d %d", &n, &m);
		if(!n && !m) break;
		for(int i=0;i<62;i++){
			g[i].clear();
			num[i] = fin[i] = sccn[i] = 0;
			cnt = 0, scnt = 0;
			
		}
		g[0].push_back(1);
		for(int i=0;i<m;i++){
			int a, b;
			char ap, bp;
			scanf("%d%c %d%c", &a, &ap, &b, &bp);
			a = ap == 'h' ? a * 2 : a * 2 + 1;
			b = bp == 'h' ? b * 2 : b * 2 + 1;
			g[rev(a)].push_back(b);
			g[rev(b)].push_back(a);
		}
		for(int i=0;i<n*2;i++){
			if(!num[i]) scc(i);
		}
		int flg = 0;
		for(int i=0;i<n;i++){
			if(sccn[i*2] == sccn[i*2+1]){
				printf("bad luck\n");
				flg = 1;
				break;
			}
		}
		if(flg) continue;
		vector<pair<int, int>> vp;
		int ans[62];
		fill(ans, ans+62, -1);
		for(int i=0;i<n*2;i++){
			vp.emplace_back(sccn[i], i);
		}
		sort(vp.begin(), vp.end(), greater<pair<int,int>>());
		for(auto p : vp){
			int c = p.second;
			if(ans[c/2]==-1) ans[c/2] = !(c%2);
		}
		for(int i=1;i<n;i++){
			if(ans[i]) printf("%dw ", i);
			else printf("%dh ", i);
		}
		printf("\n");
	}
    return 0;
}