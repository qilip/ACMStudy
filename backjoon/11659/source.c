#include <stdio.h>

int main(void){
    int N, M, arr[100010] = {0};
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++){
        int tmp;
        scanf("%d", &tmp);
        arr[i] = arr[i-1] + tmp;
    }
    for(int i=0;i<M;i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", arr[e]-arr[s-1]);
    }
}
