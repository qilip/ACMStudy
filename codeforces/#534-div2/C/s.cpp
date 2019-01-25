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

    char s[1010];
    scanf("%s", s);
    int len = strlen(s);
    int v1 = 0;
    int h3 = 0;
    for(int i=0;i<len;i++){
        if(s[i]=='0'){
            if(v1){
                v1 = 0;
                printf("3 1\n");
            }else{
                v1 = 1;
                printf("1 1\n");
            }
        }else{
            if(h3){
                h3 = 0;
                printf("4 1\n");
            }else{
                h3 = 1;
                printf("4 3\n");
            }
        }
    }
    
    return 0;
}
