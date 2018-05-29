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

ll gcd(ll a, ll b)
{
	return a%b ? gcd(b, a%b) : b;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, a, b, p, q, acnt = 0, bcnt = 0;
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &p, &q);
    acnt = n/a;
    bcnt = n/b;
    if(p>q){
        bcnt -= n/(a*b/gcd(a, b));
    }else{
        acnt -= n/(a*b/gcd(a, b));
    }
    printf("%lld", acnt*p+bcnt*q);
    return 0;
}
