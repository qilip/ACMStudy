#include <cstdio>
#include <algorithm>

int main(void){
    int N, in[20001];
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &in[i]);
    std::sort(in, in+N);
    if(N%2) N=N/2;
    else N=N/2-1;
    printf("%d", in[N]);
}
