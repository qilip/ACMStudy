#include <stdio.h>

int main(void){
    int n, a[1010];
    int dp[1010] = {0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++){
        int bef = 0;
        for(int j=1;j<i;j++){
            if(a[i] > a[j] && bef < dp[j]){
                bef = dp[j];
            }
        }
        dp[i] = bef + a[i];
    }
    int max = 0;
    for(int i=1;i<=n;i++){
        if(max < dp[i]) max = dp[i];
    }
    printf("%d", max);
    return 0;
}
