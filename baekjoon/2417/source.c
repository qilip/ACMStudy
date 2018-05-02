#include <stdio.h>
#include <math.h>

int main(void){
    long long inp, m;
    scanf("%lld", &inp);
    long long tmp = sqrt(inp);
    if(tmp*tmp == inp){
        printf("%lld", tmp);
    }else{
        printf("%lld", tmp+1);
    }
}
