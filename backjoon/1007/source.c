#include <stdio.h>
#include <math.h>

typedef struct pnt{
    int x;
    int y;
}pnt;

pnt dot[30];
int N;
double find(int nxtpm, int pcnt, int mcnt, int sumx, int sumy){
    sumx += nxtpm*dot[pcnt+mcnt].x;
    sumy += nxtpm*dot[pcnt+mcnt].y;
    if(pcnt+mcnt == N) return sqrt( pow(sumx, 2.0) + pow(sumy, 2.0) );
    double a = find(1, pcnt+1, mcnt, sumx, sumy);
    double b = find(-1, pcnt, mcnt+1, sumx, sumy);
    if(pcnt == N/2) return b;
    else if(mcnt == N/2) return a;
    else return a>b ? b : a;
}

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        N = 0;
        scanf("%d", &N);
        for(int i=1;i<=N;i++) scanf("%d %d", &dot[i].x, &dot[i].y);
        double srta = find(-1, 0, 1, 0, 0);
        double srtb = find(1, 1, 0, 0, 0);
        printf("%lf\n", srta < srtb ? srta : srtb );
    }
    return 0;
}
