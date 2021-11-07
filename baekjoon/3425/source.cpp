#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXI = 1e9;

int main(void){
	cin.tie(0)->sync_with_stdio(0);
	int run = 1;
	while(1){
		vector<pair<string, int>> op;
		while(1){
			string s;
			int u = 0;
			cin >> s;
			if(s == "QUIT"){
				run = 0;
				break;
			}
			if(s == "END") break;
			if(s == "NUM") cin >> u;
			op.emplace_back(s, u);
		}
		if(!run) break;
		int n;
		cin >> n;
		while(n--){
			int c, err = 0;
			cin >> c;
			stack<ll> st;
			st.push(c);
			for(auto [opt, opr] : op){
				ll a, b;
				if(opt=="NUM") st.push(opr);
				if(opt=="POP"){
					if(st.size()<1) { err = 1; break; }
					st.pop();
				}
				if(opt=="INV"){
					if(st.size()<1) { err = 1; break; }
					st.top() = -st.top();
				}
				if(opt=="DUP"){
					if(st.size()<1) { err = 1; break; }
					st.push(st.top());
				}
				if(opt=="SWP"){
					if(st.size()<2) { err = 1; break; }
					a = st.top(); st.pop();
					b = st.top(); st.pop();
					st.push(a); st.push(b);
				}
				if(opt=="ADD"){
					if(st.size()<2) { err = 1; break; }
					a = st.top(); st.pop();
					b = st.top(); st.pop();
					st.push(a+b);
					if(abs(st.top())>MAXI) { err = 1; break; }
				}
				if(opt=="SUB"){
					if(st.size()<2) { err = 1; break; }
					a = st.top(); st.pop();
					b = st.top(); st.pop();
					st.push(b-a);
					if(abs(st.top())>MAXI) { err = 1; break; }
				}
				if(opt=="MUL"){
					if(st.size()<2) { err = 1; break; }
					a = st.top(); st.pop();
					b = st.top(); st.pop();
					st.push(a*b);
					if(abs(st.top())>MAXI) { err = 1; break; }
				}
				if(opt=="DIV"){
					if(st.size()<2) { err = 1; break; }
					a = st.top(); st.pop();
					b = st.top(); st.pop();
					if(!a) { err = 1; break; }
					st.push(b/a);
					if(abs(st.top())>MAXI) { err = 1; break; }
				}
				if(opt=="MOD"){
					if(st.size()<2) { err = 1; break; }
					a = st.top(); st.pop();
					b = st.top(); st.pop();
					if(!a) { err = 1; break; }
					st.push(b%a);
					if(abs(st.top())>MAXI) { err = 1; break; }
				}
			}
			if(st.size()!=1 || err) cout << "ERROR\n";
			else cout << st.top() << '\n';
		}
		cout << '\n';
	}
	return 0;
}
