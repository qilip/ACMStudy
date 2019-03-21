#include <stdio.h>

int main(void){
    int n;
    int nn[9][9] = {0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char s[3];
            scanf("%s", s);
            if('0'<=s[0] && s[0]<='9') nn[i][j] = s[0]-'0';
            else if(s[0]=='A') nn[i][j] = 1;
            else if(s[0]=='T') nn[i][j] = 10;
            else if(s[0]=='J') nn[i][j] = 11;
            else if(s[0]=='Q') nn[i][j] = 12;
            else nn[i][j] = 13;
        }
    }
    for(int i=n;i>0;i--){
        for(int j=1;j<=n;j++){
            nn[i][j] += nn[i][j-1] > nn[i+1][j] ? nn[i][j-1] : nn[i+1][j];
        }
    }
    printf("%d", nn[1][n]);
    return 0;
}
