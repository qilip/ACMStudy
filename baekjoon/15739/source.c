#include <stdio.h>

int n, nx[110] = {0}, ny[110] = {0}, d1 = 0, d2 = 0, cnt[500051] = {0}, flg = 0;

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            scanf("%d", &tmp);
            if(cnt[tmp]) flg = 1;
            cnt[tmp]++;
            nx[i] += tmp;
            ny[j] += tmp;
            if(i==j) d1 += tmp;
            if( (n-(j+1)) == i ) d2 += tmp;
        }
    }
    int sum = n*(n*n+1)/2;
    if(sum != d1 || sum != d2) flg = 1;
    for(int i=0;i<n;i++){
        if(sum != nx[i] || sum != ny[i]) { flg = 1; break; }
    }
    if(flg) printf("FALSE");
    else printf("TRUE");
    return 0;
}
