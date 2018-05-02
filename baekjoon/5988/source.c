#include <stdio.h>
#include <string.h>

int main(void){
    int N;
    scanf("%d", &N);
    while(N--){
        char s[99];
        scanf("%s", s);
        if((s[strlen(s)-1]-'0')%2) printf("odd\n");
        else printf("even\n");
    }
}
