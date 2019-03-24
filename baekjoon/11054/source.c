#include <stdio.h>

int main(void){
    int n, a[1010];
    int inc[1010] = {0}, dec[1010] = {0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i] && inc[i] <= inc[j]){
                inc[i] = inc[j]+1;
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n+1;j>i;j--){
            if(a[j] < a[i] && dec[i] <= dec[j]){
                dec[i] = dec[j]+1;
            }
        }
    }
    int max = 0;
    for(int i=1;i<=n;i++){
        if(max < inc[i]+dec[i]) max = inc[i]+dec[i];
    }
    printf("%d", max-1);
    return 0;
}
