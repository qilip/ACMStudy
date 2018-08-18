// #include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, ans = 0, cnt = 0;
    int nn[30] = {0};
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        char s;
        scanf(" %c", &s);
        nn[s-'a'+1]++;
    }
    for(int i=1;i<=26;i++){
        if(nn[i]){
            ans += i;
            i++;
            cnt++;
        }
        if(cnt==k) break;
    }
    if(cnt==k) printf("%d", ans);
    else printf("-1");
    return 0;
}
