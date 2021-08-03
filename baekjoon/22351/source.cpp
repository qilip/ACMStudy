#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

char s[3000] = {0};

int strint(int st, int cnt){
	int a = 0;
	for(int j=0;j<cnt;j++){ //?
		a *= 10;
		a += s[st+j] - '0';
	}
	return a;
}

int cnta(int num){
	int r = 0;
	while(num){
		num /= 10;
		r++;
	}
	return r;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	scanf("%s", s);
	for(int i=1;i<=3;i++){
		int flg = 1;
		int a = strint(0, i);
		int k = 1;
		for(int j=i;s[j]!=0;){
			int b = cnta(a+k);
			if(strint(j, b) != a+k){
				flg = 0;
				break;
			}
			j += b;
			k++;
		}
		if(flg){
			printf("%d %d", a, a+k-1);
			break;
		}
	}
	
	return 0;
}