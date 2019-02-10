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
int a[100010];
int c[100010];
pair<int, int> p[100010];
int ptr = 1;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &c[i]);
        p[i].first = c[i];
        p[i].second = i;
    }
    sort(p+1, p+n+1);

    for(int i=0;i<m;i++){
        int t, j;
        scanf("%d %d", &t, &j);
        if(a[t]>=j){
            a[t] -= j;
            printf("%lld\n", (ll)j*(ll)c[t]);
        }else{
            j -= a[t];
            ll sum = 0;
            sum += (ll)a[t]*(ll)c[t];
            a[t] = 0;
            while(j){
                if(ptr>n){
                    sum = 0;
                    break;
                }
                if(a[p[ptr].second]>=j){
                    a[p[ptr].second] -= j;
                    sum += (ll)j*(ll)c[p[ptr].second];
                    break;
                }else{
                    j -= a[p[ptr].second];
                    sum += (ll)a[p[ptr].second]*(ll)c[p[ptr].second];
                    a[p[ptr].second] = 0;
                    ptr++;
                }
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}
