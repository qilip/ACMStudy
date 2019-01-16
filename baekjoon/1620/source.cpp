#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string tmp;
    cin >> n >> m;
    map<string, string> is;
    map<string, string> si;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        is.emplace(to_string(i), tmp);
        si.emplace(tmp, to_string(i));
    }
    for(int i=0;i<m;i++){
        cin >> tmp;
        if( '0'<=tmp.c_str()[0] && tmp.c_str()[0]<='9' ){
            cout << is.find(tmp)->second <<'\n';
        }else{
            cout << si.find(tmp)->second <<'\n';
        }
    }
    return 0;
}
