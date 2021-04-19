#include <stdio.h>

int main(void){
    int n, c = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char s[120];
        int chk[200] = {0};
        int flg = 0;
        scanf(" %s", s);
        for(int j=0;s[j]!=0;j++){
            if(chk[s[j]]){
                if(s[j-1]!=s[j]){
                    flg = 1;
                    break;
                }
            }else chk[s[j]]++;
        }
        if(!flg) c++;
    }
    printf("%d", c);
    return 0;    
}
