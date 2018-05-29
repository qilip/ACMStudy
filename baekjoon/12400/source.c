#include <stdio.h>
#include <string.h>

int main(void){
    // char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    // char crypt[] = { 'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q' };
    char dcryp[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
    int T;
    scanf("%d ", &T);
    for(int t=1;t<=T;t++){
        char g[120] = {0};
        gets(g);
        for(int i=0;g[i]!='\0';i++){
            if(g[i]>='a' && g[i]<='z'){
                g[i] = dcryp[g[i]-'a'];
            }
        }
        printf("Case #%d: ", t);
        puts(g);
    }
}
