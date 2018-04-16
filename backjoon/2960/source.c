#include <stdio.h>

int main(void){
    int N, K, che[1010] = {0};
    scanf("%d %d", &N, &K);
    while(1){
        int flg = 0;
        for(int i=2;i<=N;i++){
            if(che[i]==0){
                flg = i;
                break;
            }
        }
        for(int i=flg;i<=N;i+=flg){
            if(che[i]==0){
                che[i] = 1;
                K--;
            }
            if(K==0){
                printf("%d", i);
                return 0;
            }
        }
    }
}
