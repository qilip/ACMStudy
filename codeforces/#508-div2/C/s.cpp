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

using namespace std;

typedef long long ll;

int n;
int a[1'000'010];
int b[1'000'010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    sort(a, a+n, greater<int>());
    sort(b, b+n, greater<int>());
    ll score_a = 0, score_b = 0;
    int ptr_a = 0, ptr_b = 0;
    for(int i=0;i<n;i++){
        //a
        if(ptr_a>=n){
            ptr_b++;
        }else if(ptr_b>=n){
            score_a += a[ptr_a++];
        }else if(a[ptr_a] > b[ptr_b]){
            score_a += a[ptr_a++];
        }else{
            ptr_b++;
        }
        //b
        if(ptr_b>=n){
            ptr_a++;
        }else if(ptr_a>=n){
            score_b += b[ptr_b++];
        }else if(a[ptr_a] < b[ptr_b]){
            score_b += b[ptr_b++];
        }else{
            ptr_a++;
        }
    }
    printf("%lld", score_a - score_b);
    return 0;
}
