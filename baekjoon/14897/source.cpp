#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, sq;
int a[100'0010];
int cnt[100'0010];
int now;
int ans[100'0010];

typedef struct Query{
	int a, b, i;
	Query(int qa, int qb, int qi): a(qa), b(qb), i(qi) {};
	bool operator< (const Query &o) const {
		if(a/sq != o.a/sq) return a/sq < o.a/sq;
		else return b < o.b;
	}
} query;


int main(void){
	scanf("%d", &n);
	sq = sqrt(n);
	vector<query> q;
	int zip = 1;
	unordered_map<int, int> mm;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		if(!mm[x]) mm[x] = zip++;
		a[i] = mm[x];
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int s, e;
		scanf("%d %d", &s, &e);
		q.push_back({s, e, i});
	}
	sort(q.begin(), q.end());
	int cs = q[0].a;
	int ce = q[0].b;
	for(int i=cs;i<=ce;i++){
		if(cnt[a[i]]++==0) now++;
	}
	for(auto cq : q){
		auto [s, e, i] = cq;
		while(cs > s) if(cnt[a[--cs]]++==0) now++;
		while(ce < e) if(cnt[a[++ce]]++==0) now++;
		while(cs < s) if(--cnt[a[cs++]]==0) now--;
		while(ce > e) if(--cnt[a[ce--]]==0) now--;
		ans[i] = now;
	}
	for(int i=0;i<m;i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}