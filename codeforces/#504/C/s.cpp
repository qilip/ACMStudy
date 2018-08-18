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
#include <stack>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

char nn[200010];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", nn);
    vector<char> s;
    int cnt = n-k;
    for(int i=0;i<n;i++){
        char cur = nn[i];
        if(cur=='('){
            s.push_back('(');
        }else{
            if(cnt){
                s.pop_back();
                cnt-=2;
            }else{
                s.push_back(')');
            }
        }
    }
    for(auto i : s){
        printf("%c", i);
    }
    return 0;
}
