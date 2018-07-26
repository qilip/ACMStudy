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

    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    int rop = x - 1;
    if(b>a && rop){
        printf("1");
        b--;
        rop--;
    }
    bool last_zero = false;
    while(rop--){
        printf("0");
        a--;
        if(rop--){
            printf("1");
            b--;
        }else{
            last_zero = true;
            break;
        }
    }
    if(!last_zero) while(a--) printf("0");
    while(b--) printf("1");
    if(last_zero) while(a--) printf("0");
    return 0;
}
