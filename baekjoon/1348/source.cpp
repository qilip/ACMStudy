#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v[110];
int vcos[110][110];
int a[110];
int b[110];
int visited[110];

int dfs(int l, int maxc){
	visited[l] = 1;
	for(int r : v[l]){
		if( maxc>=vcos[l][r] && (!b[r] || (!visited[b[r]] && dfs(b[r], maxc))) ){
			a[l] = r;
			b[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(void){
	int r, c;
	char rc[60][60] = {0};
	int pc[60][60] = {0};
	int pcnt = 0;
	fill(vcos[0], vcos[110], 20000);
	vector<pair<int, int>> st;
	scanf("%d %d", &r, &c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf(" %c", &rc[i][j]);
			if(rc[i][j]=='C') st.emplace_back(i, j);
			if(rc[i][j]=='P') pc[i][j] = ++pcnt;
		}
	}
	int ni[] = {-1, 0, 1, 0};
	int nj[] = {0, 1, 0, -1};
	int acnt = 0;
	for(auto cc : st){
		acnt++;
		int nc[60][60] = {0};
		queue<pair<int, int>> q;
		queue<int> qc;
		q.push(cc);
		qc.push(0);
		nc[cc.first][cc.second] = 1;
		while(!q.empty()){
			auto [cxi, cxj] = q.front();
			int cxc = qc.front();
			q.pop(); qc.pop();
			int nxc = cxc+1;
			for(int i=0;i<4;i++){
				int nxi = cxi+ni[i];
				int nxj = cxj+nj[i];
				if(!nc[nxi][nxj] && rc[nxi][nxj]!=0 && rc[nxi][nxj]!='X'){
					if(rc[nxi][nxj] == 'P'){
						v[acnt].push_back(pc[nxi][nxj]);
						vcos[acnt][pc[nxi][nxj]] = nxc;
					}
					nc[nxi][nxj] = 1;
					q.emplace(nxi, nxj);
					qc.push(nxc);
				}
			}
		}
	}
	
	int ans = -1;
	int bl = 0, br = 10000;
	while(bl<=br){
		int mid = (bl+br)>>1;
		int count = 0;
		fill(a, a+109, 0);
		fill(b, b+109, 0);
		for(int i=1;i<=acnt;i++){
			if(!a[i]){
				fill(visited, visited+109, 0);
				if(dfs(i, mid)) count++;
			}
		}
		if(count < acnt){
			bl = mid+1;
		}else{
			ans = mid;
			br = mid-1;
		}
	}
	printf("%d", ans);
    return 0;
}