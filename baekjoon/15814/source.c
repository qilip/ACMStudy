#include <stdio.h>

int main(void){
    char s[110];
    scanf("%s", s);
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        char t = s[a];
        s[a] = s[b];
        s[b] = t;
    }
    printf("%s", s);
    return 0;
}
