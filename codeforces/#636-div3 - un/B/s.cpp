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

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        if((n/2)%2) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<n;i+=2){
                printf("%d ", i+2);
            }
            for(int i=0;i<n-2;i+=2){
                printf("%d ", i+1);
            }
            printf("%d\n", n-1+n/2);
        }
    }
    
    return 0;
}
