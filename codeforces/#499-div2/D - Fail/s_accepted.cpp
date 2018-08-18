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

    int m, n;
    int p[40];
    scanf("%d %d", &m, &n);
    for(int i=0;i<n;i++){
        printf("1\n");
        fflush(stdout);
        int tmp;
        scanf("%d", &tmp);
        if(tmp==1){
            p[i] = 1;
        }else if(tmp==-1){
            p[i] = 0;
        }else{
            return 0;
        }
    }
    int left = 1, right = m, mid;
    int rcnt = 0;
    while(1){
        mid = (left+right)/2;
        printf("%d\n", mid);
        fflush(stdout);
        int tmp;
        scanf("%d", &tmp);
        if(p[rcnt++]==0) tmp *= -1;
        if(tmp==-1){
            right = mid-1;
        }else if(tmp==1){
            left = mid+1;
        }else{
            return 0;
        }
        rcnt %= n;
    }
    return 0;
}
