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

using namespace std;

typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    int n, k;
    int chk[30] = {0};
    char s[100010];
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for(int i=0;i<n;i++){
        chk[s[i]-'A']++;
    }
    int ans = *min_element(chk, chk+k);
    printf("%d", ans*k);
    return 0;
}
