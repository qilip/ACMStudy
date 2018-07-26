#include <stdio.h>

int main(void){
    long long ans = 0;
    int n, j = 1, a, b, m;
    scanf("%d", &n);
    for(int i=1;i<=n;i+=j){
        a = n/i;
        b = n%i;
        j = b/a + 1;
        m = b%a ? 0 : 1;
        ans += a*j + j - m;
    }
    printf("%lld", ans);
    return 0;
}
