#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int x, sum = 0;
        scanf("%d", &x);
        for(int i=1;i<=x;i++){
            for(int j=1;j<=i;j++){
                sum += j;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
