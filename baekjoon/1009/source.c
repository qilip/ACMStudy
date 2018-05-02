#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int cs[20];
        if(a%10==0) {
            printf("10\n");
            goto A;
        }
        cs[1] = a%10;
        for(int j=2;j<=12;j++) cs[j] = (cs[j-1]*a)%10;
        for(int k=2;k<=12;k++){
            if(cs[1]==(cs[k])) {
                int q = b%(k-1);
                if(q==0) q=k-1;
                printf("%d\n", cs[q]);
                break;
            }
        }
        A:;
    }
    return 0;
}
