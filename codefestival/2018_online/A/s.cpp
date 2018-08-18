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

    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = 0;

        if(a==0){

        }else if(a==1){
            ans += 500;
        }else if(a<=3){
            ans += 300;
        }else if(a<=6){
            ans += 200;
        }else if(a<=10){
            ans += 50;
        }else if(a<=15){
            ans += 30;
        }else if(a<=21){
            ans += 10;
        }
        if(b==0){

        }else if(b<=1){
            ans += 512;
        }else if(b<=3){
            ans += 256;
        }else if(b<=7){
            ans += 128;
        }else if(b<=15){
            ans += 64;
        }else if(b<=31){
            ans += 32;
        }
        ans *= 10000;
        printf("%d\n", ans);
    }
    
    return 0;
}
