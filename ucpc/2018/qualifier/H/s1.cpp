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
    
    int n;
    scanf("%d", &n);

    ll cnt = 0;
    int jmp = 1, mok = 0, pes = 0, zer = 0;
    for(int i=1;i<=n;i+=jmp){
        mok = n/i;
        pes = n%i;
        jmp = pes/mok + 1;
        zer = pes%mok ? 0 : 1;
        cnt += mok*jmp + jmp - zer;
    }
    printf("%lld", cnt);
    return 0;
}
