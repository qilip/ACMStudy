#include <bits/stdc++.h>

using namespace std;

int n = 10;
int b[20][20] = {0};
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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char c;
			scanf(" %c", &c);
			if(c=='O') b[i][j] = 1;
		}
	}
	int ans = 9999'9999;
	for(int i=0;i<=1023;i++){
		int bak[20][20] = {0};
		copy(&b[0][0], &b[19][20], &bak[0][0]);
		int cnt = 0;
		for(int j=0;j<=9;j++){
			if((i>>j)&1){
				cnt++;
				for(auto[x, y]: xy){
					b[1+x][10-j+y] ^= 1;
				}
			}
		}
		int res = test(cnt);
		if(res!=-1) ans = min(ans, res);
		copy(&bak[0][0], &bak[19][20], &b[0][0]);
	}
	if(ans==9999'9999) ans = -1;
	printf("%d\n", ans);
	return 0;
}
