#include <stdio.h>
#include <string.h>

int status;
void s(int inp){
    switch(status){
        case 0:{
            status = inp ? 2 : 1;
            break;
        }case 1:{
            status = inp ? 3 : -1;
            break;
        }case 2:{
            status = inp ? -1 : 4;
            break;
        }case 3:{
            status = inp ? 2 : 1;
            break;
        }case 4:{
            status = inp ? -1 : 5;
            break;
        }case 5:{
            status = inp ? 6 : 5;
            break;
        }case 6:{
            status = inp ? 7 : 1;
            break;
        }case 7:{
            status = inp ? 7 : 8;
            break;
        }case 8:{
            status = inp ? 3 : 5;
        }
    }
}

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        char N[220];
        scanf("%s", N);
        int len = strlen(N);
        status = 0;
        for(int i=0; i<len; i++){
            int now = N[i]=='0' ? 0 : 1;
            s(now);
            if(status == -1) break;
        }
        if( status == 3 || status == 6 || status == 7 ) printf("YES\n");
        else printf("NO\n");
    }
}
