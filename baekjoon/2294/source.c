#include <stdio.h>
#include <string.h>

int min[10010];

int main(void){
    memset(min,50,sizeof(min));
    min[0] = 0;
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int coin;
        scanf("%d", &coin);
        for(int j=coin;j<=k;j++){
            min[j] = min[j] > min[j-coin] +1 ? min[j-coin] +1 : min[j];
        }
    }
    printf("%d", min[k]==min[10005] ? -1 : min[k]);
}
