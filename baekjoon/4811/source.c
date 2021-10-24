#include <stdio.h>

long long dp[40];

int main(void){
    dp[1] = 1;
    for (int i = 2; i <= 31; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += dp[j] * dp[i-j];
        }
    }
    int n;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        printf("%lld\n", dp[n+1]);
    }
    return 0;
}
