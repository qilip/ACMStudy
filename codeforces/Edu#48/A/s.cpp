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
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    int n, m;
    scanf("%d %d", &n, &m);
    int pages = m;
    for(int i=0;i<n;i++){
        int cnt = 0;
        int cur;
        scanf("%d", &cur);
        if(pages <= cur){
            cur -= pages;
            cnt++;
            cnt += cur/m;
            pages = m - (cur%m);
            printf("%d ", cnt);
        }else{
            pages -= cur;
            printf("0 ");
            continue;
        }
    }
    
    return 0;
}
