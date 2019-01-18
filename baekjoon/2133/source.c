#include <stdio.h>

int main(void){
    int n, nn[40] = {0};
    nn[0] = 1, nn[2] = 3;
    scanf("%d", &n);
    for(int i=4;i<=n;i++){
        nn[i] += nn[i-2] * 3;
        for(int j=4;i-j>=0;j+=2){
            nn[i] += nn[i-j] * 2;
        }
    }
    printf("%d", nn[n]);
    return 0;
}
