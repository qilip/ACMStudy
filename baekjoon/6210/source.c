#include <stdio.h>
#include <math.h>

int d, n;

typedef long long ll;

int power[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return 0;
    }
    return 1;
}

int isWon(void){
    ll a, b;
    for(int cd = d;cd<10;cd++){
        a = n/power[cd];
        b = n%power[cd];
        if(b/power[d-1]==0 || a/power[d-1]==0) continue;
        if(isPrime(a) && isPrime(b)) return 1;
    }
    return 0;
}

int main(void){
    scanf("%d %d", &d, &n);
    if(power[d*2-1]>n) n = power[d*2-1];
    if(n%2==0) n++;
    while(!isWon()){
        n+=2;
    }
    printf("%d", n);
    return 0;
}
