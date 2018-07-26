#include <stdio.h>
#include <stdlib.h>

int ans, n;
int nn[20];

int isPos(int a){
    for(int i=1;i<a;i++){
        if(nn[i]==nn[a]) return 0;
        if(abs(nn[i]-nn[a])==a-i) return 0;
    }
    return 1;
}

void nq(int dep){
    if(dep==n+1){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        nn[dep] = i;
        if(isPos(dep)) nq(dep+1);
        nn[dep] = 0;
    }
}

int main(void){
    scanf("%d", &n);
    nq(1);
    printf("%d", ans);
    return 0;
}
