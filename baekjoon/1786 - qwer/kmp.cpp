#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string S, T;
int ff[1000010];

void calcff(string T){
    int N = T.length();
    for(int i=1,j=0;i<N;i++){
        while(j>0 && T[i] != T[j]) j = ff[j-1];
        if(T[i] == T[j]) ff[i] = ++j;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, S);
    getline(cin, T);

    calcff(T);
    vector<int> ans;

    for(unsigned i=0,j=0;i<S.length();i++){
        while(j>0 && S[i] != T[j]) j =ff[j-1];
        if(S[i] == T[j]) j++;
        if(j == T.length()){
            ans.push_back(i - T.length() + 2);
            j = ff[j-1];
        }
    }
    
    cout<<ans.size()<<'\n';
    for(auto i : ans) cout<<i<<' ';
    return 0;
}
