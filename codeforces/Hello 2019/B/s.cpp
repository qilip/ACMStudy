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

int n;
int a[20];
int p;

void asdf(int cur, int sum){
    if(sum%360==0) sum = 0;
    if(cur == n-1){
        if(sum==0) p = 1;
        return;
    }
    asdf(cur+1, sum+a[cur+1]);
    asdf(cur+1, sum-a[cur+1]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    asdf(0, a[0]);
    asdf(0, -a[0]);
    
    if(p) printf("YES");
    else printf("NO");

    return 0;
}
