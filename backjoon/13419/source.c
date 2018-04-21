#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        char inp[30];
        scanf("%s", inp);
        int len = strlen(inp) - 1;
        if((len + 1)%2){
            for(int i=0;i<=len;i+=2) printf("%c", inp[i]);
            for(int i=1;i<=len;i+=2) printf("%c", inp[i]);
            printf("\n");
            for(int i=1;i<=len;i+=2) printf("%c", inp[i]);
            for(int i=0;i<=len;i+=2) printf("%c", inp[i]);
            printf("\n");
        }else{
            for(int i=0;i<=len;i+=2) printf("%c", inp[i]);
            printf("\n");
            for(int i=1;i<=len;i+=2) printf("%c", inp[i]);
            printf("\n");
        }
    }
    return 0;
}
