#include <stdio.h>

int n, m, dif[51][51], cnt;
char a[51][51];

void cng(int i, int j){
    cnt++;
    for(int q=0;q<3;q++){
        for(int p=0;p<3;p++){
            dif[i+q][j+p] = !dif[i+q][j+p];
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%s", a[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            scanf(" %c", &tmp);
            dif[i][j] = a[i][j] != tmp ? 1 : 0;
        }
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(dif[i][j]){
                cng(i, j);
            }
        }
    }
    int flg = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dif[i][j]){
                flg = 1;
                break;
            }
        }
    }
    if(flg) printf("-1");
    else printf("%d", cnt);
    return 0;
}
