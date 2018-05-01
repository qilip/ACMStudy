#include <stdio.h>
#include <stdlib.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int a[3], b[3], ans = 0;
        scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
        for(int i=0;i<3;i++){
            if(a[i]<b[i]){
                int tmp = b[i];
                b[i] = a[i];
                a[i] = tmp;
            }
            ans  += a[i] - b[i] > 10 - (a[i] - b[i]) ? 10 - (a[i] - b[i]) : a[i] - b[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
