#include <stdio.h>
#include <memory.h>

using namespace std;

int n, m;
char nm[60][60];
int maxcnt;
int cnt;
char i, j;
int nx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ny[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void fnd(int a, int b, int dep, int xy){
    if(dep==1){
        for(int t=0;t<8;t++){
            if(nm[a+nx[t]][b+ny[t]]==j){
                fnd(a+nx[t], b+ny[t], 2, t);
            }
        }
    }else if(dep==2){
        if(nm[a+nx[xy]][b+ny[xy]]==j){
            cnt++;
        }
    }
}

int main(void){
    memset(nm, '9', sizeof(nm));
    scanf("%d %d", &n, &m);
    for(int ai=1;ai<=n;ai++){
        for(int aj=1;aj<=m;aj++){
            scanf(" %c", &nm[ai][aj]);
        }
    }
    for(i='A';i<='Z';i++){
        if(i=='M') continue;
        for(j='A';j<='Z';j++){
            cnt = 0;
            if(i==j || j=='O') continue;
            for(int a=1;a<=n;a++){
                for(int b=1;b<=m;b++){
                    if(nm[a][b]==i) fnd(a, b, 1, 0);
                }
            }
            if(maxcnt < cnt) maxcnt = cnt;
        }
    }
    printf("%d", maxcnt);
    return 0;
}
