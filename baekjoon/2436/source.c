#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b){
    return a%b ? gcd(b, a%b) : b;
}

int main(void){
    ll A, B;
    scanf("%lld %lld", &A, &B);
    ll m = A*B, mina = A, minb = B;
    for(ll i=A;i*i<=m;i+=A){
        ll tmp = m/i;
        ll q = gcd(i, tmp);
        if(q == A && i*tmp/q == B && mina+minb>i+tmp){
            mina = i;
            minb = tmp;
        }
    }
    printf("%lld %lld", mina, minb);
    return 0;
}
