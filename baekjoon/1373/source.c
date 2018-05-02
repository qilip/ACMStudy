#include <stdio.h>
#include <string.h>

char in[1000010];
int main(void){
    scanf("%s", in); 
    int len = strlen(in);
    int t = len%3, i = 0;
    switch(t){
        case 1: {
            printf("%d", (int)in[0] -'0' );
            i++;
            break;
        }
        case 2: {
            printf("%d", ((int)in[0]-'0')*2 + (int)in[1]-'0' );
            i+=2;
            break;
        }
    }
    for(i;i<len;i+=3){
        printf("%d", ((int)in[i]-48)*4 + ((int)in[i+1]-48)*2 + (int)in[i+2]-48);
    }
}
