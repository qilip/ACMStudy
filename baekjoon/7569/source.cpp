#include <bits/stdc++.h>

using namespace std;

const int DIM = 3;
const int MAXN = 1e6 + 10;

int nm[DIM];
int psnm[DIM+1] = {1, };
int n = 1;
int box[MAXN];
int cnt_zro;

int main(void){
	for(int i=0;i<DIM;i++){ cin >> nm[i]; n *= nm[i]; psnm[i+1] = psnm[i] * nm[i]; }
	for(int i=0;i<n;i++){ cin >> box[i]; cnt_zro += !box[i]; }
	queue<pair<int, int>> q;
	int day = 0;
	for(int i=0;i<n;i++) if(box[i]>0) q.emplace(i, 0);
	while(!q.empty()){
		auto [cur, c_day] = q.front(); q.pop(); day = c_day;
		for(int i=0;i<DIM;i++){
			int dim_dis = psnm[i];
			int dis_bnd = psnm[i+1] * (cur / psnm[i+1] + 1);
			for(int j : {-1,1}){
				int nxt = cur + j * dim_dis;
				if(0<=nxt && nxt<n && dis_bnd-psnm[i+1] <= nxt && nxt < dis_bnd && !box[nxt]){
					box[nxt] = 1;
					cnt_zro--;
					q.emplace(nxt, day+1);
				}
			}
		}
	}
	if(cnt_zro) cout << "-1\n";
	else cout << day << '\n';
	return 0;
}
