#include <stdio.h>
#include <string.h>

char in[1000010];
int main(void){
    scanf("%[^\n]s", in);
    int len = strlen(in), c=0;
    for(int i=0;i<len;i++){
        if('A'<=(int)in[i] && (int)in[i]<='z'&&c==0) c++;
        else if(in[i]==' '&& 'A'<=(int)in[i+1] && (int)in[i+1]<='z') c++;
    }
    printf("%d", c);
}
