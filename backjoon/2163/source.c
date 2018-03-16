#include <stdio.h>
int s[310][310]={0};

int bb(int h, int w){
    int ha, wa;
    if(h>w) { ha=h; wa=w; }
    else { ha=w; wa=h; }
    if(ha==1&&wa==1) return 0;
    else if(ha==2&&wa==1) return 1;    
    else if(s[ha][wa]) return s[ha][wa];
    else return s[ha][wa] = bb(ha/2, wa) + bb(ha-ha/2, wa) + 1;
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", bb(a, b));
}
