#include <stdio.h>
int nn[1010][1010];
int main(void) {
    int N, F;
    scanf("%d", &N);
    scanf("%d", &F);
    int ptrh = N/2+1, ptrw = N/2+1;
    int ph = -1, pw=-1, mh=0, mw=0, mvt = 0, mvc = 0, Fh, Fw;
    nn[ptrh][ptrw] = 1;
    for(int i=2;i<=N*N;){
        int mvv = mvt%4;
        switch(mvv) {
            case 0: { ph += 2; mvc = ph; break; }
            case 1: { pw += 2; mvc = pw; break; }
            case 2: { mh += 2; mvc = mh; break; }
            case 3: { mw += 2; mvc = mw; break; }
        }
        for(int j=0;j<mvc;j++){
            switch(mvv) {
                case 0: { ptrh--; break; }
                case 1: { ptrw++; break; }
                case 2: { ptrh++; break; }
                case 3: { ptrw--; break; }
            }
            nn[ptrh][ptrw] = i;
            if(i == F) { Fh=ptrh; Fw=ptrw; }
            i++;
        }
        mvt++;
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            printf("%d ", nn[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", Fh, Fw);
}
