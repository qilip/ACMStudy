#include <stdio.h>

int n, m, max = 0, nm[1010][1010] = {0};

int minn(int a, int b, int c){
    if(!a || !b || !c) return 0;
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    if(c<=a && c<=b) return c;
    return -1;
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %1d", &nm[i][j]);
            if(nm[i][j]) max = 1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(nm[i][j])
                nm[i][j] = minn(nm[i-1][j-1], nm[i][j-1], nm[i-1][j]) + 1;
            if(nm[i][j] > max) max = nm[i][j];
        }
    }
    printf("%d", max*max);
    return 0;
}
