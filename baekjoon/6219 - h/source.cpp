#include <stdio.h>

int a, b, d;
bool notPrime[4000010];

void era(void){
    notPrime[0] = notPrime[1] = true;
    for(int i=2;i*i<=b;i++){
        if(!notPrime[i]){
            for(int j=i*i;j<=b;j+=i){
                notPrime[j] = true;
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &a, &b, &d);
    era();
    int cnt = 0;
    for(int i=a;i<=b;i++){
        if(notPrime[i]) continue;
        
    }
    printf("%d", &cnt);
    return 0;
}
