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
    int s[110];
    int cnt[110] = {0};
    int unia = 0, unib = 0;
    bool ans[110] = {false}; //false는 A true는 B
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &s[i]);
        cnt[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(cnt[s[i]]==1){
            cnt[s[i]]=0;
            if(unia>unib){
                unib++;
                ans[i] = true;
            }else{
                unia++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(unia==unib) break;
        if(cnt[s[i]]>2){
            cnt[s[i]] = 0;
            if(unia>unib){
                unib++;
                ans[i] = true;
            }else{
                unia++;
            }
        }
    }
    if(unia==unib){
        printf("YES\n");
        for(int i=0;i<n;i++){
            printf("%c", ans[i]==true ? 'B' : 'A');
        }
    }else{
        printf("NO");
    }
    return 0;
}
