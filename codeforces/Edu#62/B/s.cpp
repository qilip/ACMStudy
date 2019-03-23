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

    int t;
    scanf("%d" , &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char s[110];
        scanf(" %s", s);
        int ans = 0;
        if(s[0]=='>') ans = 0;
        else if(s[n-1]=='<') ans = 0;
        else{
            int a = 110, b = 110;
            for(int i=0;i<n;i++){
                if(s[i]=='>'){
                    a = i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(s[i]=='<'){
                    b = n-1-i;
                    break;
                }
            }
            ans = a > b ? b : a;
        }
        printf("%d\n", ans);
    }
    return 0;
}
