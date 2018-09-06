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

char nn[100010];
int cnt[30];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    scanf("%d", &n);
    scanf("%s", nn);
    for(int i=0;i<n;i++){
        cnt[nn[i]-'a']++;
    }
    int one = 0, two = 0;
    for(int i=0;i<30;i++){
        if(cnt[i]==1){
            one++;
        }else if(cnt[i]>=2){
            two++;
        }
    }
    if(two || n==1) printf("Yes");
    else printf("No");
    return 0;
}
