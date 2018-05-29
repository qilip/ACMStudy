#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

ll pow(ll a, ll b){
    if(b==0) return 1;
    for(int i=1;i<b;i++){
        a*=a;
    }
    return a;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, n, x;
    scanf("%lld %lld %lld %lld", &a, &b, &n, &x);
    if(a==1){
        printf("%lld", x+b*n);
        return 0;
    }
    ll alpha = b/(a-1);
    ll answer = (x+alpha)*pow(a, n-1)-alpha;
    answer%=1000000007;
    printf("%lld", answer);
    return 0;
}
