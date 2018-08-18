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
    
    int n, m;
    int fod[110] = {0};
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d", &tmp);
        fod[tmp]++;
    }
    sort(fod, fod+110, greater<int>());
    int t = fod[n-1];
    int b[110];
    int bt[110];
    for(int i=n-1;i>=0;i--){
        fod[i] -= t;
        b[i] = t;
        bt[i] = i;
    }

    bool flg = true;
    while(flg){
        flg = false;
        // printf("%d %d %d :: %d %d %d :: %d %d %d\n", fod[0], fod[1], fod[2], bt[0], bt[1], bt[2], b[0], b[1], b[2]);
        int min_b = min_element(b, b+n) - b;
        if(fod[bt[min_b]]){
            // printf("-1-\n");
            flg = true;
            b[min_b]++;
            fod[bt[min_b]]--;
            continue;
        }
        int max_f = max_element(fod, fod+n) - fod;
        if(fod[max_f] > b[min_b]){
            // printf("-2-\n");
            flg = true;
            b[min_b]++;
            bt[min_b] = max_f;
            fod[max_f] -= b[min_b];
            continue;
        }
    }
    printf("%d", *min_element(b, b+n));
    return 0;
}
