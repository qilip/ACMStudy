#include <stdio.h>

int main(void){
    char s;
    s = getchar();
    while(s!=EOF){
        putchar(s);
        s = getchar();
    }
    return 0;
}
