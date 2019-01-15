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
const int MOD = 10'0000'0007;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    char s[210];
    scanf("%d", &n);
    scanf("%s", s);
    int len = strlen(s);
    
    int lcnt = 0, rcnt = 0;
    stack<int> st;
    for(int i=0;i<len;i++){
        if(s[i]==')'){
            if(!st.empty()){
                if(st.top()==2) st.pop();
                else st.push(1);
            }else{
                st.push(1);
            }
        }else{
            st.push(2);
        }
    }
    while(!st.empty()){
        if(st.top()==1){
            lcnt++;
        }else{
            rcnt++;
        }
        st.pop();
    }

    for(int l=0;l<=2*n-len;l++){
        int r = 2*n-len-l;
        int left = l-lcnt;
        int right = r-rcnt;
        if(left<0 || right<0) continue;
        // 홀짝 나눠서, left right 호응 가능한지 체크후
        // DP에 중복체크도 해야함
    }
    return 0;
}
