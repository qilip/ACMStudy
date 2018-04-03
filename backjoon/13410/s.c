#include <stdio.h>

int poww(int a){
    int  s = 1;
    for(int i=0;i<a;i++){
        s *= 10;
    }
    return s;
}

int main(void){
    int a, b, gu[1010], maxj = 1, max = 0;
    scanf("%d %d", &a, &b);
    for(int i=1;i<=b;i++){
        gu[i] = a*i;
        for(int j=7;j>=0;j--){
            if(gu[i]/poww(j)){
                if(j>=maxj) {
                    maxj = j+1;
                }
            }
        }
    }
    for(int k=1;k<=b;k++){
        if(gu[k]/poww(maxj-1)==0) continue;
        int tmpg = gu[k];
        gu[k] = 0;
        for(int i=1;i<=maxj;i++){
            int tmp = (tmpg%10) * poww(maxj-i+1);
            tmpg /= 10;
            gu[k] += tmp;
        }
        if(max < gu[k]) max = gu[k];
    }
    printf("%d", max/10);
    return 0;
}
