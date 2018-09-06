#include <stdio.h>

int main(void){
    int k, p, x;
    scanf("%d %d %d", &k, &p, &x);
    double ans = 99999999.9;
    for(int i=1;i<=10000;i++){
        double cur = (double)(k*p)/(double)i+x*i;
        ans = ans > cur ? cur : ans;
    }
    printf("%.3f", ans);
    return 0;
}
