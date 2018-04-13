#include <stdio.h>

int nn[4][110][110], bcnt[4] = {0}, wcnt[4] = {0}, bbc[4] = {0}, wwc[4] = {0};
int tru[3][4] = { 0 }, zcnt = 0, sss = 0;

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                scanf("%1d", &nn[i][j][k]);
                if(nn[i][j][k]) bbc[i]++;
                else wwc[i]++;
                if(nn[i][j][k] == (j+k)%2){ //첫칸이 검정 TRUE
                    wcnt[i]++;
                }else{
                    bcnt[i]++;
                }
            }
        }
        if(wcnt[i] < bcnt[i]){ //최소수정후 첫칸 검정
            tru[0][i] = wcnt[i];
            tru[1][i] = bcnt[i];
            tru[2][i] = 0;
        }else{
            tru[0][i] = bcnt[i];
            tru[1][i] = wcnt[i];
            tru[2][i] = 1;
            zcnt++; //첫칸 화이트일 갯수
        }
    }
    if(zcnt == 2){
        printf("%d", tru[0][0] + tru[0][1] + tru[0][2] + tru[0][3]);
    }else if(zcnt == 1 || zcnt == 3){
        int w = 0, mark = 0;
        if(zcnt==3) w = 0;
        else w = 1;
        int min = 9999999;
        for(int i=0;i<4;i++){
            if(tru[2][i] == w){
                if(min < tru[w][i]) {
                    min = tru[w][i];
                    mark = i;
                }
            }
        }
        for(int i=0;i<4;i++){
            if(i == mark || tru[2][i] == w ) {
                int tmp = tru[w][i];
                tru[w][i] = tru[!w][i];
                tru[!w][i] = tmp;
            }
            sss += tru[1][i];
        }
        printf("%d", sss);
    }else{
        int mark = 0;
        int min = 9999999;
        for(int i=0;i<4;i++){
            if(min > tru[1][i]) {
                min = tru[1][i];
                mark = i;
            }
        }
        int tmp = tru[1][mark];
        tru[1][mark] = 9999999;
        tru[0][mark] = tmp;
        mark = 0;
        min = 9999999;
        for(int i=0;i<4;i++){
            if(min > tru[1][i]) {
                min = tru[1][i];
                mark = i;
            }
        }
        tmp = tru[1][mark];
        tru[1][mark] = 9999999;
        tru[0][mark] = tmp;       
        printf("%d", tru[0][0] + tru[0][1] + tru[0][2] + tru[0][3]);
    }
}
