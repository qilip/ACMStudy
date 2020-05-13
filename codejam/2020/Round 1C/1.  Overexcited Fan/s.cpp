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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int x, y;
        char m[1010] = {0};
        scanf("%d %d %s", &x, &y, m);
        printf("Case #%d: ", t);
        int cur = 0, flg = 0;
        while(m[cur]){
            switch(m[cur]){
                case 'N':
                y++;
                break;
                case 'S':
                y--;
                break;
                case 'E':
                x++;
                break;
                case 'W':
                x--;
                break;
            }
            cur++;
            if(cur >= abs(x)+abs(y)){
                printf("%d\n", cur);
                flg = 1;
                break;
            }
        }
        if(!flg) printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
