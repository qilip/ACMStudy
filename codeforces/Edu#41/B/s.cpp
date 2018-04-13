#include <stdio.h>

int na[100010], nt[100010];
long long cnt = 0, sum[100010] = { 0 };

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++){
        scanf("%d", &na[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &nt[i]);
    }
    for(int i=1;i<=n;i++){
        if(nt[i]){
            cnt += na[i];
            na[i] = 0;
        }
        sum[i] = sum[i-1] + na[i];
    }
    long long max = 0;
    for(int i=1;i<=n-k+1;i++){
        long long tmp = sum[i+k-1] - sum[i-1];
        if(max < tmp) max = tmp;
    }
    printf("%lld", cnt + max);
}
