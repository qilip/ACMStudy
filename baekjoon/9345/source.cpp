#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> tree[400000];
int disk[100010];

void update(int cur, int idx, int value, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[cur] = {value, value};
        return;
    }
    int m = (l+r)/2;
    update(cur*2, idx, value, l, m);
    update(cur*2+1, idx, value, m+1, r);
    tree[cur] = {max(tree[cur*2].first, tree[cur*2+1].first),
                min(tree[cur*2].second, tree[cur*2+1].second)};
}

pair<int, int> find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return {-1, 99999999};
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    auto left = find(cur*2, fl, fr, l, m);
    auto right = find(cur*2+1, fl, fr, m+1, r);
    return {max(left.first, right.first),
            min(left.second, right.second)};
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++) tree[i] = {-1, 99999999};
        for(int i=0;i<n;i++){
            update(1, i+1, i, 1, n);
            disk[i] = i;
        }
        for(int i=0;i<k;i++){
            int q, a, b;
            scanf("%d %d %d", &q, &a, &b);
            if(!q){
                update(1, b+1, disk[a], 1, n);
                update(1, a+1, disk[b], 1, n);
                swap(disk[a], disk[b]);
            }else{
                pair<int, int> m = find(1, a+1, b+1, 1, n);
                if(m.first == b && m.second == a) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
