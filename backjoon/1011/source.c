#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for (int i=0;i<T;i++){
        long long x, y, a, q, tmp, cnt;
        scanf("%lld %lld", &x, &y);
        a = y - x;
        for (q=1;((q+1)*(q+1))<=a;q++);
        tmp = a-q*q;
        cnt = q*2-1 + tmp/q;
        if(tmp%q) cnt++;
        printf("%lld\n", cnt);
    }
}
