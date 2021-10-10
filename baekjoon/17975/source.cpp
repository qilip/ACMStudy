#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MINT = -20'0000'0000;

typedef struct Node {
	ll lmax;
	ll rmax;
	ll tmax;
	ll sum;
} node;

node tree[2'0010];

void update(int idx, int val, int n, int nl, int nr){
	if(idx < nl || nr < idx) return;
	if(idx==nl && nr==idx){
		tree[n].lmax += val;
		tree[n].rmax += val;
		tree[n].tmax += val;
		tree[n].sum += val;
		return;
	}
	int mid = (nl+nr)>>1;
	update(idx, val, n*2, nl, mid);
	update(idx, val, n*2+1, mid+1, nr);
	tree[n].lmax = max(tree[n*2].lmax, tree[n*2].sum + tree[n*2+1].lmax);
	tree[n].rmax = max(tree[n*2+1].rmax, tree[n*2].rmax + tree[n*2+1].sum);
	tree[n].tmax = max({tree[n*2].tmax, tree[n*2+1].tmax, tree[n*2].rmax + tree[n*2+1].lmax});
	tree[n].sum = tree[n*2].sum + tree[n*2+1].sum;
}

node query(int l, int r, int n, int nl, int nr){
	if(r < nl || nr < l) return { MINT, MINT, MINT, MINT };
	if(l <= nl && nr <= r) return tree[n];
	int mid = (nl+nr)>>1;
	node left = query(l, r, n*2, nl, mid);
	node right = query(l, r, n*2+1, mid+1, nr);
	node cur;
	cur.lmax = max(left.lmax, left.sum + right.lmax);
	cur.rmax = max(right.rmax, left.rmax + right.sum);
	cur.tmax = max({left.tmax, right.tmax, left.rmax + right.lmax});
	cur.sum = left.sum + right.sum;
	return cur;
}

int main(void){
	int na;
	scanf("%d", &na);
	vector<pair<int, int>> n1;
	for(int i=0;i<na;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		n1.emplace_back(a, b);
	}
	int nb;
	scanf("%d", &nb);
	vector<pair<int, int>> n2;
	for(int i=0;i<nb;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		n2.emplace_back(a, b);
	}
	int c1, c2;
	scanf("%d %d", &c1, &c2);
	int n = na + nb;
	vector<pair<pair<int, int>, int>> v;
	vector<int> vy;
	map<int, int> m;
	int mcnt = 0;
	for(auto c : n1){
		v.push_back({{c.first, c.second}, c1});
		vy.push_back(c.second);
	}
	for(auto c : n2){
		v.push_back({{c.first, c.second}, -c2});
		vy.push_back(c.second);
	}
	sort(v.begin(), v.end());
	sort(vy.begin(), vy.end());
	for(int yc : vy){
		if(!m[yc])
			m[yc] = ++mcnt;
	}
	ll maxi = -99'9999'9999;
	for(int i=0;i<n;i++){
		if(i>0 && v[i-1].first.first == v[i].first.first) continue;
		fill(tree, tree+n*4, node{0,0,0,0});
		for(int j=i;j<n;j++){
			update(m[v[j].first.second], v[j].second, 1, 1, n);
			if(j<n-1 && v[j].first.first != v[j+1].first.first)
				maxi = max(maxi, tree[1].tmax);
			else if(j==n-1) maxi = max(maxi, tree[1].tmax);
		}
	}
	printf("%lld\n", maxi);
	return 0;
}