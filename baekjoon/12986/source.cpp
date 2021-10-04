#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, sq;
int a[20'0010];
int cnt[20'0010];
int maxc[10'0010];
int maxx;
int ans[20'0010];

typedef struct Query{
	int a, b, i;
	Query(int qa, int qb, int qi): a(qa), b(qb), i(qi) {};
	bool operator< (const Query &o) const {
		if(a/sq != o.a/sq) return a/sq < o.a/sq;
		else return b < o.b;
	}
} query;

void add(int c){
	maxc[cnt[a[c]]]--;
	cnt[a[c]]++;
	maxc[cnt[a[c]]]++;
	if(maxx < cnt[a[c]]) maxx = cnt[a[c]];
}

void sub(int c){
	maxc[cnt[a[c]]]--;
	if(!maxc[cnt[a[c]]] && cnt[a[c]] == maxx) maxx--;
	cnt[a[c]]--;
	maxc[cnt[a[c]]]++;
}

int main(void){
	scanf("%d %d", &n, &m);
	sq = sqrt(n);
	vector<query> q;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		a[i] = x+10'0001;
	}
	for(int i=0;i<m;i++){
		int s, e;
		scanf("%d %d", &s, &e);
		q.push_back({s, e, i});
	}
	sort(q.begin(), q.end());
	int cs = q[0].a;
	int ce = q[0].b;
	for(int i=cs;i<=ce;i++){
		add(i);
	}
	for(auto cq : q){
		auto [s, e, i] = cq;
		while(cs > s) add(--cs);
		while(ce < e) add(++ce);
		while(cs < s) sub(cs++);
		while(ce > e) sub(ce--);
		ans[i] = maxx;
	}
	for(int i=0;i<m;i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}