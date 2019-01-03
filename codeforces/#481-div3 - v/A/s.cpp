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
    int nn[1010] = {0};
    vector<int> v;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int cur;
        scanf("%d", &cur);
        nn[cur] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<1010;j++){
            if(nn[j]==i){
                v.push_back(j);
                break;
            }
        }
    }
    printf("%d\n", v.size());
    for(auto i: v){
        printf("%d ", i);
    }
    return 0;
}
