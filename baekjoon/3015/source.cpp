#include <cstdio>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

int main(void){
    int n;
	scanf("%d", &n);
	stack<pair<int, int>> st;
	long long ans = 0;
	while(n--){
		int a;
		scanf("%d", &a);
		if(st.empty()){
			st.emplace(a, 1);
			continue;
		}
		while(st.size() && st.top().first < a){
			ans += st.top().second;
			st.pop();
		}
		if(st.empty()){
			st.emplace(a, 1);
			continue;
		}
		if(st.top().first == a){
			if(st.size() > 1) ans++;
			ans += st.top().second;
			st.top().second++;
		}else{
			st.emplace(a, 1);
			ans++;
		}
	}
	printf("%lld", ans);
	return 0;	
}