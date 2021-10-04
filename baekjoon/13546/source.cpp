#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, m, sq;
int a[19'0010];
list<int> dk[19'0010];
int dsu[19'0010];
int dsq[400];
int ans[19'0010];

typedef struct Query{
	int a, b, i;
	Query(int qa, int qb, int qi): a(qa), b(qb), i(qi) {};
	bool operator< (const Query &o) const {
		if(a/sq != o.a/sq) return a/sq < o.a/sq;
		else return b < o.b;
	}
} query;

void add(int c, int is_f){
	auto &bk = dk[a[c]];
	if(!bk.empty()){
		int di = bk.front() - bk.back();
		dsu[di]--;
		dsq[di/sq]--;
	}
	if(is_f) bk.push_front(c);
	else bk.push_back(c);
	int dj = bk.front() - bk.back();
	dsu[dj]++;
	dsq[dj/sq]++;
}

void sub(int c, int is_f){
	auto &bk = dk[a[c]];
	int di = bk.front() - bk.back();
	dsu[di]--;
	dsq[di/sq]--;
	if(is_f) bk.pop_front();
	else bk.pop_back();
	if(!bk.empty()){
		int dj = bk.front() - bk.back();
		dsu[dj]++;
		dsq[dj/sq]++;
	}
}

int main(void){
	scanf("%d %d", &n, &k);
	sq = sqrt(n);
	vector<query> q;
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
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
		add(i, 1);
	}
	for(auto cq : q){
		auto [s, e, i] = cq;
		while(cs > s) add(--cs, 0);
		while(ce < e) add(++ce, 1);
		while(cs < s) sub(cs++, 0);
		while(ce > e) sub(ce--, 1);
		int res = 0;
		for(int i=399;i>=0;i--){
			if(dsq[i]){
				for(int j=sq-1;j>=0;j--){
					if(dsu[sq*i+j]){
						res = sq*i+j;
						goto E;
					}
				}
			}
		}
		E:;
		ans[i] = res;
	}
	for(int i=0;i<m;i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}