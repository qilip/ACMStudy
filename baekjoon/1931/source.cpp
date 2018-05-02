#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    vector< pair<int, int> > v;
    int N, cnt = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    int stime = 0;
    for(int i=0;i<v.size();i++){
        if(v[i].second >= stime){
            cnt++;
            stime = v[i].first;
        }
    }
    cout<<cnt;
}
