#include <stdio.h>

int prime[1000100];

void findPrime(void){
    for(int i=2;i<999999;i++){
        if(!prime[i]){
            for(int j=i+i;j<999999;j+=i){
                prime[j] = 1;
            }
        }
    }
}

int main(void){
    findPrime();
    while(1){
        int n, a = 3;
        scanf("%d", &n);
        if(!n) break;
        for(;a<999999;a++){
            if(!prime[a] && !prime[n-a]) break;
        }
        printf("%d = %d + %d\n", n, a, n-a);
    }
    return 0;
}
