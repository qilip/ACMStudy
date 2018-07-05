#include <stdio.h>

int main(void){
    char s[2];
    double sc = 0;
    scanf("%s", s);
    switch(s[0]){
        case 'A': sc = 4.3; break;
        case 'B': sc = 3.3; break;
        case 'C': sc = 2.3; break;
        case 'D': sc = 1.3; break;
        case 'F': printf("0.0"); return 0;
    }
    switch(s[1]){
        case '+': break;
        case '0': sc -= 0.3; break;
        case '-': sc -= 0.6; break;
    }
    printf("%0.1f", sc);
    return 0;
}
