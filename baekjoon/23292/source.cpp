#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    string birth;
    cin >> birth;
    int n;
    cin >> n;
    pair<int, string> nn[1010];
    for(int k=0;k<n;k++){
        cin >> nn[k].second;
        int a = 0, b = 0, c = 0;
        for(int i=0;i<4;i++) a += (birth[i] - nn[k].second[i]) * (birth[i] - nn[k].second[i]);
        for(int i=4;i<6;i++) b += (birth[i] - nn[k].second[i]) * (birth[i] - nn[k].second[i]);
        for(int i=6;i<8;i++) c += (birth[i] - nn[k].second[i]) * (birth[i] - nn[k].second[i]);
        nn[k].first -= a * b * c;
    }
    sort(nn, nn + n);
    cout << nn[0].second << endl;
    return 0;
}
