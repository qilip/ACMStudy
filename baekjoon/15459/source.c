#include <stdio.h>

typedef long long ll;

ll tree[400010];
ll ff[100010];

void update(int node, int l, int r, int idx, ll val){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[node] = val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2, l, mid, idx, val);
    update(node*2+1, mid+1, r, idx, val);
    tree[node] = tree[node*2] > tree[node*2+1] ? tree[node*2] : tree[node*2+1];
}

ll find(int node, int l, int r, int fl, int fr){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[node];
    int mid = (l+r)/2;
    ll le = find(node*2, l, mid, fl, fr);
    ll ri = find(node*2+1, mid+1, r, fl, fr);
    return le > ri ? le : ri;
}

int main(void){
    int n;
    ll m;
    scanf("%d %lld", &n, &m);
    for(int i=1;i<=n;i++){
        ll f, s;
        scanf("%lld %lld", &f, &s);
        ff[i] = f;
        update(1, 1, n, i, s);
    }
    ll fla = 0, stt = 1;
    ll ans = 1e10, maxx;
    for(int i=1;i<=n;i++){
        fla += ff[i];
        while(fla-ff[stt]>=m){
            fla -= ff[stt++];
        }
        if(fla>=m){
            maxx = find(1, 1, n, stt, i);
            if(ans>maxx) ans = maxx;
        }
    }
    printf("%lld", ans);
    return 0;
}
