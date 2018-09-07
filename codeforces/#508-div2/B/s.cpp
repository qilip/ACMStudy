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

int gcd(int a, int b){
    return a%b ? gcd(b, a%b) : b;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    int n;
    scanf("%d", &n);
    int sum = (n+1)*n/2;
    int s1 = sum - 2;
    bool flg = true;
    bool chk[45001] = {false};
    int s2 = 2;
    while(flg){
        if(s1< sum/2){
            printf("No");
            return 0;
        }
        if(gcd(s2, s1) > 1){
            flg = false;
        }else{
            s2++;
            s1--;
        }
    }
    int ck = n;
    int s1cnt = 0;
    while(s1){
        if(ck<=s1){
            s1 -= ck;
            chk[ck] = true;
            s1cnt++;
        }
        ck--;
    }
    printf("Yes\n");
    printf("%d ", s1cnt);
    for(int i=1;i<=n;i++){
        if(chk[i]) printf("%d ", i);
    }
    printf("\n");
    printf("%d ", n-s1cnt);
    for(int i=1;i<=n;i++){
        if(!chk[i]) printf("%d ", i);
    }
    return 0;
}
