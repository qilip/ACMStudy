#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    for(int q=1;q<=T;q++){
        int N, V1[50030], V2[50030];
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            if((i+1)%2) scanf("%d", &V1[i/2+i%2]);
            else scanf("%d", &V2[i/2]);
        }
        sort(V1, V1+(N/2)+(N%2));
        sort(V2, V2+(N/2));
        for(int i=0;i<N/2;i++){
            if(V1[i]>V2[i]){
                i *=2;
                printf("Case #%d: %d\n", q, i);
                goto SubEnd;
            }
            if(i+1<=(N/2-1+N%2) && V2[i]>V1[i+1]){
                i =i*2+1;
                printf("Case #%d: %d\n", q, i);
                goto SubEnd;             
            }
        }
        if(N%2 && V1[N/2]<V2[N/2-1]) {
            printf("Case #%d: %d\n", q, N/2);
            continue;
        }
        printf("Case #%d: OK\n", q);
        SubEnd:;
    }
}
