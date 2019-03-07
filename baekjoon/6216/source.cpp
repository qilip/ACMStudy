#include <stdio.h>
#include <algorithm>

using namespace std;

struct cow{
    int t;
    int d;
    bool operator<(const cow &o) const{
        return d*o.t > o.d*t;
    }
};

int main(void){
    int n;
    scanf("%d", &n);
    cow p[100010];
    for(int i=0;i<n;i++){
        scanf("%d %d", &p[i].t, &p[i].d);
    }
    sort(p, p+n);
    long long cnt = 0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += p[i].d*cnt;
        cnt += p[i].t*2;
    }
    printf("%lld", ans);
    return 0;
}
