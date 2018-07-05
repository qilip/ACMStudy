#include <stdio.h>

int main(void){
    int m, s[21] = {0};
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        char c[10];
        int x;
        scanf("%s %d", c, &x);
        switch(c[0]){
            case 'a':
                if(c[1]=='d')
                    s[x] = 1;
                else
                    for(int i=1;i<=20;i++) s[i] = 1;
                break;
            case 'r':
                s[x] = 0;
                break;
            case 'c':
                printf("%d\n", s[x]);
                break;
            case 't':
                s[x] = s[x] ? 0 : 1 ;
                break;
            case 'e':
                for(int i=1;i<=20;i++) s[i] = 0;
                break;
        }
    }
    return 0;
}
