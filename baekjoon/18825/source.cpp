#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int met = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        int pwr = (r1+r2)*(r1+r2);
        int mwr = (r1-r2)*(r1-r2);
        if(met==0 && r1==r2) printf("-1\n");
        else if(met == mwr || met == pwr) printf("1\n");
        else if(met > mwr && met < pwr) printf("2\n");
        else printf("0\n");
    }
    return 0;
}