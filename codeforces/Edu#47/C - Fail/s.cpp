// #include <bits/stdc++.h>

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
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    double ans = 0.0;
    scanf("%d %d", &n, &m);
    while(m--){
        int x, d;
        scanf("%d %d", &x, &d);
        ans += x*n;
        int r = 0;
        if(d>=0) r = ((n-1)+1)*(n-1)/2;
        else{
            r = ((n-1)/2+1)*((n-1)/2)/2;
            if(!(n%2)) r += n/2;
        }
        ans += r*d;
    }
    printf("%f", ans/(double)n);
    return 0;
}
