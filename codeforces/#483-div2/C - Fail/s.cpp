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

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    scanf("%d", &n);
    while(n--){
        ll p, q, b;
        scanf("%lld %lld %lld", &p, &q, &b);
        if(p==0 || q==1){
            printf("Finite\n");
            continue;
        }
        ll na = (p%q)*b/q;
        ll nb = q/b;
        if( na*q == (p%q)*b || nb*b == q ){
            printf("Finite\n");
        }else{
            printf("Infinite\n");
        }
    }    
    return 0;
}
