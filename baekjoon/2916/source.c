#include <stdio.h>

int main(void){
    int n, k, nn[11], deg[361] = {0};
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &nn[i]);
    deg[0] = 1;
    for(int i=0;i<n;i++){
        int d = 0;
        while(1){
            d += nn[i];
            d %= 360;
            deg[d] = 1;
            if(d==0) break;
        }
        d = 0;
        while(1){
            if(deg[d]){
                deg[ (d+nn[i])%360 ] = 1;
                deg[ (360*360 + d - nn[i])%360 ] = 1;
            }
            d++;
            d %= 360;
            if(d==0) break;
        }
    }
    for(int i=0;i<k;i++){
        int tmp;
        scanf("%d", &tmp);
        if(deg[tmp]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
