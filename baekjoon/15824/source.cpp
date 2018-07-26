#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll nn[300010];
ll m = 1000000007;
ll sum = 0;
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
    for(int i=1;i<=n;i++){
        sum = (sum + ( (nn[i-1] % m) * (e[i-1] - e[n-i]) ) % m + m) % m;
    }
    printf("%lld", sum);
    return 0;
}
