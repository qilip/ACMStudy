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
    int a[110] = {0};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    printf("%d", *max_element(a, a+109));
    return 0;
}
