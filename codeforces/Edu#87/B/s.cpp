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
#include <bitset>

using namespace std;

typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        char s[200010] = {0};
        scanf(" %s", s);
        int cnt[4] = {0};
        int minans = 99'9999;
        int l = 0;
        for(int i=0;s[i]!=0;i++){
            cnt[s[i]-'0']++;
            while(cnt[s[l]-'0']>1){
                cnt[s[l]-'0']--;
                l++;
            }
            if(cnt[1] && cnt[2] && cnt[3]){
                if(minans > i-l+1) minans = i-l+1;
            }
        }
        if(minans == 999999) printf("0\n");
        else printf("%d\n", minans);
    }
    
    return 0;
}
