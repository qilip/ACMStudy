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
#include <iostream>
#include <iomanip>
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
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, sc[1010];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sc[i] = a+b+c+d;
    }
    int to = sc[0];
    sort(sc, sc+n, greater<int>());
    for(int i=0;i<n;i++){
        if(sc[i]==to){
            printf("%d", i+1);
            break;
        }
    }

    return 0;
}
