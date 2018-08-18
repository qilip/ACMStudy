#include <stdio.h>

int n, m, k;
long long tree[1000010];

void update(int i, long long a){
    while(i<=n){
        tree[i] += a;
        i += i&-i;
    }
}

long long find(int a, int b){
    long long ra = 0, rb = 0;
    while(b>0){
        rb += tree[b];
        b -= b&-b;
    }
    while(a>0){
        ra += tree[a];
        a -= a&-a;
    }
    return rb - ra;
}

int main(void){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++){
        long long t;
        scanf("%lld", &t);
        update(i, t);
    }
    for(int i=0;i<m+k;i++){ 
        int a;
        long long b, c;
        scanf("%d %lld %lld", &a, &b, &c);
        if(a==1){
            long long bef = find(b-1, b);
            update(b, c - bef);
        }else{
            printf("%lld\n", find(b-1, c));
        }
    }
    return 0;
}
