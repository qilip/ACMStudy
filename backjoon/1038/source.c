#include <stdio.h>

int nn[10][11] = {
    { 1,1,1,1,1,1,1,1,1,1 },
    { 0, },
};
int N, cnt  = 10, i, j, k, q, w, e, r, ans[10] = {0};

void addn(int a){
    if(ans[a]+1 < ans[a+1]){
        ans[a]++;
        for(w = 0;w<a;w++) ans[w] = w;
    }
    else addn(a+1);
}

int main(void){
    scanf("%d", &N);
    if(N<10){ printf("%d", N); return 0; }
    else if(N>1022){ printf("-1"); return 0; }
    for(i=1;i<=9;i++){
        for(j=i;j<10;j++){
            k = 0;
            for(q = 0;q<=j-1;q++) k += nn[i-1][q];
            nn[i][j] = k;
            if(cnt+k <= N) cnt += k;
            else goto JMP;
        }
    }
    JMP:; ans[i] = j;
    for(w = 0;w<i;w++) ans[w] = w;
    for(e = 0;e<N-cnt;e++) addn(0);
    for(r = i; r>=0;r--) printf("%d", ans[r]);
    return 0;
}
