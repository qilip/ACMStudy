#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n, a, b, cnt;
vector<pair<int, bool>> cow;
vector<int> cng;

int main(void){
    scanf("%d %d %d", &n, &a, &b);
    for(int i=0;i<n;i++){
        char s[2];
        int w;
        scanf("%s %d", s, &w);
        if(s[0]=='S'){
            cow.emplace_back(w, true);
        }else{
            cow.emplace_back(w, false);
        }
    }
    sort(cow.begin(), cow.end());
    int ptr = 0;
    cng.push_back(0);
    bool flg = true;
    while(ptr < n && !cow[ptr].second) ptr++;
    if(!ptr) cng.push_back(1);
    else if(ptr == n) {
        printf("0");
        return 0;
    }
    else{
        cng.push_back((cow[ptr].first + cow[ptr-1].first + 1)/2);
    }
    for(int i=ptr;i<n;i++){
        if(cow[i].second!=flg){
            cng.push_back((cow[i].first + cow[i-1].first + cow[i].second)/2);
            flg = !flg;
        }
    }
    cng.push_back(1000000001);
    *(upper_bound(cng.begin(), cng.end(), a) - 1) = a;
    cng.insert(lower_bound(cng.begin(), cng.end(), b) , b);
    flg = true;
    for(int i=0;i<(int)cng.size()-1;i++){
        flg = !flg;
        if(flg && a<=cng[i] && cng[i+1]<=b){
            cnt += cng[i+1] - cng[i] + 1;
        }
    }
    printf("%d", cnt);
    return 0;
}
