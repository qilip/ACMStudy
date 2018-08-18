#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int tt;
        scanf("%d", &tt);
        int nn[110] = {0};
        for(int i=0;i<1000;i++){
            int tmp;
            scanf("%d", &tmp);
            nn[tmp]++;
        }
        int max = 0, max_el = 0;
        for(int i=100;i>=0;i--){
            if(max<nn[i]) max = nn[i], max_el = i;
        }
        printf("#%d %d\n", tt, max_el);
    }
    return 0;
}
