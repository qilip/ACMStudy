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

int a[200010] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        bool peak[200010] = {false};
        int peakpsum[200010] = {0};
        for(int i=1;i<n-1;i++){
            if(a[i-1] < a[i] && a[i] > a[i+1]){
                peakpsum[i] = peakpsum[i-1] + 1;
                peak[i] = true;
            }else peakpsum[i] = peakpsum[i-1];
        }
        peakpsum[n-1] = peakpsum[n-2];
        int maxp = 0;
        int maxi = 0;
        for(int i=0;i<=n-k;i++){
            if(maxp < peakpsum[i+k-1] - peakpsum[i] - peak[i+k-1]){
                maxp = peakpsum[i+k-1] - peakpsum[i] - peak[i+k-1];
                maxi = i;
            }
        }
        printf("%d %d\n", maxp+1, maxi+1);
    }
    
    return 0;
}
