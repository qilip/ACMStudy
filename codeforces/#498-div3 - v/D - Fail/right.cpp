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
    char a[100010];
    char b[100010];
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);

    int cnt = 0;
    if(n%2 && a[n/2] != b[n/2]){
        cnt++;
    }
    for(int i=0;i<n/2;i++){
        int l = i;
        int r = n-1-i;
        if(a[l] == b[l] && a[r] == b[r]) continue;
        else if(a[l] == a[r] && b[l] == b[r]) continue;
        else if(a[l] == b[r] && a[r] == b[l]) continue;

        else if(a[l] == b[l] || a[r] == b[r]) cnt++;
        else if(b[l] == b[r]) cnt++;
        else if(a[l] == b[r] || a[r] == b[l]) cnt++;
        else cnt+=2;
    }
    printf("%d", cnt);
    
    return 0;
}
