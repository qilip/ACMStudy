#include <stdio.h>

long long tree[400005];

void update(int cur, int idx, long long value, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[cur] = value;
        return;
    }
    int m = (l+r)/2;
    update(cur*2, idx, value, l, m);
    update(cur*2+1, idx, value, m+1, r);
    tree[cur] = tree[cur*2] + tree[cur*2+1];
}

long long find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++){
        long long t;
        scanf("%lld", &t);
        update(1, i, t, 1, n);
    }
    for(int i=0;i<q;i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a>b){
            int t = a;
            a = b;
            b = t;
        }
        printf("%lld\n", find(1, a, b, 1, n));
        update(1, c, d, 1, n);
    }
    return 0;
}
