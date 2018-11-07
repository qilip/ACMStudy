// #include <bits/stdc++.h>

/* codeforces printf %Lf problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef long long ll;

int ss[1500'0001];

int gcd(int a, int b){
    return a%b ? gcd(b, a%b) : b;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    int a[300'010];
    int maxi = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        if(maxi < a[i]) maxi = a[i];
    }
    int gg = gcd(a[0], a[1]);
    for(int i=2;i<n;i++){
        gg = gcd(gg, a[i]);
    }

    for(int i=0;i<n;i++){
        int cur = a[i];
        for(int j=gg;j*j<=cur;j++){
            if(cur%j==0){
                ss[j]++;
                if(j!=cur/j) ss[cur/j]++;
            }
        }
    }
    int max = 0;
    for(int i = maxi;i>gg;i--){
        if(max < ss[i]) max = ss[i];
    }
    if(!max) printf("-1");
    else printf("%d", n-max);
    return 0;
}