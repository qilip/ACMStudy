#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int sq;
int cnt;
int cntn[100'0010];
int qres[10'0010];	

typedef struct Query{
	int a, b, i;
	Query(int qa, int qb, int qi): a(qa), b(qb), i(qi) {};
	bool operator< (const Query &o) const {
		int x = b / sq;
		int y = o.b / sq;
		return x==y ? a<o.a : x<y;
	}
} query;

int main(void){
	int n;
	scanf("%d", &n);
	sq = sqrt(n);
	int nn[10'0010] = {0};
	for(int i=0;i<n;i++){
		scanf("%d", &nn[i]);
	}
	int m;
	scanf("%d", &m);
	vector<query> vq;
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		vq.emplace_back(a-1, b, i);
	}
	sort(vq.begin(), vq.end());
	int a = vq[0].a;
	int b = vq[0].b;
	for(int i=a; i<b; i++){
		if(cntn[nn[i]]++ == 0) cnt++;
	}
	qres[vq[0].i] = cnt;
	for(int i=1;i<vq.size();i++){
		while(vq[i].a < a) if(cntn[nn[--a]]++ == 0) cnt++;
		while(vq[i].a > a) if(--cntn[nn[a++]] == 0) cnt--;
		while(vq[i].b > b) if(cntn[nn[b++]]++ == 0) cnt++;
		while(vq[i].b < b) if(--cntn[nn[--b]] == 0) cnt--;
		qres[vq[i].i] = cnt;
	}
	for(int i=0;i<m;i++){
		printf("%d\n", qres[i]);
	}
	
    return 0;
}