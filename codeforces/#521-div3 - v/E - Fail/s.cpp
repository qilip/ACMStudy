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

int n;
int a[200010];
int arr[200010];
int cnt = 1;
int ptr = 0;
int chk[200010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for(int i=1;i<n;i++){
        if(a[i-1] != a[i]){
            arr[ptr++] = cnt;
            cnt = 0;
        }
        cnt++;
    }
    arr[ptr++] = cnt;
    sort(arr, arr+ptr);

    int maxx = 0;

    for(int i=1;i<=20'0000;i++){
        if(chk[i]) continue;
        int stt = 0;
        int sum = 0;
        int cur = i;
        while(1){
            chk[cur] = 1;
            stt = *lower_bound(arr, arr+ptr, cur);
            printf("%d ", stt);
            if(stt < cur) break;
            sum += i;
            cur *= 2;
        }
        if(maxx < sum) maxx = sum;
    }
    printf("%d", maxx);
    return 0;
}
