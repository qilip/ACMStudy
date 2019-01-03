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
    vector<int> v;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char t;
        scanf(" %c", &t);
        v.push_back(t);
    }
    int del = 1;
    int dcnt = 0;
    while(del){
        del = 0;
        int xcnt = 0;
        for(int i=0;i<n-dcnt;i++){
            if(v[i]=='x'){
                xcnt++;
                if(xcnt>=3){
                    v.erase(v.begin() + i);
                    dcnt++;
                    del = 1;
                    break;
                }
            }else{
                xcnt = 0;
            }
        }
    }
    printf("%d", dcnt);
    return 0;
}
