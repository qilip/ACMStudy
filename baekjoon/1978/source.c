#include <stdio.h>

int main(void){
    int n, cnt = 0;
    int era[1010] = {0};
    era[1] = 1;
    scanf("%d", &n);
    for(int i=2;i<=1000;i++){
        if(era[i]) continue;
        for(int j=i+i;j<=1000;j+=i){
            era[j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        if(!era[tmp]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
