#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long w[1010], e[1010], tot = 0;

int main(void){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld", &e[i]);
    }
    for(int i=1;i<n-1;i++){
        long long a = max(w[0], w[i]) * max(e[0], e[i]);
        long long b = max(w[i+1], w[i]) * max(e[i+1], e[i]);
        if(a<=b){
            w[0] = max(w[0], w[i]);
            e[0] = max(e[0], e[i]);
        }else{
            w[i+1] = max(w[i+1], w[i]);
            e[i+1] = max(e[i+1], e[i]);
        }
    }
    tot = max(w[0], w[n-1]) * max(e[0], e[n-1]);
    printf("%lld", tot);
    return 0;
}
