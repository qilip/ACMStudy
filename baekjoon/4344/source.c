#include <stdio.h>

int main(void){
    int C;
    scanf("%d", &C);
    for(int i=0;i<C;i++){
        int N, in[1010], sum=0, cnt=0;
        scanf("%d", &N);
        for(int j=0;j<N;j++){
            scanf("%d", &in[j]);
            sum+=in[j];
        }
        double avg = (double)sum/(double)N;
        for(int j=0;j<N;j++) if(avg<in[j]) cnt++;
        double out = (double)cnt/(double)N*100;
        printf("%2.3f%%\n", out);
    }
}
