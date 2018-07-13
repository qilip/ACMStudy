#include <stdio.h>

typedef long long ll;

ll sum = 0, r = 31, m = 1234567891;

ll rr(int a){
    ll s = 1;
    for(int i=0;i<a;i++){
        s *= r;
        s %= m;
    }
    return s;
}

int main(void){
    int l;
    char s[60];
    scanf("%d", &l);
    scanf("%s", s);
    for(int i=0;i<l;i++){
        sum += (s[i]-'a'+1)*rr(i);
        sum %= m;
    }
    printf("%lld", sum);
    return 0;
}
