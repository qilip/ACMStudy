#include <stdio.h>

int buf[4000][8000], n;

void small(int line, int space){
    buf[line][space+1] = 1;
    buf[line+1][space] = 1; buf[line+1][space+2] = 1;
    for(int i=0;i<5;i++) buf[line+2][space-1+i] = 1;
    return;
}

void writer(int level, int lineStr, int lineEnd, int space){
    if(level==1){
        small(lineStr, space);
    }else{
        writer(level/2, lineStr, (lineStr+lineEnd)/2, space);
        writer(level/2, (lineStr+lineEnd)/2+1, lineEnd, space-level/2*3);
        writer(level/2, (lineStr+lineEnd)/2+1, lineEnd, space+level/2*3);
    }
}

int main(void){
    scanf("%d", &n);
    writer(n/3, 1, n, n-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*2-1;j++){
            printf("%c", buf[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    return 0;
}
