#include <stdio.h>
#include <math.h>

int main(void){
    int N = 0, inp, z = 0, cnt = 0, chancnt = 0;
    while(1){
        scanf("%c", &inp);
        if(inp==EOF) break;
        cnt++;
        N += inp;
    }
    if(cnt==1) goto A;
    z = log10(N) + 1;
    while(z>1){
        for(int i=z;i>=0;i--){
            
        }
        chancnt++;
        z = log10(N) + 1;
    }

    A:;
    
}
