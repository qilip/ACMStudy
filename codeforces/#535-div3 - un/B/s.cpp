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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    int nn[200];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    sort(nn, nn+n, greater<int>());
    int x = nn[0];
    vector<int> xv;
    for(int i=1;i<=x;i++){
        if(x%i==0) xv.push_back(i);
    }
    sort(xv.begin(), xv.end(), greater<int>());
    for(int i=0;i<n;i++){
        if(!xv.empty() && xv[0] == nn[i]){
            xv.erase(xv.begin());
        }else{
            printf("%d %d", x, nn[i]);
            break;
        }
    }
    return 0;
}
