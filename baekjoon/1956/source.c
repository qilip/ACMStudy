#include <stdio.h>
#include <string.h>
#define MAX 0x3f3f3f3f

int main(void){
    int v, e;
    int d[410][410];
    memset(d, 0x3f, sizeof d);
    scanf("%d %d", &v, &e);
    for(int i=0;i<e;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = c;
    }
    for(int k=1;k<=v;k++)
        for(int i=1;i<=v;i++)
            for(int j=1;j<=v;j++)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    int min = MAX;
    for(int i=1;i<=v;i++)
        if(min > d[i][i]) min = d[i][i];
    if(min == MAX) min = -1;
    printf("%d", min);
    return 0;
}
