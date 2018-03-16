#include <stdio.h>
#include <string.h>

int main(void){
    char in[1010];
    int card[4][13]={0};
    scanf("%s", in);
    int len = strlen(in);
    for(int i=0;i<len-1;i+=3){
        int c;
        if(in[i]=='P') c=0;
        else if(in[i]=='K') c=1;
        else if(in[i]=='H') c=2;
        else if(in[i]=='T') c=3;
        int ca = ((int)in[i+1]-48)*10+((int)in[i+2]-48)-1;
        if(card[c][ca]==0) card[c][ca]=1;
        else if(card[c][ca]==1) {
            printf("GRESKA");
            return 0;
        }
    }
    for(int i=0;i<4;i++){
        int cnt=0;
        for(int j=0;j<13;j++){
            if(card[i][j]==1) cnt++;
        }
        printf("%d ", 13-cnt);
    }
}
