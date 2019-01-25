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

    int n, a[1010] = {0};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int mini = 9999'9999;
    int curi = 0;
    for(int i=1;i<=100;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(a[j]<i) sum += abs(a[j]-(i-1));
            if(a[j]>i) sum += abs(a[j]-(i+1));
        }
        if(sum < mini){
            mini = sum;
            curi = i;
        }
    }
    printf("%d %d", curi, mini);
    return 0;
}
