#include <bits/stdc++.h>

using namespace std;

string mn[] = {"", "10", "1", "7", "4", "2", "6"};

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c = n;
        if(c==10) { cout << "22"; c -= 10; }
        else if(c>10 && c%7==4) { cout << "20"; c -= 11; }
        else if(c>16 && c%7==3) { cout << "200"; c -= 17; }
        else if(c%7) cout << mn[c%7];
        for(c-=c%7==1?8:c%7;c>0;c-=7) cout << "8";
        cout << " ";
        c = n;
        if(c%2) cout << "7";
        for(c-=c%2?3:0;c>0;c-=2) cout << "1";
        cout << '\n';
    }
    return 0;
}
