#include <stdio.h>

typedef long long ll;

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n, k;
        ll v;
        char a[60][30];
        int flg[60] = {0};
        scanf("%d %d %lld", &n, &k, &v);
        for(int i=0;i<n;i++){
            scanf("%s", a[i]);
        }
        int nxt = (int)((ll)k * (v-1) % (ll)n);
        int rop = k;
        while(rop--){
            flg[nxt] = 1;
            nxt++;
            nxt %= n;
        }
        printf("Case #%d: ", t);
        for(int i=0;i<n;i++){
            if(flg[i]) printf("%s ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
