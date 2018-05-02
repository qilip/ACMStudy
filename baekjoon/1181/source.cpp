#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    int N;
    vector< pair<int , string> > v;
    cin >> N;
    for(int i=0;i<N;i++){
        int a; string b;
        cin >> b;
        a = b.length();
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i].second <<"\n";
    }
    return 0;
}
