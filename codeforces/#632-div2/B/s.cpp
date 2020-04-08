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

    int t;
    scanf("%d", &t);
    while(t--){
        int n, a[100010] = {0}, b[100010] = {0};
        int mcnt = 0, pcnt = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
            if(a[i] == 1) pcnt++;
            else if(a[i] == -1) mcnt++;
        }
        for(int i=0;i<n;i++){
            scanf("%d", &b[i]);
        }
        if(a[0] != b[0]){
            printf("NO\n");
            continue;
        }
        bool ans = true;
        for(int i=n-1;i>0;i--){
            if(a[i] == 1) pcnt--;
            else if(a[i] == -1) mcnt--;
            if(a[i] == b[i]) continue;
            if(a[i]-b[i] > 0){
                if(!mcnt) ans = false;
            }else{
                if(!pcnt) ans = false;
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
