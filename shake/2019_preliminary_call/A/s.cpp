#include <stdio.h>

int main(void){
    int n, m;
    long long ans = 1;
    scanf("%d %d", &n, &m);
    while(n--){
        int c;
        scanf("%d", &c);
        c %= m;
        ans = (ans * c) % m;
    }
    printf("%lld", ans);
    return 0;
}
