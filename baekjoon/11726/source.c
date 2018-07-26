#include <stdio.h>

int main(void){
    int n, nn[1010] = {0};
    nn[0] = 1;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=1;j<=2;j++){
            nn[i+j] += nn[i];
            nn[i+j] %= 10007;
        }
    }
    printf("%d", nn[n]);
    return 0;
}
