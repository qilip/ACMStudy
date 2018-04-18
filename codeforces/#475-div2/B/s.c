#include <stdio.h>

int main(void){
    int n, A, B, C, T;
    int cnt = 0;
    scanf("%d %d %d %d %d", &n, &A, &B, &C, &T);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        cnt += T-tmp;
    }
    if(B>=C){
        printf("%d", n*A);
    }else{
        int max = C*cnt;
        int minu = A*n - B*cnt;
        printf("%d", max+minu);
    }
    return 0;
}
