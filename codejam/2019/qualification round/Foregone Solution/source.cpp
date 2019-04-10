#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        char n[300] = {0};
        char b[300] = {0};
        int bi = 0;
        scanf("%s", n);
        for(int i=0;n[i];i++){
            if(n[i] == '4'){
                n[i] = '3';
                b[bi++] = '1';
            }else{
                if(bi) b[bi++] = '0';
            }
        }
        printf("Case #%d: %s %s\n", t, n, b);
    }
    return 0;
}
