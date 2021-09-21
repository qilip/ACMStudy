#include <bits/stdc++.h>

using namespace std;

int main(void){
    char s[210] = {0};
	scanf(" %s", s);
	int len = strlen(s);
	stack<int> st;
	vector<pair<int, int>> v;
	for(int i=len-1;i>=0;i--){
		if(s[i]==')') st.push(i);
		if(s[i]=='('){
			v.emplace_back(st.top(), i);
			st.pop();
		}
	}
	int cnt = (1<<v.size()) - 1;
	vector<string> sv(cnt);
	for(int i=1;i<=cnt;i++){
		bool no[210] = {0};
		for(int j=i,k=0;j>0;j>>=1,k++){
			if(~j&1) continue;
			auto [a, b] = v[k];
			no[a] = true, no[b] = true;
		}
		for(int j=0;j<len;j++){
			if(!no[j]) sv[i-1] += s[j];
		}
	}
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());
	for(auto c : sv){
		cout << c << '\n';
	}
    return 0;
}
