#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll nn[300010];
ll m = 1000000007;
ll sum = 0, sumr = 0, suml = 0;
ll e[300010];

int main(void){
    scanf("%d", &n);
    e[0] = 1;
    for(int i=1;i<n;i++){
        e[i] = (e[i-1]<<1) % m;
    }
    for(int i=0;i<n;i++){
        scanf("%lld", &nn[i]);
    }
    sort(nn, nn+n);
    for(int i=0;i<n;i++){
        suml = (suml + ( (nn[i] % m) * (e[n-1-i]-1) ) % m) % m;
        sumr = (sumr + ( (nn[i] % m) * (e[i]-1) ) % m) % m;
    }
    sum = (sumr - suml) % m;
    printf("%lld", sum);
    return 0;
}
