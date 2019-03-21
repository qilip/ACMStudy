#include <stdio.h>

int main(void){
    int n, q;
    int ar[10010] = {0};
    int cnt = 0;
    scanf("%d %d", &n, &q);
    for(int i=0;i<q;i++){
        int s, d;
        scanf("%d %d", &s, &d);
        for(int j=s;j<=n;j+=d) ar[j] = 1;
    }
    for(int i=1;i<=n;i++) if(!ar[i]) cnt++;
    printf("%d", cnt);
    return 0;
}
