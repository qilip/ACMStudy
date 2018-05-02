#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int q=0;q<T;q++){
        int x1, y1, x2, y2, n, cx[60], cy[60], r[60], cnt=0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d %d %d", &cx[i], &cy[i], &r[i]);
        for(int i=0;i<n;i++) {
            int tmp1, tmp2;
            tmp1 = abs(pow(x1-cx[i],2)+pow(y1-cy[i],2));
            tmp2 = abs(pow(x2-cx[i],2)+pow(y2-cy[i],2));
            if(tmp1<pow(r[i],2)^tmp2<pow(r[i],2)) cnt++;
        }
        printf("%d\n", cnt);
    }
}
