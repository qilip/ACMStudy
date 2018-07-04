#include <stdio.h>

int n, m, cnt;
char nm[60][60];
bool cnm[60][60];

bool chk(int a, int b){
    if(nm[a][b]!='.') return false;
    if(nm[a][b-1]=='#' || nm[a][b-1]==0){
        if(nm[a][b+1]=='.' && nm[a][b+2]=='.'){
            cnm[a][b] = true;
            return true;
        }
    }
    if(nm[a-1][b]=='#' || nm[a-1][b]==0){
        if(nm[a+1][b]=='.' && nm[a+2][b]=='.'){
            cnm[a][b] = true;
            return true;
        }
    }
    return false;
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%s", nm[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(chk(i, j)) cnt++;
        }
    }
    printf("%d\n", cnt);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnm[i][j]) printf("%d %d\n", i, j);
        }
    }    
    return 0;
}
