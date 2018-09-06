#include <stdio.h>
#include <string.h>

int main(void){
    char s[110];
    scanf("%s", s);
    int len = strlen(s);
    int flg = 1;
    for(int a=0;a<len-1;a++){
        for(int b=a+1;b<len;b++){
            int ispal = 1;
            for(int i=a, j=b;i<=b+1;i++,j--){
                if(s[i]!=s[j]){
                    ispal = 0;
                    break;
                }
            }
            if(ispal){
                if((b-a+1)%2==0){
                    flg = 0;
                    goto E;
                }
            }
        }
    }
    E:;
    if(flg){
        printf("Odd.");
    }else{
        printf("Or not.");
    }
    return 0;
}
