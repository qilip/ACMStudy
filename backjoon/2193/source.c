#include <stdio.h>

int main(void){
    long long nn[92] = {0, 1};
    int N;
    scanf("%d", &N);
    for(int i = 1;i<=N;i++){
        nn[i+1] = nn[i] + nn[i-1];
    }
    printf("%lld", nn[N]);
}
