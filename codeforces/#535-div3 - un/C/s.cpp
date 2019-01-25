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
    char t[6][4] = {
        "RGB",
        "RBG",
        "GBR",
        "GRB",
        "BRG",
        "BGR"
    };
    scanf("%d", &n);
    scanf("%s", s);
    int mcnt = 9999'9999, mt = 0;
    for(int i=0;i<6;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(s[j]!=t[i][j%3]) cnt++;
        }
        if(cnt<mcnt){
            mcnt = cnt;
            mt = i;
        }
    }
    printf("%d\n", mcnt);
    for(int i=0;i<n;i++){
        printf("%c", t[mt][i%3]);
    }
    return 0;
}
