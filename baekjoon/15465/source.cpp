#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

int main(void){
    int n;
    tuple<int, int, int> cow[110];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a, b, c;
        string s;
        cin >> a >> s >> c;
        if(s=="Bessie") b = 1;
        if(s=="Elsie") b = 2;
        if(s=="Mildred") b = 3;
        cow[i] = {a, b, c};
    }
    sort(cow, cow+n);
    int cur[4] = {0, 7, 7, 7};
    int bol[4] = {0, 1, 1, 1};
    int cnt = 0;
    for(int i=0;i<n;i++){
        int a, b, c;
        tie(a, b, c) = cow[i];
        cur[b] += c;
        int max = *max_element(cur, cur+4);
        int cng = 0;
        for(int j=1;j<=3;j++){
            if(max==cur[j]){
                if(!bol[j]) cng = 1;
                bol[j] = 1;
            }
            if(max!=cur[j]){
                if(bol[j]) cng = 1;
                bol[j] = 0;
            }
        }
        if(cng) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
