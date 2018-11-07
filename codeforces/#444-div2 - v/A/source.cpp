#include <stdio.h>
#include <string.h>

int main(void){
    char s[110];
    scanf(" %s", s);
    int len = strlen(s);
    long long num = 1;
    int is_del = 0;
    int y = 0;
    for(int i=len-1;i>=0;i--){
        num *= 2;
        if(s[i]=='1' && num<=64) num/=2, is_del = 1;
        if(s[i]=='1' && num>=128) {y = 1; break;}
    }
    if(y) printf("yes");
    else printf("no");
    return 0;
}
