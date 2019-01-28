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

    char s[100010];
    scanf("%s", s);
    stack<char> st;
    int len = strlen(s);
    int cnt = 0;
    for(int i=0;i<len;i++){
        if(!st.empty()){
            if(st.top()==s[i]){
                st.pop();
                cnt++;
            }else{
                st.push(s[i]);
            }
        }else{
            st.push(s[i]);
        }
    }
    if(cnt%2){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
