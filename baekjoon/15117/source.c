#include <stdio.h>

int main(void){
    int n;
    char s[40][40];
    int ichk[40][100] = {0};
    int jchk[40][100] = {0};
    int isNo = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( !ichk[i][(int)s[i][j]] && !jchk[j][(int)s[i][j]] ){
                ichk[i][(int)s[i][j]] = 1;
                jchk[j][(int)s[i][j]] = 1;
            }else{
                isNo = 1;
                goto N;
            }
        }
    }
    N:;
    if(isNo){
        printf("No");
        return 0;
    }
    int isRed = 1;
    for(int i=1;i<n;i++){
        if(s[i-1][0] > s[i][0]){
            isRed = 0;
            break;
        }
        if(s[0][i-1] > s[0][i]){
            isRed = 0;
            break;
        }
    }
    if(isRed){
        printf("Reduced");
    }else{
        printf("Not Reduced");
    }
    return 0;
}
