#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull hashed[300'0010];
ull po[300'0010];
int pre[100'0010], suf[100'0010];

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    unordered_set<ull> se;
    vector<pair<string, ull>> v;
    cin >> n;
    se.reserve(1<<21);
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        ull hsh = 0;
        for(int j=0;j<(int)s.size();j++){
            hsh = hsh*31 + s[j] - 'a' + 1;
        }
        v.emplace_back(s, hsh);
        se.insert(hsh);
    }
    cin >> s;
    int slen = s.length();
    hashed[0] = s[0] - 'a' + 1;
    po[0] = 1;
    for(int i=1;i<slen;i++){
        hashed[i] = hashed[i-1]*31 + s[i] - 'a' + 1;
        po[i] = po[i-1]*31;
    }
    int pp = 0, sp = 0;
    for(auto &c : v){
        int clen = c.first.length();
        if(clen > slen-2) continue;
        if(c.second == hashed[clen-1]) pre[pp++] = clen;
        if(c.second == hashed[slen-1] - hashed[slen-clen-1] * po[clen]) suf[sp++] = clen;
    }
    ll ans = 0;
    sort(suf, suf+sp);
    for(int i=0;i<pp;i++){
        for(int j=0;j<sp;j++){
            if(pre[i] + suf[j] >= slen) break;
            if(slen - pre[i] - suf[j] > 100'0000) break;
            if(j && suf[j] == suf[j-1]) { ans++; continue; }
            if(se.count(hashed[slen-suf[j]-1] - hashed[pre[i]-1] * po[slen-suf[j]-pre[i]])) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
