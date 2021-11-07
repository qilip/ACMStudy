#include <bits/stdc++.h>

using namespace std;

int n;
int b[22][22] = {0};
pair<int, int> xy[] = {{0, -1}, {-1, 0}, {0, 0}, {1, 0}, {0, 1}};
	
int test(int cnt){
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i-1][j]){
				cnt++;
				for(auto[x, y]: xy){
					b[i+x][j+y] ^= 1;
				}
			}
		}
	}
	int ans = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]) ans = 0;
		}
	}
	return ans?cnt:-1;
}

int main(void){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &b[i][j]);
		}
	}
	int ans = 9999'9999;
	for(int i=0;i<=(1<<n)-1;i++){
		int bak[22][22] = {0};
		copy(&b[0][0], &b[21][22], &bak[0][0]);
		int cnt = 0;
		for(int j=0;j<=n-1;j++){
			if((i>>j)&1){
				cnt++;
				for(auto[x, y]: xy){
					b[1+x][n-j+y] ^= 1;
				}
			}
		}
		int res = test(cnt);
		if(res!=-1) ans = min(ans, res);
		copy(&bak[0][0], &bak[21][22], &b[0][0]);
	}
	if(ans==9999'9999) ans = -1;
	printf("%d\n", ans);
	return 0;
}
