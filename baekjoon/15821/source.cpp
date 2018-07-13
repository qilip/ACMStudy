#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(void){
    int n, k;
    vector<ll> maxx;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int pi;
        scanf("%d", &pi);
        ll maxp = 0;
        for(int j=0;j<pi;j++){
            ll x, y;
            scanf("%lld %lld", &x, &y);
            maxp = maxp<x*x+y*y ? x*x+y*y : maxp;
        }
        maxx.push_back(maxp);
    }
    sort(maxx.begin(), maxx.end());
    printf("%lld.00", maxx[k-1]);
    return 0;
}
