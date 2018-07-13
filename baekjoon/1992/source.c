#include <stdio.h>

int n;
char nn[70][70];

void qt(int sx, int sy, int siz){
    char s = nn[sx][sy];
    int flg = 0;
    for(int i=sx;i<sx+siz;i++){
        for(int j=sy;j<sy+siz;j++){
            if(s!=nn[i][j]) {
                flg = 1;
                break;
            }
        }
    }
    if(flg){
        int nsiz = siz/2;
        printf("(");
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                qt(sx+nsiz*i, sy+nsiz*j, nsiz);
            }
        }
        printf(")");
    }else{
        printf("%c", s);
    }
    return;
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s", nn[i]+1);
    }
    qt(1, 1, n);
    return 0;
}
