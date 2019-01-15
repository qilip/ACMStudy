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
    char s[60], t[60];
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    int cnt = 0;
    vector<int> mov;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]) continue;
        int flg = 1;
        for(int j=i;j<n;j++){
            if(t[i]==s[j]){
                for(int q=j;q>i;q--){
                    cnt++;
                    mov.push_back(q);
                    swap(s[q], s[q-1]);
                }
                flg = 0;
                break;
            }
        }
        if(flg){
            printf("-1");
            return 0;
        }
    }
    printf("%d\n", cnt);
    for(auto i : mov){
        printf("%d ", i);
    }
    return 0;
}
