#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    setbuf(stdout, NULL);
    int pp[10010] = {1,2,3,4,5,6,7,8,9,}, ptr = 9;
    for(int i=11;i<10000;i++){
        if(i%10==0) continue;
        int j = 0, tmp = i, re = 0;
        if(i<100) j=10; else if(i<1000) j=100; else j=1000;
        for(;j>=1;j/=10){
            int a = tmp%10;
            tmp/=10;
            re += a*j;
        }
        if(i==re) pp[ptr++] = i;
    }
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n, k, kk[4];
        scanf("%d", &n);
        for(int p = 1; p<=3;p++){
            if(binary_search(pp, pp+ptr, n)){
                k = p;
                kk[p] = n;
                n = 0;
                break;
            }else{
                if(p==3) break;
                int ite = lower_bound(pp, pp+ptr, n) - pp - 1;
                k = p;
                kk[p] = pp[ite];
                n -= pp[ite];
            }
        }
        if(n) k = 0;
        printf("Case #%d\n", t);
        printf("%d", k);
        for(int i=1;i<=k;i++){
            printf(" %d", kk[i]);
        }
        printf("\n");
    }
    return 0;
}
