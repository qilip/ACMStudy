#include <stdio.h>

typedef long long ll;

int main(void){
    int n, m;
    int nn[100010];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    ll l = 1, r = 1e18, mid, ans = 0;
    while(l<=r){
        mid = (l+r)/2;
        ll out = 0;
        for(int i=0;i<n;i++){
            out += mid/nn[i];
            if(out >= m) break;
        }
        if(out >= m){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    printf("%lld", ans);
    return 0;
}
