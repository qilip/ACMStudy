#include <stdio.h>

int N, S, nn[22], cnt;

void find(int now, int slt, int sum, int nu){
    sum += slt*nn[now];
    if(now==N-1){
        if(sum==S && nu) cnt++;
        return;
    }
    find(now+1, 0, sum, nu);
    find(now+1, 1, sum, nu+1);
}

int main(void){
    scanf("%d %d", &N, &S);
    for(int i=0;i<N;i++) scanf("%d", &nn[i]);
    find(0, 0, 0, 0);
    find(0, 1, 0, 1);
    printf("%d", cnt);
    return 0;
}
