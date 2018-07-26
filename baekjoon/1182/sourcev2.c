#include <stdio.h>

int cnt, n, s, nn[30];

void r(int dep, int sel, int sum){
    if(dep==n){
        if(sum==s && sel) cnt++;
        return;
    }
    r(dep+1, sel, sum);
    r(dep+1, sel+1, sum+nn[dep]);
}

int main(void){
    scanf("%d %d", &n, &s);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    r(1, 0, 0);
    r(1, 1, nn[0]);
    printf("%d", cnt);
    return 0;
}
