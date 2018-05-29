#include <stdio.h>

int pow(int a, int b){
    int t = a;
    for(int i=1;i<b;i++){
        t*=a;
    }
    return t;
}

int N, era[1000010], inp[103][100010], ans = 1, cnt = 0, pcnt = 0;

int main(void){
    for(int i=2;i<1001;i++){
        if(era[i]) continue;
        for(int j=i+i;j<1000001;j+=i){
            era[j] = 1;
        }
        inp[102][pcnt++] = i;
    }
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d", &tmp);
        for(int j=2;j<=tmp;j++){
            if(era[j]) continue;
            if(!(tmp%era[j])){
                tmp/=era[j];
                inp[i][j]++;
                inp[101][j]++;
            }
        }
    }
    for(int i=0;i<N;i++){
        
    }
    return 0;
}
