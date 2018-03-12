#include <stdio.h>

int main(void){
    int N, V[10010], ptr=0;
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &V[i]);
    for(int i=0;i<N;i++){
        int T, nok=0;
        scanf("%d", &T);
        for(int j=ptr;j<=i;j++){
            if(V[j]<=T){
                nok += V[j];
                ptr=j+1;
            }else{
                V[j] -= T;
                nok += T;
            }
        }
        printf("%d ", nok);
    }
}
