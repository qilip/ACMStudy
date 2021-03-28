#include <stdio.h>
#include <string.h>

char s[100];
char c[100];
char m[100];

void cns(int a, int b){
    for(int j=0;j<b-a+1;j++){
        c[b-j] = s[a+j];
    }
    return;
}

int main(void){
    scanf(" %s", s);
    int sl = strlen(s);
    cns(0, sl-1);
    strcpy(m, c);
    for(int i=0;i<sl-2;i++){
        cns(0, i);
        for(int j=i+1;j<sl-1;j++){
            cns(i+1, j);
            cns(j+1, sl-1);
            if(strcmp(c, m)<0) strcpy(m, c);
        }
    }
    
    printf("%s", m);
    return 0;
}
