#include <stdio.h>

int a, b, sa, sb, sum, r = 0;

int main(void){
    scanf("%d %d", &a, &b);
    for(int i=1;i<=b;){
        for(int j=0;j<r;j++){
            sum += r;
            if(i==a-1) sa = sum;
            if(i==b) sb = sum;
            i++;
        }
        r++;
    }
    printf("%d", sb - sa);
    return 0;
}
