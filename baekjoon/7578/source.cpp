#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int a[1000010];
pair<int, int> b[1000010];
int tree[2000010];

void update(int cur, int idx, int value, int l, int r){
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

int find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d", &t);
        a[t] = i;
    }
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d", &t);
        b[i].first = a[t];
        b[i].second = i;
    }
    sort(b+1, b+n+1);
    long long sum = 0;
    for(int i=1;i<=n;i++){
        sum += find(1, b[i].second, n, 1, n);
        update(1, b[i].second, 1, 1, n);
    }
    printf("%lld", sum);
    return 0;
}
