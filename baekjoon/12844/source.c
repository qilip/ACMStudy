#include <stdio.h>

int tree[2000000];
int lazy[2000000];

void init(int cur, int idx, int val, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[cur] = val;
        return;
    }
    int m = (l+r)/2;
    init(cur*2, idx, val, l, m);
    init(cur*2+1, idx, val, m+1, r);
    tree[cur] = tree[cur*2] ^ tree[cur*2+1];
}

void lazy_update(int cur, int l, int r){
    if(!lazy[cur]) return;
    tree[cur] ^= (r-l+1)%2 ? lazy[cur] : 0;
    if(l!=r){
        lazy[cur*2] ^= lazy[cur];
        lazy[cur*2+1] ^= lazy[cur];
    }
    lazy[cur] = 0;
}

void update(int cur, int val, int ul, int ur, int l, int r){
    lazy_update(cur, l, r);
    if(ur<l || r<ul) return;
    if(ul<=l && r<=ur){
        tree[cur] ^= (r-l+1)%2 ? val : 0;
        if(l!=r){
            lazy[cur*2] ^= val;
            lazy[cur*2+1] ^= val;
        }
        return;
    }
    int m = (l+r)/2;
    update(cur*2, val, ul, ur, l, m);
    update(cur*2+1, val, ul, ur, m+1, r);
    tree[cur] = tree[cur*2] ^ tree[cur*2+1];
}

int find(int cur, int fl, int fr, int l, int r){
    lazy_update(cur, l, r);
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2,fl, fr, l, m) ^ find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        init(1, i, t, 0, n-1);
    }
    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if(a>b){
            int t = a;
            a = b;
            b = t;
        }
        if(t==1){
            int c;
            scanf("%d", &c);
            update(1, c, a, b, 0, n-1);
        }else{
            printf("%d\n", find(1, a, b, 0, n-1));
        }
    }
    return 0;
}
