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
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int n;
char a[100010], b[100010];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    int zz_cnt = 0, zo_cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(a[i]=='0'){
            if(b[i]=='0'){
                zz_cnt++;
            }else{
                zo_cnt++;
            }
        }
    }
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            if(b[i]=='1'){
                cnt += zz_cnt;
            }else{
                cnt += zz_cnt+zo_cnt;
            }
        }
    }
    printf("%lld", cnt);
    return 0;
}
