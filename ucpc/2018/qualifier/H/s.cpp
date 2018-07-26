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

    // 대조군 1
    // int ans = 0;
    // int a[100000] = {0};
    // for(int i=1;i<=n;i++){
    //     a[n/i + (n%i ? 1 : 0)]++;
    // }
    // for(int i=1;i<=n;i++){
    //     if(a[i])
    //         printf("%d: %d\n", i, a[i]);
    //     ans += i*a[i];
    // }
    // printf("\n%d\n", ans);
    
    // 확실한거
    // long long hehe = 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j+=i){
    //         hehe++;
    //     }
    // }
    // printf("\n%lld\n", hehe);

    // 나누는 수, 몫, 나머지
    // for(int i=1;i<=n;i++){
    //     printf("%d %d %d\n", i, n/i, n%i);
    // }

    //
    return 0;
}
