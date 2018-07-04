#include <stdio.h>
#include <memory.h>

int n, a[1010], cnt[1111];

void jmp(int cur){
    int t = a[cur];
    for(int i=1;i<=t;i++){
        if(cnt[cur+i] > cnt[cur]+1)
            cnt[cur+i] = cnt[cur]+1;
    }
}

int main(void){
    memset(cnt, 40, sizeof(cnt));
    cnt[0] = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n;i++){
        jmp(i);
    }
    if(cnt[n-1] == 673720360) printf("-1");
    else printf("%d", cnt[n-1]);
    return 0;
}
