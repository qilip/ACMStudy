#include <stdio.h>

long long tree[4000010];

void update(long long node, long long l, long long r, long long idx, long long value){
    if(idx<l || r<idx) return;
    if(l==r){ tree[node] = value; return; }
    long long mid = (l+r)/2;
    update(node*2, l, mid, idx, value);
    update(node*2+1, mid+1, r, idx, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long find(long long node, long long l, long long r, long long fl, long long fr){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[node];
    long long mid = (l+r)/2;
    return find(node*2, l, mid, fl, fr) + find(node*2+1, mid+1, r, fl, fr);
}

long long main(void){
    long long N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);
    for(long long i=1;i<=N;i++){
        long long tmp;
        scanf("%lld", &tmp);
        update(1, 1, N, i, tmp);
    }
    for(long long i=1;i<=M+K;i++){
        long long a, b;
        long long c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a==1) update(1, 1, N, b, c);
        else printf("%lld\n", find(1, 1, N, b, (long long)c));
    }
    return 0;
}
