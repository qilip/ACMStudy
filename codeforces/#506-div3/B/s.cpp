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

    int n, nn[200010];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    int cnt = 1, cur = nn[0], max = 1;
    for(int i=1;i<n;i++){
        if(cur*2>=nn[i]){
            cur = nn[i];
            cnt++;
            if(max<cnt) max = cnt;
        }else{
            cur = nn[i];
            cnt = 1;
        }
    }
    printf("%d", max);
    
    return 0;
}
