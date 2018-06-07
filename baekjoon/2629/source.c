#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c, cc[33], dp[15010] = {0};
    dp[0] = 1;
    scanf("%d", &c);
    for(int i=1;i<=c;i++)
        scanf("%d", &cc[i]);
    for(int i=1;i<=c;i++){
        int tmp[15010] = {0};
        for(int j=0;j<15010;j++){
            if(!dp[j]) continue;
            int a = abs(j+cc[i]);
            int b = abs(j-cc[i]);
            if(a<=15000) tmp[a] = 1;
            if(b<=15000) tmp[b] = 1;
        }
        for(int j=0;j<15010;j++)
            if(tmp[j]) dp[j] = tmp[j];
    }
    int d;
    scanf("%d", &d);
    for(int i=0;i<d;i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp>15000) printf("N ");
        else if(dp[tmp]) printf("Y ");
        else printf("N ");
    }
    return 0;
}
