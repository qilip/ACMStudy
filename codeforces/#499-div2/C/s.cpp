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

    int n, m, a[1010], b[1010];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }

    double mass = (double)m;
    if(!(b[0]-1)){ printf("-1"); return 0;};
    mass += (mass)/(double)(b[0]-1);
    if(!(a[n-1]-1)){ printf("-1"); return 0;};
    mass += (mass)/(double)(a[n-1]-1);
    for(int i=n-1;i>0;i--){
        if(!(b[i]-1)){ printf("-1"); return 0;};
        mass += (mass)/(double)(b[i]-1);
        if(!(a[i-1]-1)){ printf("-1"); return 0;};
        mass += (mass)/(double)(a[i-1]-1);
    }
    printf("%f", mass-(double)m);
    return 0;
}
