#include <stdio.h>

int N, inp[130][130], wh = 0, bl =0;

void dc(int n, int sti, int stj){
    int tmpw = 0, tmpb = 0;
    for(int i=sti;i<sti+n;i++){
        for(int j=stj;j<stj+n;j++){
            if(inp[i][j]) tmpb++;
            else tmpw++;
        }
    }
    if( tmpw && !tmpb ){ wh++; return; }
    if( tmpb && !tmpw ){ bl++; return; }
    n/=2;
    dc(n, sti, stj); dc(n, sti+n, stj); dc(n, sti, stj+n); dc(n, sti+n, stj+n);
}

int main(void){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &inp[i][j]);
        }
    }
    dc(N, 0, 0);
    printf("%d\n%d", wh, bl);
}
