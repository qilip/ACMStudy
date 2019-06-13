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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    cin >> n;
    vector<string> v;
    // tuple<int, char, int> aeiou[100010]; // cnt, last, idx;

    vector<pair<int, int>> ae[6]; // cnt, idx
    vector<tuple<int, int, int>> aeiou; // cnt, last, idx;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
        int ccnt = 0;
        char clast = '0';
        for(auto cur : s){
            if(cur=='a'||cur=='e'||cur=='i'||cur=='o'||cur=='u'){
                ccnt++;
                clast = cur;
            }
        }
        int id = 5;
        switch(clast){
            case 'a': id = 0; break;
            case 'e': id = 1; break;
            case 'i': id = 2; break;
            case 'o': id = 3; break;
            case 'u': id = 4; break;
            default: id = 5; break;
        }
        ae[id].emplace_back(ccnt, i);
    }

    // cout << ae[5].size() << "\n";
    // for(auto tmp : ae[5]){
    //     cout << tmp.second << "\n";
    // }

    for(int i=0;i<5;i++){
        sort(ae[i].begin(), ae[i].end());
    }
    stack<int> first; // 두개가 한쌍
    stack<int> second; // 두개가 한쌍

    for(int i=0;i<5;i++){
        for(int j=0;j<(int)ae[i].size();j++){
            if(ae[i][j].first == ae[i][j+1].first){
                second.push(ae[i][j].second);
                second.push(ae[i][j+1].second);
                j++;
            }else{
                aeiou.emplace_back(ae[i][j].first, i, ae[i][j].second);
            }
        }
    }
    sort(aeiou.begin(), aeiou.end());
    for(int i=0;i<(int)aeiou.size();i++){
        if(get<0>(aeiou[i]) == get<0>(aeiou[i+1])){
            first.push(get<2>(aeiou[i]));
            first.push(get<2>(aeiou[i+1]));
            i++;
        }
    }
    vector<pair<int, int>> vv;
    while(!first.empty() && !second.empty()){
        vv.emplace_back(first.top(), second.top());
        first.pop();
        second.pop();
        vv.emplace_back(first.top(), second.top());
        first.pop();
        second.pop();
    }
    while(second.size()>=4){
        int a, b;
        int c, d;
        a = second.top();
        second.pop();
        c = second.top();
        second.pop();
        b = second.top();
        second.pop();
        d = second.top();
        second.pop();
        vv.emplace_back(a, b);
        vv.emplace_back(c, d);
    }
    cout << (int)vv.size()/2 << "\n";
    for(int i=0;i<(int)vv.size();i++){
        cout << v[vv[i].first] << " " << v[vv[i].second] << "\n";
    }
    return 0;
}
