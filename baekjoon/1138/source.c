#include <stdio.h>

int main(void){
    int N, nn[12]={0};
    scanf("%d", &N);
    for(int height=1;height<=N;height++) {
        int lft, i, zcnt=0;
        scanf("%d", &lft);
        for(i=1;i<=N;i++){
            if(nn[i]==0) zcnt++;
            if(lft==0 || zcnt==lft) break;
        }
        if(lft!=0 && lft<i ) lft = i;
        for(;lft<N;lft++){
            if(nn[lft+1]==0){
            nn[lft+1]=height;
            break;
            }
        }
    }
    for(int i=1;i<=N;i++){
        printf("%d ", nn[i]);
    }
}
