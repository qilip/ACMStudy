#include <stdio.h>

char nm[60][60];

int find(int a, int b){
    int cnt = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if( (i+j)%2 && nm[i+a][j+b] == 'W' ) cnt++;
            else if( !((i+j)%2) && nm[i+a][j+b] == 'B' ) cnt++;
        }
    }
    return cnt>64-cnt ? 64-cnt : cnt;
}

int main(void){
    int N, M, cng = 64;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        scanf("%s", nm[i]);
    }
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            int tmp = find(i, j);
            if(cng > tmp) cng = tmp;
        }
    }
    printf("%d", cng);
}
