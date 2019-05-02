#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int tree[300000];

void update(int cur, int idx, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[cur] += 1;
        return;
    }
    int m = (l+r)/2;
    update(cur*2, idx, l, m);
    update(cur*2+1, idx, m+1, r);
    tree[cur] = tree[cur*2] + tree[cur*2+1];
}

int find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        vector<pair<int, int> > p;
        vector<pair<int, int> > v;
        memset(tree, 0, sizeof tree);
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            p.emplace_back(y, x);
        }
        sort(p.begin(), p.end());
        int cnt = 0;
        for(int i=0;i<(int)p.size();i++){
            if(!i || p[i-1].first != p[i].first) cnt++;
            v.emplace_back(-p[i].second, cnt);
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for(auto cur : v){
            ans += find(1, 1, cur.second, 1, n);
            update(1, cur.second, 1, n);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
