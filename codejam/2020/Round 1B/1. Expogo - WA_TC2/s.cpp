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

bool chk(int a, int b, int c, int d, int m){
    bool h = false;
    for(int i=0;i<=m;i++){
        int cnt = 0;
        if(1 & (a>>i)) cnt++;
        if(1 & (b>>i)) cnt++;
        if(1 & (c>>i)) cnt++;
        if(1 & (d>>i)) cnt++;
        if(!h && cnt == 0) h = true;
        else if(h || cnt != 1) return false;
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int x, y;
        scanf("%d %d", &x, &y);
        bool xm = false, ym = false, yx = false;
        if(x<0){
            xm = true;
            x = -x;
        }
        if(y<0){
            ym = true;
            y = -y;
        }
        if(x<y){
            yx = true;
            swap(x, y);
        }
        int lx = 0, rx = 0, ly = 0, ry = 0;
        int lxc, rxc, lyc, ryc;
        for(int i=1; i<=x; i<<=1) lx = i;
        rx = lx * 2;
        lxc = x - lx;
        rxc = rx - x;
        for(int i=1; i<=y; i<<=1) ly = i;
        ry = ly * 2;
        lyc = y - ly;
        ryc = ry - y;
        printf("Case #%d: ", t);
        // printf("[%d,%d|%d,%d|%d,%d|%d,%d]", lx, lxc, ly, lyc, rx, rxc, ry, ryc);
        vector<int> ans;
        if(!x){
            if(chk(0, 0, ly, lyc, 32-__builtin_clz(x | y))){
                for(int i=0;i<32;i++)
                    if((1 & (ly >> i)) || (1 & (lyc >> i))) ans.push_back(3); 
            }else if(chk(0, 0, ry, ryc, 32-__builtin_clz(x | y))){
                for(int i=0;i<32;i++){
                    if(1 & (ry >> i)) ans.push_back(3);
                    if(1 & (ryc >> i)) ans.push_back(4);
                }
            }else{
                printf("IMPOSSIBLE\n");
                continue;
            }
        }else if(!y){
            if(chk(lx, lxc, 0, 0, 32-__builtin_clz(x | y))){
                for(int i=0;i<32;i++)
                    if((1 & (lx >> i)) || (1 & (lxc >> i))) ans.push_back(1); 
            }else if(chk(rx, rxc, 0, 0, 32-__builtin_clz(x | y))){
                for(int i=0;i<32;i++){
                    if(1 & (rx >> i)) ans.push_back(1);
                    if(1 & (rxc >> i)) ans.push_back(2);
                }
            }else{
                printf("IMPOSSIBLE\n");
                continue;
            }
        }else{
            int q = 0, w = 0, e = 0, r = 0;
            if(chk(lx, lxc, ly, lyc, 32-__builtin_clz(x | y))) q = lx, q += lxc, e = ly, e += lyc;
            else if(chk(lx, lxc, ry, ryc, 32-__builtin_clz(x | y))) q = lx, q += lxc, e = ry, r = ryc;
            else if(chk(rx, rxc, ly, lyc, 32-__builtin_clz(x | y))) q = rx, w = rxc, e = ly, e += lyc;
            else if(chk(rx, rxc, ry, ryc, 32-__builtin_clz(x | y))) q = rx, w = rxc, e = ry, r = ryc;
            else{
                printf("IMPOSSIBLE\n");
                continue;
            }
            for(int i=0;i<32;i++){
                if(1 & (q>>i)) ans.push_back(1);
                if(1 & (w>>i)) ans.push_back(2);
                if(1 & (e>>i)) ans.push_back(3);
                if(1 & (r>>i)) ans.push_back(4);
            }
        }
        // +기준 X(E-1, W-2), Y(N-3, S-4)
        if(yx){
            for(auto i = ans.begin(); i!=ans.end(); i++){
                if((*i) == 1) (*i) = 3;
                else if((*i) == 2) (*i) = 4;
                else if((*i) == 3) (*i) = 1;
                else if((*i) == 4) (*i) = 2;
            }
        }
        for(auto i : ans){
            if(i == 1) printf("%c", xm ? 'W' : 'E');
            if(i == 2) printf("%c", xm ? 'E' : 'W');
            if(i == 3) printf("%c", ym ? 'S' : 'N');
            if(i == 4) printf("%c", ym ? 'N' : 'S');
        }
        printf("\n");
    }
    
    return 0;
}
