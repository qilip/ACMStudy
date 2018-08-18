#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int cnt[1010], idx[1010], sfx[1010], g[1010], ng[1010];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int n = (int)s.length();
    for(int i=0;i<n;i++) g[i] = s[i] - 'a' + 1;
    for(int l=1; l<n;l*=2){
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<n;i++) cnt[g[min(i+l, n)]]++;
        for(int i=1;i<=max(n, 'z'-'a'+1);i++) cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--) idx[--cnt[g[min(i+l, n)]]] = i;

        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<n;i++) cnt[g[i]]++;
        for(int i=1;i<=max(n, 'z'-'a'+1);i++) cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--) sfx[--cnt[g[idx[i]]]] = idx[i];

        static auto cmp = [&](int i, int j){
            if(g[i] == g[j]) return g[min(i+l, n)] < g[min(j+l, n)];
            return g[i] < g[j];
        };

        ng[sfx[0]] = 1;
        for(int i=1;i<n;i++){
            if(cmp(sfx[i-1], sfx[i])) ng[sfx[i]] = ng[sfx[i-1]] + 1;
            else ng[sfx[i]] = ng[sfx[i-1]];
        }
        memcpy(g, ng, sizeof g);
    }

    for(int i=0;i<n;i++){
        cout<<s.substr(sfx[i], n-sfx[i])<<'\n';
    }

    return 0;
}
