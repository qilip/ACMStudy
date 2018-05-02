#include <stdio.h>
#include <string.h>

int main(void){
    unsigned char a[10011], b[10011], c[10010] = { 0 };
    scanf("%s %s", a, b);
    int ai = strlen(a)-1, bi = strlen(b)-1, ci = 0, upp = 0;
    a[10010] = b[10010] = '0';
    for(;;ci++){
        c[ci] = (a[ai]-48 + b[bi]-48 + upp)%10;
        upp = (a[ai]-48 + b[bi]-48 + upp)/10;
        if( (ai==0 || ai==10010) && (bi==0 || bi==10010) ) break;
        if( ai>0 && ai!=10010 ) ai--; else ai = 10010;
        if( bi>0 && bi!=10010 ) bi--; else bi = 10010;
    }
    if(upp) c[++ci] = upp;
    for(int i=ci;i>=0;i--){
        printf("%d", c[i]);
    }
}
