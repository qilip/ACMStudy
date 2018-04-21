#include <stdio.h>
#include <string.h>

int main(void){
    int N;
    scanf("%d", &N);
    while(N--){
        char inp[130];
        scanf("%s", inp);
        gets(inp);
        printf("god");
        for(int i=0;i<strlen(inp);i++){
            if(inp[i]!=32) printf("%c", inp[i]);
        }
        printf("\n");
    }
}
