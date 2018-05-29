#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long carr[100010] = {0}, cnt = 0, darr[100010] = {0};
    long long b, x, ans = 0;
    cin >> n >> b;
    string k;
    cin >> k;
    cin >> x;
    for(int i=1;i<=n;i++){
        string tmp;
        cin >> tmp;
        k == tmp ? carr[i] == ++cnt : carr[i] == cnt ;
        darr[i] = cnt + darr[i-1];
    }
    long long onecyc = ((b/n)*darr[n] + darr[b%n])*2-carr[n];
    ans += (x/onecyc)*(b*2-1);
    long long incyc = x%onecyc;
    if(((b/n)*darr[n] + darr[b%n])<incyc){
        ans += b;
        //감소하며;
    }else{
        //증가하며;
    }

    return 0;
}
