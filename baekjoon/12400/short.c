#include <stdio.h>

int main(void){
    char d[]="yhesocvxduiglbkrztnwjpfmaq";
    int T;
    scanf("%d ", &T);
    for(int t=1;t<=T;t++){
        char g[120];
        gets(g);
        for(int i=0;g[i]!='\0';i++){
            if(g[i]>='a'&&g[i]<='z'){
                g[i]=d[g[i]-'a'];
            }
        }
        printf("Case #%d: ", t);
        puts(g);
    }
}
