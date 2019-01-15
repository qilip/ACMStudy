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
        int flg[10] = {0};
        if(a[i] == a[n-1-i]) flg[0] = 1;
        if(b[i] == b[n-1-i]) flg[1] = 1;
        if(a[i] == b[i]) flg[2] = 1;
        if(a[n-1-i] == b[n-1-i]) flg[3] = 1;
        if(a[i] == b[n-1-i]) flg[4] = 1;
        if(b[i] == a[n-1-i]) flg[5] = 1;
        
        if(flg[0] && flg[1]) continue;
        else if(flg[4] && flg[5]) continue;
        else if(flg[2] && flg[3]) continue;

        else if(!flg[2] && !flg[3] && !flg[4] && !flg[5]) cnt+=2;
        else cnt++;
    }
    printf("%d", cnt);
    
    return 0;
}
