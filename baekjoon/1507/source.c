#include <stdio.h>

int main(void){
    int n;
    int d[21][21];
    int chk[21][21] = {0};
    int sum = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d", &d[i][j]);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || i==k || k==j) continue;
                if(d[i][j] == d[i][k]+d[k][j]){
                    chk[i][j] = 1;
                }
                if(d[i][j] > d[i][k]+d[k][j]){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!chk[i][j]) sum += d[i][j];
        }
    }
    printf("%d", sum);
    return 0;
}
