#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        for(int i=2;N>1;i++){
            if(!(N%i)){
                if(i==N) printf("%d\n", i);
                else printf("%d ", i);
                N /= i;
                i = 1;
            }
        }
    }
    return 0;
}
