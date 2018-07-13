#include <stdio.h>

int main(void){
    int v, w, d, ans = 0;
    scanf("%d %d %d", &v, &w, &d);
    double cnt = 0.0;
    double vv = v;
    while(cnt<d){
        double tmp = 5*(double)(w*w)/(double)(vv*vv);
        if(cnt + tmp <= d) cnt += tmp;
        else break;
        vv = vv*4.0/5.0;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
