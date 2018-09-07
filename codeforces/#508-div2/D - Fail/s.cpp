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
    list<ll> li;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        li.push_back(tmp);
    }
    auto iter = min_element(li.begin(), li.end());
    int min = *iter;
    while(iter!=li.end()){
        if(*iter != min){ iter++; continue; }
        if(iter!=li.begin()){
            iter--;
            int bef = *iter;
            iter++;
            int cur = *iter;
            if(bef > cur){
                *iter = cur - bef;
                iter--;
                iter = li.erase(iter);
                goto STR;
            }
        }
        if(iter!=li.end()){
            iter++;
            int aft = *iter;
            iter--;
            int cur = *iter;
            if(aft > cur){
                iter++;
                *iter = cur - aft;
                iter--;
                iter = li.erase(iter);
                goto STR;
            }
        }
        iter++;
    }
    STR:;
    //printf("%lld, %d| ", *iter, li.size());
    while(li.size()>1){
        if(iter!=li.begin()){
            iter--;
            int bef = *iter;
            iter++;
            int cur = *iter;
            *iter = cur - bef;
            iter--;
            iter = li.erase(iter);
        }else if(iter!=li.end()){
            iter++;
            int aft = *iter;
            iter--;
            int cur = *iter;
            iter++;
            *iter = cur - aft;
            iter--;
            iter = li.erase(iter);
        }
        //printf("%lld, %d| ", *iter, li.size());
    }
    printf("%lld", -(*iter));
    return 0;
}

/*

5
0 -1 -1 -1 -1

같은 경우, 내 코드앞에 다 양수화 시켜주고 진행해야 하려나.

*/
