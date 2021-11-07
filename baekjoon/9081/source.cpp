#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	scanf("%d", &n);
	while(n--){
		string s, o;
		cin >> s;
		o = s;
		int nxt = next_permutation(s.begin(), s.end());
		if(nxt) cout << s << '\n';
		else cout << o << '\n';
	}
	return 0;
}
