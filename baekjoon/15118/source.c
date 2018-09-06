#include <stdio.h>

typedef long long ll;

int main(void){
    int n;
    scanf("%d", &n);
    int l = 1, r = n-1, mid, ans = -1;
    ll asum = (ll)n*(ll)(n-1)/2;
    asum = (asum+1)/2;
    while(l<=r){
        mid = (l+r)/2;
        ll sum = ((ll)(n-1)+(ll)(n-mid))*(ll)mid/2;
        if(asum<=sum){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    printf("%d", ans);
    return 0;
}
