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

    int n, st[100010];
    scanf("%d", &n);
    int a = 1;
    for(int i=1;i<=n;i+=2){
        st[i] = a;
        a++;
    }
    int b = n;
    for(int i=2;i<=n;i+=2){
        st[i] = b;
        b--;
    }
    for(int i=1;i<=n;i++) printf("%d ", st[i]);
    return 0;
}
