#include <stdio.h>
#include <string.h>
#include <ctype.h>

char in[1000010];
int main(void){
    scanf("%s", in);
    int len=strlen(in), al[30]={0}, max = 0, mcnt = 0, idx=0;
    for(int i=0;i<len;i++){
        idx = toupper(in[i])-'A';
        al[idx]++;
        if(al[idx] > max) max=al[idx];
    }
    for(int i=0;i<26;i++){
        if(al[i]==max) {
            mcnt++;
            idx = i;
        }
    }
    if(mcnt>1) printf("?");
    else printf("%c", (char)idx+'A');
}
