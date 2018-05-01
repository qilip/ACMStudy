#include <stdio.h>
#include <stdlib.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int l, n, tmp;
        scanf("%d %d", &l, &n);
        scanf("%d", &tmp);
        int maxi = tmp;
        int mcnt = abs(l/2-tmp);
        int mini = tmp;
        int micnt = abs(l/2-tmp);
        for(int i=1;i<n;i++){
            int tmp;
            scanf("%d", &tmp);
            if(mcnt > abs(l/2-tmp)){
                maxi = tmp;
                mcnt = abs(l/2-tmp);
            }
            if(micnt < abs(l/2-tmp)){
                mini = tmp;
                micnt = abs(l/2-tmp);
            }
        }
        int min = maxi > l-maxi ? l-maxi : maxi;
        int max = mini < l-mini ? l-mini : mini;
        printf("%d %d\n", min, max);
    }
    return 0;
}
