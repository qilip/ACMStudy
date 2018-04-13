#include <stdio.h>
#include <math.h>

int poww(int a){
    int s = 1;
    if(a==0) return 1;
    for(;a--;){
        s *= 10;
    }
    return s;
}

int main(void){
    int N = 0, inp, z = 0, cnt = 0, chancnt = 0;
    while(scanf("%1d", &inp)!=EOF){
        cnt++;
        N += inp;
    }
    if(cnt==1) goto A;
    chancnt++;
    z = log10(N) + 1;
    while(z>1){
        int a = 0;
        for(int i=z-1;i>=0;i--){
            int tmp = N / poww(i);
            tmp %= 10;
            a += tmp;
        }
        chancnt++;
        N = a;
        z = log10(N) + 1;
    }
    A:;
    printf("%d\n", chancnt);
    if(N%3==0) printf("YES");
    else printf("NO");
}
