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
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

char nn[200010], mm[200010];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    
    int n, m;
    scanf("%d %d", &n, &m);
    scanf(" %s", nn);
    scanf(" %s", mm);
    int i = 0;
    bool flg = false, wild = false;
    for(i=0;i<n;i++){
        if(i>m-1){
            flg = false;
            break;
        }
        if(nn[i]=='*'){
            wild = true;
            break;
        }
        if(nn[i]!=mm[i]){
            flg = false;
            break;
        }
    }
    if(i==n && i==m && nn[i-1] == mm[i-1]) flg = true;
    if(wild){
        int a = n-1;
        int b = m-1;
        while(1){
            if(nn[a]=='*'){
                flg = true;
                break;
            }
            if(b<i){
                flg = false;
                break;
            }
            if(nn[a]!=mm[b]){
                flg = false;
                break;
            }
            a--;
            b--;
        }
    }
    if(flg) printf("YES");
    else printf("NO");
    return 0;
}
