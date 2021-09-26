#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	int nk[110] = {0};
	set<int> ka;
	for(int i=0;i<k;i++){
		int a;
		scanf("%d", &a);
		nk[i] = a;
	}
	int ans = 0;
	for(int i=0;i<k;i++){
		if(ka.find(nk[i]) != ka.end()) continue;
		if(ka.size() < n) ka.insert(nk[i]);
		else{
			int last = 0;
			int no = 0;
			for(auto c : ka){
				int cl = 0;
				for(int j=i+1;j<k;j++){
					if(c==nk[j]){
						cl = j;
						break;
					}
				}
				if(!cl) no = c;
				else if(last < cl) last = cl;
			}
			ans++;
			last = nk[last];
			if(no) last = no;
			ka.erase(ka.find(last));
			ka.insert(nk[i]);
		}
	}
	printf("%d", ans);
    return 0;
}