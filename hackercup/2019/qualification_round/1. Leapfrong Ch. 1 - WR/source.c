#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        char n[5010] = {0};
        scanf(" %s", n);
        int len = strlen(n);
        int flg = 0;
        if( (n[len-3] == 'B' || n[len-2] =='B') && n[len-1] == '.') flg = 1;
        if(n[len-1] == 'B'){
            for(int i=len-2;i>=1;i--){
                if(n[i] == '.'){
                    flg = 1;
                    break;
                }
            }
        }
        if(n[1] != 'B' && n[2] != 'B'){
            flg = 0;
        }
        if(flg) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
