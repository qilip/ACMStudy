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

    char table[4];
    char card[5][4];
    scanf("%s", table);
    for(int i=0;i<5;i++){
        scanf("%s", card[i]);
    }
    int flg = 0;
    for(int i=0;i<5;i++){
        if(card[i][0] == table[0] || card[i][1] == table[1]) flg = 1;
    }
    if(flg) printf("YES");
    else printf("NO");

    return 0;
}
