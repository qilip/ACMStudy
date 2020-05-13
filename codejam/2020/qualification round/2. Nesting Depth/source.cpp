#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        char s[110] = {0};
        scanf(" %s", s);
        printf("Case #%d: ", t);
        int cur = 0;
        for(int i=0; s[i]!=0; i++){
            if(s[i]-'0'>cur){
                for(int j=0; j<s[i]-'0'-cur; j++)
                    printf("(");
                cur = s[i]-'0';
            }else{
                for(int j=0; j<cur-(s[i]-'0'); j++)
                    printf(")");
                cur = s[i]-'0';
            }
            printf("%c", s[i]);
        }
        for(int i=0; i<cur; i++)
            printf(")");
        printf("\n");
    }
    return 0;
}
