#include <stdio.h>

int n, a[3][6];
int num[1000];

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            scanf("%d", &a[i][j]);
        }
    }
    if(n>=1){
        for(int i=0;i<6;i++){
            for(int q=0;q<n;q++){
                num[a[q][i]]++;
            }
        }
    }
    if(n>=2){
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                num[a[0][i]*10+a[1][j]]++;
                num[a[1][i]*10+a[0][j]]++;
                if(n==3){
                    num[a[0][i]*10+a[2][j]]++;
                    num[a[2][i]*10+a[0][j]]++;
                    num[a[1][i]*10+a[2][j]]++;
                    num[a[2][i]*10+a[1][j]]++;
                }
            }
        }
    }
    if(n==3){
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    num[a[0][i]*100+a[1][j]*10+a[2][k]]++;
                    num[a[0][i]*100+a[2][j]*10+a[1][k]]++;
                    num[a[1][i]*100+a[2][j]*10+a[0][k]]++;
                    num[a[1][i]*100+a[0][j]*10+a[2][k]]++;
                    num[a[2][i]*100+a[1][j]*10+a[0][k]]++;
                    num[a[2][i]*100+a[0][j]*10+a[1][k]]++;
                }
            }
        }
    }
    for(int i=1;i<=999;i++){
        if(!num[i]){
            printf("%d", i-1);
            break;
        }
    }
    return 0;
}
