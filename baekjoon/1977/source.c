#include <stdio.h>
#include <math.h>

int main(void){
    int M, N, sum=0, min=10001;
    scanf("%d %d", &M, &N);
    for(int i=M;i<=N;i++){
        if( sqrt(i)==(int)sqrt(i) ){
            sum+=i;
            if(min>i) min=i;
        }
    }
    if(sum==0){
        printf("-1");
        return 0;
    }
    printf("%d\n%d", sum, min);
}
