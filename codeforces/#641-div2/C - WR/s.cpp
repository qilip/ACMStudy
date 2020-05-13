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
#include <bitset>

using namespace std;

typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int era[200010] = {0};
    int prime[1010] = {0};
    int pcnt = 0;
    for(int i=2;i<=sqrt(20'0000);i++){
        if(era[i]) continue;
        prime[pcnt++] = i;
        for(int j=i+i;j<=20'0000;j+=i){
            era[j] = 1;
        }
    }
    int n;
    scanf("%d", &n);
    int a[100010] = {0};

    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int ans = 1;
    for(int i=0;i<pcnt;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(!(a[j]%prime[i])){
                a[j]/=prime[i];
                cnt++;
            }
        }
        if(cnt>=n-1){
            ans *= prime[i];
            i = -1;
        }
    }
    printf("%d", ans);
    return 0;
}
