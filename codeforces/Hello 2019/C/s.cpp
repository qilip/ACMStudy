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
    scanf("%d", &n);
    int nn[100010] = {0};
    for(int i=0;i<n;i++){
        char str[500010];
        scanf("%s", str);
        int len = strlen(str);
        stack<int> st;
        for(int i=0;i<len;i++){
            int cur = str[i];
            if(cur=='('){
                st.push(1);
            }else{
                if(st.empty()){
                    st.push(2);
                }else{
                    if(st.top()==1){
                        st.pop();
                    }else{
                        st.push(2);
                    }
                }
            }
        }
        int l = 0, r = 0;
        while(!st.empty()){
            if(st.top()==1){
                r++;
            }else{
                l++;
            }
            st.pop();
        }
        if(l && r) nn[i] = 12345678; // 사용 불가능
        else if(!l && !r) nn[i] = 0;
        else nn[i] = l ? -l : r ;
    }
    sort(nn, nn+n);
    int chk[100010] = {0};
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(nn[i]==12345678 || chk[i] == 1) continue;
        chk[i] = 1;
        int lb = lower_bound(nn, nn+n, -nn[i]) - nn;
        int ub = upper_bound(nn, nn+n, -nn[i]) - nn;
        for(int j=lb;j<ub;j++){
            if(nn[j]+nn[i]) break;
            if(chk[j]) continue;
            chk[j] = 1;
            cnt++;
            break;
        }
    }
    printf("%d", cnt);
    return 0;
}
