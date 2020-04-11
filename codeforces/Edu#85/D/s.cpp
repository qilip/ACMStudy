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
        int n;
        ll l, r;
        scanf("%d %lld %lld", &n, &l, &r);
        ll start = 1;
        for(int i=1;i<=n;i++){
            if(start + (n-i)*2 <= l){
                start += (n-i)*2;
                continue;
            }
            if(start > r) break;
            for(int j=1; j<=(n-i)*2;j++){
                if(start < l){
                    start++;
                    continue;
                }
                if(start > r) break;
                if(j%2){
                    printf("%d ", i);
                }else{
                    printf("%d ", i+j/2);
                }
                start++;
            }
        }
        if(r == (ll)(n-1)*n+1) printf("1");
        printf("\n");
    }
    
    return 0;
}
