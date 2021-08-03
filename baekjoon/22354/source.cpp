#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int n;
char s[30'0010];
int nn[30'0010];
int ne[30'0010];
ll score;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	scanf("%d", &n);
	scanf(" %s", s);
	for(int i=0;i<n;i++) scanf("%d", &nn[i]);
	int maxx = 0;
	int flg = 1;
	nn[0] = 0;
	for(int i=0;i<n-1;i++){
		if(s[i] != s[i+1]){
			if(flg){
				flg = 0;
				maxx = 0;
				nn[i] = 0;
				continue;
			}
			nn[i] = max(nn[i], maxx);
			maxx = 0;
		}else{
			maxx = max(maxx, nn[i]);
			nn[i] = 0;
		}
	}
	
	int nc = 0;
	for(int i=0;i<n-1;i++){
		if(nn[i]){
			ne[nc++] = nn[i];
			// printf("[%d:%d]", i, nn[i]);
		}
	}
	vector<pair<int, int>> v;
	for(int i=0;i<nc;i++){
		v.emplace_back(-ne[i], i);
	}
	sort(v.begin(), v.end());
	int cnt = nc/2 + nc%2;
	for(int i=0;i<cnt;i++){
		score -= v[i].first;
	}
	printf("%lld", score);
	return 0;
}