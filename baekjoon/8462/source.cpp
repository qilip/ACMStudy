#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, sq;
int a[20'0010];
int cnt[100'0010];
ll power;
ll ans[20'0010];

typedef struct Query{
	int a, b, i;
	Query(int qa, int qb, int qi): a(qa), b(qb), i(qi) {};
	bool operator< (const Query &o) const {
		if(a/sq != o.a/sq) return a/sq < o.a/sq;
		else return b < o.b;
	}
} query;

void add(int c){
	power -= (ll)cnt[a[c]] * cnt[a[c]] * a[c];
	cnt[a[c]]++;
	power += (ll)cnt[a[c]] * cnt[a[c]] * a[c];
}

void sub(int c){
	power -= (ll)cnt[a[c]] * cnt[a[c]] * a[c];
	cnt[a[c]]--;
	power += (ll)cnt[a[c]] * cnt[a[c]] * a[c];
}

int main(void){
	scanf("%d %d", &n, &m);
	sq = sqrt(n);
	vector<query> q;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
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
		ans[i] = power;
	}
	for(int i=0;i<m;i++){
		printf("%lld\n", ans[i]);
	}
	return 0;
}
