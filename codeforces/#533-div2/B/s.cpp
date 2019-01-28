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

    int n, k;
    char s[200010];
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int abc[30] = {0};
    int cnt = 1;
    if(cnt>=k){
        abc[s[0]-'a']++;
        cnt = 0;
    }
    for(int i=1;i<n;i++){
        if(s[i] != s[i-1]){
            cnt = 1;
        }else{
            cnt++;
        }
        if(cnt>=k){
            abc[s[i]-'a']++;
            cnt = 0;
        }
    }
    if(cnt>=k) abc[s[n-1]-'a']++;
    sort(abc, abc+28, greater<int>());
    printf("%d", abc[0]);

    return 0;
}
