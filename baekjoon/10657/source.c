#include <stdio.h>

int main(void){
    int n, pos[100010], spd[100010], cnt = 0, g_spd = 999999999;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &pos[i], &spd[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(spd[i] <= g_spd){
            cnt++;
            g_spd = spd[i];
        }
    }
    printf("%d", cnt);
    return 0;
}
