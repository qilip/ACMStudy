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

int n, w, a[1010] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &w);
    for(int i=0;i<n;i++){
        int c;
        scanf("%d", &c);
        a[i+1] = a[i] + c;
    }
    int minw = 0, maxw = w;
    
    maxw = w - *max_element(a+1, a+n+1);
    minw = 0 - *min_element(a+1, a+n+1);

    if(minw < 0) minw = 0;
    if(maxw > w) maxw = w;

    if(minw > w || maxw < 0) printf("0");
    else printf("%d", maxw - minw + 1);
    
    return 0;
}
