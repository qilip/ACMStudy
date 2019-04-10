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

int n, m;
int a[510][510];
int c[510][510];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int no = 0;
    for(int i=0;i<n;i++){
        int wcnt = 0;
        for(int j=0;j<m;j++){
            int t;
            scanf("%d", &t);
            if(t==a[i][j]) c[i][j] = 0;
            else{
                c[i][j] = 1;
                wcnt++;
            }
        }
        if(wcnt%2) no = 1;
    }
    for(int j=0;j<m;j++){
        int hcnt = 0;
        for(int i=0;i<n;i++){
            if(c[i][j]) hcnt++;
        }
        if(hcnt%2) no = 1;
    }
    if(no) printf("No");
    else printf("Yes");
    
    return 0;
}
