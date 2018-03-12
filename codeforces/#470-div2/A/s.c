#include <stdio.h>

char rc[510][510]={'K'};
int main (void){
    int R, C;
    char tmp;
    scanf("%d %d", &R, &C);
    for(int i=1;i<=R;i++) {
        scanf("%s", &rc[i][1]);
    }
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(rc[i][j]=='W') {
                if((rc[i-1][j]=='S')||(rc[i+1][j]=='S')||(rc[i][j-1]=='S')||(rc[i][j+1]=='S')){
                    printf("No");
                    return 0;
                } 
            }
        }
    }
    printf("Yes\n");
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(rc[i][j]=='.') {
                rc[i][j]='D'; 
            }
            printf("%c", rc[i][j]);
        }
        printf("\n");
    }
}
