#include <stdio.h>
#include <algorithm>

using namespace std;

int n, s, n1[21], n2[21];
int dp1[1048579], dp2[1048579], d1p, d2p;
long long ans;

void set1(int dep, int sum){
    if(dep==n/2){
        dp1[d1p++] = sum;
        return;
    }
    set1(dep+1, sum+n1[dep]);
    set1(dep+1, sum);
}

void set2(int dep, int sum){
    if(dep==(n+1)/2){
        dp2[d2p++] = sum;
        return;
    }
    set2(dep+1, sum+n2[dep]);
    set2(dep+1, sum);
}

int main(void){
    scanf("%d %d", &n, &s);
    for(int i=0;i<n/2;i++) scanf("%d", &n1[i]);
    for(int i=0;i<(n+1)/2;i++) scanf("%d", &n2[i]);
    set1(0, 0); set2(0, 0);
    d1p--, d2p--;
    sort(dp1, dp1+d1p); sort(dp2, dp2+d2p);
    for(int i=0;i<d1p;i++){
        if(dp1[i]==s) ans++;
        ans += upper_bound(dp2, dp2+d2p, s-dp1[i]) - lower_bound(dp2, dp2+d2p, s-dp1[i]);
    }
    for(int i=0;i<d2p;i++) if(dp2[i]==s) ans++;
    printf("%lld", ans);
    return 0;
}
