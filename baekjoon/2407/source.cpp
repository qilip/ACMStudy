#include <stdio.h>

struct bigint{
    unsigned long long a, b;
    bigint(){
        a = 0;
        b = 0;
    }
    bigint operator + (const bigint &o) const{
        bigint rtn;
        rtn.a = a + o.a;
        rtn.b = b + o.b;
        if(rtn.b>=1000000000000000000){
            rtn.b -= 1000000000000000000;
            rtn.a++;
        }
        return rtn;
    }
    bool operator == (const bigint &o) const{
        return (a==o.a && b==o.b);
    }
    bigint & operator = (const bigint &o){
        a = o.a;
        b = o.b;
        return *this;
    }
};

bigint me[110][110];

bigint ncr(int n, int r){
    bigint t;
    t.b = 1;
    if(n==r || r==0) return t;
    if(me[n][r].a || me[n][r].b) return me[n][r];
    me[n][r] = ncr(n-1, r-1) + ncr(n-1, r);
    return me[n][r];
}

int main(void){
    int n ,m;
    scanf("%d %d", &n, &m);
    bigint ans;
    ans = ncr(n, m);
    if(ans.a) printf("%llu%llu", ans.a, ans.b);
    else printf("%llu", ans.b);
    return 0;
}
