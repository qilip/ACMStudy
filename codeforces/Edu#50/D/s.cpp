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
int a[300'010];
int b[300'010];
int pa, pb;
ll cnta, cntb;
int ans;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &b[i]);
    }
    while(pa<n && pb<m){
        if(cnta==0 && cntb==0){
            cnta += a[pa++];
            cntb += b[pb++];
        }else if(cnta>cntb){
            cntb += b[pb++];
        }else if(cnta<cntb){
            cnta += a[pa++];
        }
        if(cnta==cntb && cnta!=0){
            ans++;
            cnta = 0;
            cntb = 0;
        }
    }
    if(pa==n){
        while(pb<m){
            cntb += b[pb++];
        }
        if(cnta==cntb && cnta!=0){
            ans++;
            cnta = 0;
            cntb = 0;
        }
    }else if(pb==m){
        while(pa<n){
            cnta += a[pa++];
        }
        if(cnta==cntb && cnta!=0){
            ans++;
            cnta = 0;
            cntb = 0;
        }        
    }
    if(pa!=n || pb!=m || cnta!=cntb){
        printf("-1");
    }else{
        printf("%d", ans);
    }
    return 0;
}
