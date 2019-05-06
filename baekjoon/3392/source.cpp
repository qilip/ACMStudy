#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int sum[120000];
int cnt[120000];

void update(int cur, int diff, int ul, int ur, int l, int r){
    if(ur<l || r<ul) return;
    if(ul<=l && r<=ur) cnt[cur] += diff;
    else{
        int m = (l+r)/2;
        update(cur*2, diff, ul, ur, l, m);
        update(cur*2+1, diff, ul, ur, m+1, r);
    }
    if(cnt[cur]) sum[cur] = r-l+1;
    else{
        if(l==r) sum[cur] = 0;
        else sum[cur] = sum[cur*2] + sum[cur*2+1];
    }
}

int main(void){
    int n;
    vector<tuple<int, int, int, int> > v;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        v.emplace_back(a, -1, b, d-1); //a, in , b, d
        v.emplace_back(c, 1, b, d-1); //c, out , b, d
    }
    sort(v.begin(), v.end());
    int ans = 0, bef = 0;
    for(auto c : v){
        int x, diff, y1, y2;
        tie(x, diff, y1, y2) = c;
        ans += sum[1] * (x - bef);
        update(1, -diff, y1, y2, 0, 30000);
        bef = x;
    }
    printf("%d", ans);
    return 0;
}
