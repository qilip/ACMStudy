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

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    int ar[2][300010];
    int lin[600010];
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &ar[0][i]);
    for(int i=0;i<n;i++) scanf("%d", &ar[1][i]);
    ll leftup = 0, leftdown = 0, up = 0, down = 0, dn = 0, un = 0, max = 0, upcnt, downcnt;
    upcnt = downcnt = n*2-1;
    //zigzag
        for(int i=0;i<n*2;i+=2){
            leftup += lin[i] = ar[0][i]*i;
            lin[i] = ar[0][i];
        }
        for(int i=1;i<n*2;i+=2){
            leftup += lin[i] = ar[1][i]*i;
            lin[i] = ar[1][i];
        }
        max = leftdown = leftup;
    // up init
        un += lin[upcnt];
        un += lin[upcnt-1];
        up += lin[upcnt]*upcnt;
        leftup -= lin[upcnt]*upcnt;
        upcnt--;
        up += lin[upcnt]*upcnt;
        leftup -= lin[upcnt]*upcnt;
        upcnt--;
        
    // down init
        for(int i=0;i<3;i++){
            dn += lin[downcnt-i];
            down += lin[downcnt-i]*(downcnt-2+i);
            leftdown -= lin[downcnt-i]*(downcnt-2+i);
        }
        downcnt-=3;
        if(leftdown + down > max) max = leftdown + down;
    //
    while(upcnt>3){
        up -= un*2;
        for(int i=0;i<3;i++){
            un += lin[upcnt-i];
            up += lin[upcnt-i]*(upcnt-2+i);
            leftup -= lin[upcnt-i]*(upcnt-2+i);
        }
        upcnt-=3;
        if(leftup + up > max) max = leftup + up;
    }
    while(downcnt>1){
        down -= dn*2;
        for(int i=0;i<3;i++){
            dn += lin[downcnt-i];
            down += lin[downcnt-i]*(downcnt-2+i);
            leftdown -= lin[downcnt-i]*(downcnt-2+i);
        }
        downcnt-=3;
        if(leftdown + down > max) max = leftdown + down;
    }
    printf("%lld", max);
    return 0;
}
