#include <stdio.h>

int n, s, m, vol[1010];

int main(void){
    scanf("%d %d %d", &n, &s, &m);
    vol[s] = 1;
    for(int i=0;i<n;i++){
        int inp;
        scanf("%d", &inp);
        int tmp[1010] = {0};
        int flg = 1;
        for(int j=0;j<=m;j++){
            if(vol[j]){
                if(j-inp>=0) { tmp[j-inp] = 1; flg = 0; }
                if(j+inp<=m) { tmp[j+inp] = 1; flg = 0; }
            }
        }
        for(int j=0;j<=m;j++){
            vol[j] = tmp[j];
        }
        if(flg){
            printf("-1");
            return 0;
        }
    }
    for(int i=m;i>=0;i--){
        if(vol[i]){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
