#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int y = 0, m = 0;
    for(int i=0;i<n;i++){
        int c;
        scanf("%d", &c);
        c++;
        y += c/30 + (c%30>0);
        m += c/60 + (c%60>0);
    }
    y *= 10;
    m *= 15;
    if(y<m) printf("Y %d", y);
    else if(y>m) printf("M %d", m);
    else printf("Y M %d", y);
    return 0;    
}
