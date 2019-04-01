#include <stdio.h>
#include <string.h>

char a[110], b[110], c[110];
int dp[110][110][110];

int max(int a, int b, int c){
    int d = a > b ? a : b;
    return c > d ? c : d;
}

int main(void){
    scanf("%s %s %s", a+1, b+1, c+1);
    int al = strlen(a+1);
    int bl = strlen(b+1);
    int cl = strlen(c+1);
    for(int i=1;i<=al;i++){
        for(int j=1;j<=bl;j++){
            for(int k=1;k<=cl;k++){
                if(a[i] == b[j] && b[j] == c[k]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
            }
        }
    }
    printf("%d", dp[al][bl][cl]);
    return 0;
}
