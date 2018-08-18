#include <stdio.h>

int main(void){
    int n, nn[2222] = {0};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        nn[t+1001] = 1;
    }
    for(int i=0;i<=2200;i++){
        if(nn[i]) printf("%d ", i-1001);
    }
    return 0;
}
