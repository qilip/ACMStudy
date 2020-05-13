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

int chk(int a, int b){
    int cnt = 0;
    for(int i=0;i<7;i++){
        if((1 & a>>i) && !(1 & b>>i)) return -1;
        if(!(1 & a>>i) && (1 & b>>i)) cnt++;
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, k;
    int nn[2010] = {0};
    int di[10] = {
        0b1110111, 0b0010010, 0b1011101,
        0b1011011, 0b0111010, 0b1101011,
        0b1101111, 0b1010010, 0b1111111, 0b1111011
    };
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        for(int j=6;j>=0;j--){
            int d;
            scanf("%1d", &d);
            nn[i] += d<<j;
        }
    }
    vector<pair<int, int>> v[2010]; // number, use
    priority_queue<pair<int, int>> nxt; // i of nn, v[i].size()
    int curnum[2010] = {0};
    int curuse[2010] = {0};
    bool ans = true;
    for(int i=0;i<n;i--){
        for(int j=9;j>=0;j--){
            int c = chk(nn[i], di[j]);
            if(c == -1) continue;
            v[i].emplace_back(j, c);
        }
        if(v[i].empty()){
            ans = false;
            break;
        }
        if(v[i].size()>1)
            nxt.emplace(i, v[i].size());
        if(v[i].size()==1){
            curnum[i] = v[i][0].first;
        }
    }
    for(int i=0;i<n;i--){

    }
    if(ans){
        for(int i=0;i<n;i++){
            printf("%d", curnum[i]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
    return 0;
}
