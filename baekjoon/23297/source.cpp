#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 70'2010;

int r, c, n;
vector<int> g[MAXN];
stack<int> s;
int num[MAXN];
int fin[MAXN];
int sccn[MAXN];
int rscn[MAXN];
int cnt, scnt;
vector<vector<int>> sccs;
vector<int> scs;
vector<string> ans;
int valid[MAXN];

int parse(string s){
    int a = 0;
    int b = 0;
    for(int i=0;i<(int)s.size();i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            a *= 26;
            a += s[i] - 'A' + 1;
        }else{
            b *= 10;
            b += s[i] - '0';
        }
    }
    return a + (b-1) * c;
}

string stringify(int s){
	string res;
	int b = (s-1) / c + 1;
	int a = (s-1) % c + 1;
	while(b){
		res += '0' + b % 10;
		b = b / 10;
	}
	while(a){
		res += 'A' + (a-1) % 26;
		a = (a-1) / 26;
	}
	reverse(res.begin(), res.end());
	return res;
}

int scc(int cur){
	num[cur] = ++cnt;
	s.push(cur);
	int res = num[cur];
	for(int nxt : g[cur]){
		if(!num[nxt]) res = min(res, scc(nxt));
		else if(!fin[nxt]) res = min(res, num[nxt]);
	}
	if(res == num[cur]){
		vector<int> cur_scc;
		scnt++;
		while(1){
			int c = s.top();
			s.pop();
			cur_scc.push_back(c);
			fin[c] = 1;
			sccn[c] = scnt;
			rscn[scnt] = c;
			if(c == cur) break;
		}
		if(cur_scc.size() > 1){
			sort(cur_scc.begin(), cur_scc.end());
			sccs.push_back(cur_scc);
		}
	}
	return res;
}

bool ractangle(vector<int>& v){
	int lt = v[0]; // 첫줄 왼쪽 끝
	pair<int, int> ltp = {(lt-1) / c + 1, (lt-1) % c + 1};
	int rt = v[0];
	auto [bb, ba] = ltp;
	ba--;
	for(auto& i : v){
		int b = (i-1) / c + 1;
		int a = (i-1) % c + 1;
		if(ltp.first == b && ltp.second < a) rt = i; // 첫줄 오른쪽 끝
		if(bb == b){
			if(ba != a-1) return false;
			ba = a;
		}else{
			//줄넘김
			if((rt-1)%c+1 != ba) return false;
			if(bb != b-1) return false;
			bb = b;
			if(ltp.second != a) return false;
			ba = a;
		}
	}
	if((rt-1)%c+1 != ba) return false;
	return true;
}

void propagate(int cur){
	for(int nxt : g[cur]){
		if(valid[cur] == -1 && valid[nxt] >= 0){
			valid[nxt] = -1;
			propagate(nxt);
		}
	}
}

int main(void){
    scanf("%d %d", &r, &c);
	n = r*c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            char ss[30] = {0};
            scanf(" %s", ss);
            string st = ss;
			if(st[0] == '.') continue;
			auto plus_pos = st.find('+');
			if(plus_pos == string::npos){
				g[parse(st)].push_back((i-1) * c + j);
			}else{
				int a = parse(st.substr(0, plus_pos));
				int b = parse(st.substr(plus_pos+1));
				g[a].push_back((i-1) * c + j);
				g[b].push_back((i-1) * c + j);
			}
        }
    }
    for(int i=1;i<=n;i++){
		if(!num[i]) scc(i);
    }
	for(auto &v : sccs){
		if(ractangle(v)){
			for(auto &i : v) valid[i] = 2;
			scs.push_back(v[0]);
		}
		else
			for(auto &i : v) valid[i] = -1;
	}
	for(int i=1;i<=n;i++){
		if(valid[i]) propagate(i);
	}
	for(auto i : scs) if(valid[i] == 2) valid[i] = 1;
	for(int i=1;i<=n;i++){
		if(valid[i]==0 || valid[i]==1) ans.push_back(stringify(i));
	}
	printf("%d\n", (int)ans.size());
	if(ans.empty()) return 0;
	sort(ans.begin(), ans.end());
	for(auto c : ans){
		printf("%s ", c.c_str());
	}
	printf("\n");
    return 0;
}
