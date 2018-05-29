#include <stdio.h>

typedef long long ll;

int main(void){
    ll n, m, ans = 1;
    scanf("%lld %lld", &n, &m);
    for(ll i=0;i<n;i++){
        ll inp;
        scanf("%lld", &inp);
        ans *= inp%m;
        ans = ans%m;
    }
    printf("%lld", ans);
    return 0;
}
