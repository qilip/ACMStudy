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
    char s[510][510];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", s[i]);
    }
    int cnt = 0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(s[i-1][j-1]=='X' && s[i][j]=='X' && s[i-1][j+1]=='X' && s[i+1][j-1]=='X' && s[i+1][j+1]=='X'){
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
