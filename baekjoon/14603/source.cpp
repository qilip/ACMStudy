#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m, n, k, w;
int mn[310][310];
int ans[310][310];
int tree[40'0000];

void update(int pos, int val){
	int idx = pos + k+1;
	tree[idx] += val;
	idx >>= 1;
	while(idx){
		tree[idx] = tree[idx<<1] + tree[idx<<1|1];
		idx>>=1;
	}
}

int query(){
	int l = 0, r = k+1;
	int res = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		int cur = 0;
		int cl = 0, cr = mid;
		// printf("<%d:%d>",cl,cr);
		for(cl+=k+1, cr+=k+1;cl<=cr; cl>>=1, cr>>=1){
			if(cl&1) cur += tree[cl];
			if(~cr&1) cur += tree[cr];
			cl++; cr--;
		}
		if(cur < w*w/2+1) l = mid + 1;
		if(cur >= w*w/2+1){
			res = mid;
			r = mid - 1;
		}
		// printf("[%d,%d]", cur, res);
	}
	// printf("\n");
	return res;
}

int main(void){
	scanf("%d %d %d %d", &m, &n, &k, &w);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &mn[i][j]);
		}
	}
	int cm = 0, cn = 0, np = 1, flg = 0;
	for(int i=0;i<w;i++){
		for(int j=0;j<w;j++){
			update(mn[i][j], 1);
		}
	}
	ans[0][0] = query();
	while(cm <= m-w){
		cn += np;
		if(n==w && cm==0){
			cn--;
			flg = 2;
		}
		if(cn > n-w) break;
		if(!flg){
			//np방향으로
			for(int i=0;i<w;i++){
				if(np>0){
					update(mn[cm+i][cn-1], -1);
					update(mn[cm+i][cn+w-1], 1);
				}else{
					update(mn[cm+i][cn+w], -1);
					update(mn[cm+i][cn], 1);
				}
			}
		}else if(flg==1){
			for(int i=0;i<w;i++){
				update(mn[cm-1][cn+i], -1);
				update(mn[cm+w-1][cn+i], 1);
			}
		}
		ans[cm][cn] = query();
		if(n==w) flg = 0;
		if(cn==n-w && !flg){
			cm++; np = -1; cn -= np; flg++;
		}else if(cm && cn==0 && !flg){
			cm++; np = 1; cn -= np; flg++;
		}else flg = 0;
	}
	for(int i=0;i<=m-w;i++){
		for(int j=0;j<=n-w;j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
    return 0;
}