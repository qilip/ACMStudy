#include <stdio.h>

int n, nn[1010][1010];

void euc(int csr){
    for(int i=0;i<=n;i++){
        if(!nn[csr][i]) continue;
        nn[csr][i]--;
        nn[i][csr]--;
        euc(i);
    }
    printf("%d ", csr);
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp) cnt+=tmp;
            nn[i][j] = tmp;
        }
        if(cnt%2){
            printf("-1");
            return 0;
        }
    }
    euc(1);
    return 0;
}
