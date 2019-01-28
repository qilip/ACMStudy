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

    int n;
    char s[200010];
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0;
    char c[3] = {'R', 'G', 'B'};
    if(n==2){
        if(s[0] == s[1]){
            cnt++;
            for(int j=0;j<3;j++){
                if(c[j] != s[1]){
                    s[1] = c[j];
                    break;
                }
            }
        }
    }
    for(int i=1;i<n-1;i++){
        if(s[i-1] == s[i] && s[i] == s[i+1]){
            cnt++;
            for(int j=0;j<3;j++){
                if(c[j] != s[i]){
                    s[i] = c[j];
                    break;
                }
            }
        }
    }
    for(int i=1;i<n-1;i++){
        if(s[i-1] != s[i] && s[i] != s[i+1]) continue;
        int cs[3] = {0};
        for(int j=0;j<3;j++){
            if(s[i-1] == c[j] || s[i+1] == c[j]){
                cs[j] = 1;
            }
        }
        for(int j=0;j<3;j++){
            if(cs[j]==0){
                cnt++;
                s[i] = c[j];
                break;
            }
        }
    }
    printf("%d\n%s", cnt, s);
    return 0;
}
