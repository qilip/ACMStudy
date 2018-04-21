#include <stdio.h>
#include <string.h>

int main(void){
    while(1){
        char inp[510];
        gets(inp);
        if(!strcmp(inp, "END")) break;
        for(int i=strlen(inp)-1; i>=0;i--){
            printf("%c", inp[i]);
        }
        printf("\n");
    }
    return 0;
}
