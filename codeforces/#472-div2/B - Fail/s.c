#include <stdio.h>

int n, m, flg = 0;
int flgn[60]={0}, flgm[60]={0};
char nm[60][60];

void findn(int a);
void findm(int b);

// 줄 안에서 찾기
void findn(int a){
    if(flgn[a] == 1) flg++;
    else {
        for(int j = 0;j<m;j++){
            if(nm[a][j] == '#' && flgm[j] == 0){
                nm[a][j] = '.';
                findm(j);
                flgm[j] = 1;
            }else if(nm[a][j] == '#' && flgm[j] == 1){
                flg++;
                break;
            }
        }
    }
    flgn[a] = 1;
}

// 열 안에서 찾기
void findm(int b){
    if(flgm[b] == 1) flg++;
    else {
        for(int i=0;i<n;i++){
            if(nm[i][b] == '#' && flgn[i] == 0){
                nm[i][b] = '.';
                findn(i);
                flgn[i] = 1;
            }else if(nm[i][b] == '#' && flgn[i] == 1){
                flg++;
            }
        }
    }
    flgm[b] = 1;
}

int main(void){

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%s", nm[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nm[i][j] == '#')
            findm(j);
        }
    }
    if(flg) printf("No");
    else printf("Yes");
}
