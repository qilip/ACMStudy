#include <stdio.h>

int main(void){
    int N, ar[10010], maxbit = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &ar[i]);
    }
    for(int i=0;i<N;i++){
        int min, max;
        min = max = ar[i];
        for(int j=i+1;j<N;j++){
            if(ar[j]>max) max = ar[j];
        }
        if(maxbit < max - min) maxbit = max - min;
    }
    printf("%d", maxbit);
    return 0;
}
