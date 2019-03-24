#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    int nn[1010];
    int dp[1010] = {0};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    for(int i=0;i<n;i++){
        int low = 99999999, high = -1;
        for(int j=i;j>=0;j--){
            low = low > nn[j] ? nn[j] : low;
            high = high > nn[j] ? high : nn[j];
            dp[i] = dp[i] < dp[j-1]+high-low ? dp[j-1]+high-low : dp[i];
        }
    }
    printf("%d", dp[n-1]);
    return 0;
}
