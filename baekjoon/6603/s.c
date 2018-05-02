#include <stdio.h>

int main(void){
    while(1){
        int k, ar[14];
        scanf("%d", &k);
        if(k==0) break;
        for(int i=1;i<=k;i++){
            scanf("%d", &ar[i]);
        }
        for(int i=1;i<=k-5;i++){
            for(int j=i+1;j<=k-4;j++){
                for(int q=j+1;q<=k-3;q++){
                    for(int w=q+1;w<=k-2;w++){
                        for(int e=w+1;e<=k-1;e++){
                            for(int r=e+1;r<=k;r++){
                                printf("%d %d %d %d %d %d\n", ar[i], ar[j], ar[q], ar[w], ar[e], ar[r]);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
