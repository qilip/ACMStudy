#include <stdio.h>

typedef long long ll;

ll tree[800000];
int cnt[800000];

void update(int cur, int idx, int value, int l, int r){
    if(idx<l || r<idx) return;
    if(l == r){
        tree[cur] += value;
        cnt[cur] += 1;
        return;
    }
    int m = (l+r)/2;
    update(cur*2, idx, value, l, m);
    update(cur*2+1, idx, value, m+1, r);
    tree[cur] = tree[cur*2] + tree[cur*2+1];
    cnt[cur] = cnt[cur*2] + cnt[cur*2+1];
}

int count(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return cnt[cur];
    int m = (l+r)/2;
    return count(cur*2, fl, fr, l, m) + count(cur*2+1, fl, fr, m+1, r);
}

ll find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int n;
    ll ans = 1;
    int M = 1000000007;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        t++;
        update(1, t, t, 1, 200000);
        if(!i) continue;
        ll left = (ll)count(1, 1, t-1, 1, 200000)*t - (ll)find(1, 1, t-1, 1, 200000);
        ll right = (ll)find(1, t+1, 200000, 1, 200000) - (ll)count(1, t+1, 200000, 1, 200000)*t;
        ans *= (left+right)%M;
        ans %= M;
    }
    printf("%lld", ans);
    return 0;
}
