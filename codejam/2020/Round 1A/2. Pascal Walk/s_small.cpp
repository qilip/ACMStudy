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

    //N<=1000

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n;
        scanf("%d", &n);
        printf("Case #%d:\n", t);
        n--;
        printf("1 1\n");
        if(n){
            n--;
            printf("2 1\n");
        }
        if(n==1){
            n--;
            printf("3 1\n");
        }
        int c = 3;
        while(n){
            if(n>=c-1){
                n -= c-1;
                printf("%d 2\n", c);
                c++;
            }else{
                n--;
                printf("%d 1\n", c-1);
                c++;
            }
        }
    }
    
    return 0;
}
