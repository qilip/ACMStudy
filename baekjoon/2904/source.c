#include <stdio.h>

int ipow(int b, int a){
    int s = 1;
    while(a--){
        s *= b;
    }
    return s;
}

int era[1000001], inp[102][100001], N, ans = 1, cnt = 0, ptr = 0;

int main(void){
    for(int i=2;i<1001;i++){
        if(era[i]) continue;
        for(int j=i+i;j<1000001;j+=i){
            era[j] = 1;
        }
    }
    for(int i=2;i<1000001;i++){
        if(!era[i]){
            inp[101][ptr++] = i;
        }
    }
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d", &tmp);
        for(int j=0;inp[101][j]<=tmp;j++){
            while(!(tmp%inp[101][j])){
                tmp/=inp[101][j];
                inp[i][j]++;
                inp[100][j]++;
            }
        }
    }
    for(int i=0;i<ptr;i++){
        if(!(inp[100][i]/N)) continue;
        int s = inp[100][i]/N;
        ans *= ipow(inp[101][i], s);
        for(int j=0;j<N;j++){
            if(inp[j][i]<s){
                cnt += s-inp[j][i];
            }
        }
    }
    printf("%d %d", ans, cnt);
    return 0;
}
