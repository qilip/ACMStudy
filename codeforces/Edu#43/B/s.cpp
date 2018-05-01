#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>

using namespace std;

int main(void){
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    if(k<n) printf("%lld 1", k+1);
    else if(k<n+m-1) printf("%lld %lld", n, (k-(n-1))+1);
    else{
        k = k-(n+m-1);
        long long mm = m-1;
        long long nn = k/mm + 1;
        long long nt = k%mm;
        long long ansn = n - nn;
        long long ansm;
        if(nn%2){
            ansm = m-nt;
        }else{
            ansm = 2+nt;
        }
        printf("%lld %lld", ansn, ansm);
    }
    return 0;
}
