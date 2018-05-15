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
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, cut = 0;
    scanf("%lld", &n);
    n++;
    if(n==1){
        cut = 0;
    }else if(n%2==0){
        cut = n/2;
    }else{
        cut = n;
    }
    printf("%lld", cut);    
    return 0;
}
