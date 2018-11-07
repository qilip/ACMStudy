#include <stdio.h>

unsigned k, n, kk[10010];

int is_pos(unsigned m){
    unsigned ans = 0;
    for(int i=0;i<k;i++){
        ans += kk[i]/m;
        if(ans>=n) return 1;
    }
    return 0;
}

int main(void){
    scanf("%u %u", &k, &n);
    for(int i=0;i<k;i++) scanf("%u", &kk[i]);
    unsigned l = 1, r = (1LL<<31)-1, m, ans = -1;
    while(l<=r){
        m = (l+r)/2;
        if(is_pos(m)){
            ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }
    printf("%u", ans);
    return 0;
}
