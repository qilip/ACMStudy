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

char s[100010];
int len;

void swp(int a){
    int pt = a-1;
    while(pt>=0){
        if(s[a]+1==s[pt]) pt--;
        else break;
    }
    pt++;
    swap(s[a], s[pt]);
    return;
}

void fns(int a){
    int fz = a+1;
    while(fz<len){
        if(s[fz]=='2') return;
        if(s[fz]=='1'){
            s[a] = '1';
            s[a+1] = '2';
            s[fz] = '0';
            return;
        }
        fz++;
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%s", s);
    len = strlen(s);
    for(int i=0;i<len-1;i++){
        if(s[i]==s[i+1]+1) swp(i+1);
        if(s[i]=='2' && s[i+1]=='0') fns(i);
    }
    printf("%s", s);
    return 0;
}
