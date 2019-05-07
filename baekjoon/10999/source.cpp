#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tree[4'000'000];
ll lazy[4'000'000];

void set(int cur, int idx, ll val, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[cur] = val;
        return;
    }
    int m = (l+r)/2;
    set(cur*2, idx, val, l, m);
    set(cur*2+1, idx, val, m+1, r);
    tree[cur] = tree[cur*2] + tree[cur*2+1];
}

void chk_lazy(int cur, int l, int r){
    if(!lazy[cur]) return;
    tree[cur] += lazy[cur] * (r-l+1);
    if(l!=r){
        lazy[cur*2] += lazy[cur];
        lazy[cur*2+1] += lazy[cur];
    }
    lazy[cur] = 0;
}

void update(int cur, ll diff, int ul, int ur, int l, int r){
    chk_lazy(cur, l, r);
    if(ur<l || r<ul) return;
    if(ul<=l && r<=ur){
        tree[cur] += (r-l+1) * diff;
        if(l!=r){
            lazy[cur*2] += diff;
            lazy[cur*2+1] += diff;
        }
        return;
    }
    int m = (l+r)/2;
    update(cur*2, diff, ul, ur, l, m);
    update(cur*2+1, diff, ul, ur, m+1, r);
    tree[cur] = tree[cur*2] + tree[cur*2+1];
}

ll find(int cur, int fl, int fr, int l, int r){
    chk_lazy(cur, l, r);
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++){
        ll t;
        scanf("%lld", &t);
        set(1, i, t, 1, n);
    }
    for(int i=0;i<m+k;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a==1){
            ll d;
            scanf("%lld", &d);
            update(1, d, b, c, 1, n);
        }else{
            printf("%lld\n", find(1, b, c, 1, n));
        }
    }
    return 0;
}
