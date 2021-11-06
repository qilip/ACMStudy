#include <bits/stdc++.h>

using namespace std;

int main(void){
	int h, w;
	scanf("%d %d", &h, &w);
	char s[110][110] = {0};
	for(int i=0;i<h;i++){
		scanf(" %s", s[i]);
	}
	int ans = 0;
	for(int i=0;i<h;i++){
		int on = 0;
		for(int j=0;j<w;j++){
			if(s[i][j] == '\\' || s[i][j] == '/'){
				ans++;
				on ^= 1;
			}else{
				if(on) ans += 2;
			}
		}
	}
	printf("%d\n", ans/2);
	return 0;
}
