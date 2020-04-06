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
        int n, x;
        int cnt[300] = {0};
        scanf("%d %d", &n, &x);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d", &a);
            cnt[a] = 1;
        }
        for(int i=1;i<=300;i++){
            if(cnt[i]==0){
                if(x){
                    x--;
                }else{
                    printf("%d\n", i-1);
                    break;
                }
            }
        }

    }
    
    return 0;
}
