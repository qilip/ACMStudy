#include <stdio.h>

int main(void){
    int A, inp[1010], dp[1010];
    scanf("%d", &A);
    for(int i=0;i<A;i++){
        scanf("%d", &inp[i]);
    }
    int max = 0;
    for(int i=0;i<A;i++){
        int min = 0;
        for(int j=0;j<i;j++){
            if(inp[i] > inp[j] && min < dp[j]){
                min = dp[j];
            }
        }
        dp[i] = min + 1;
        if(max < dp[i]) max = dp[i];
    }
    printf("%d\n", max);
}
