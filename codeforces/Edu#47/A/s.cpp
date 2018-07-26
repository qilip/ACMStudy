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
    
    int n, m, nn[1010], mm[1010];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d", &mm[i]);
    }
    int pn = 0, pm = 0, cnt = 0;
    while(pn<n && pm<m){
        if(nn[pn] <= mm[pm]){
            cnt++;
            pn++;
            pm++;
        }else{
            pn++;
        }
    }
    printf("%d", cnt);
    return 0;
}
