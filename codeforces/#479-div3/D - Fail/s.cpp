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
#include <map>
#include <set>

using namespace std;

int n;
multiset <long long> m;
string answer;

void help(long long bef, int cur, multiset <long long> ms, string ans){
    if(cur==n){
        answer = ans;
    }
    for(int k=0;k<n;k++){
        if(bef/3==*ms.find(bef/3)){
            multiset <long long> mt (ms);
            mt.erase(*ms.find(bef/3));
            string newans = ans;
            newans += " ";
            newans += bef/3;
            help(bef/3, cur+1, mt, newans);
        }
        if(bef*2==*ms.find(bef*2)){
            multiset <long long> mt (ms);
            mt.erase(*ms.find(bef/3));
            string newans = ans;
            newans += " ";
            newans += bef/3;
            help(bef*2, cur+1, mt, newans);
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        long long tmp;
        scanf("%lld", &tmp);
        m.insert(tmp);
    }
    multiset <long long>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++){
        multiset <long long> me (m);
        me.erase(iter);
        string a;
        help(*iter, 1, me, a);
    }
    cout << answer;
    return 0;
}
