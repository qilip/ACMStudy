#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int x, a[] = { 1,2,3,4,5,6,7,8,9,10 };
        scanf("%d", &x);
        x %= 6;
        for(int i=0;i<x;i++){
            int a1 = a[1], a2 = a[3] ,a3 = a[5] ,a4 = a[7];
            a[1] = a[2];
            a[2] = a[4];
            a[3] = a[6];
            a[4] = a[8];
            a[5] = a1;
            a[6] = a2;
            a[7] = a3;
            a[8] = a4;
        }
        for(int i=0;i<10;i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
