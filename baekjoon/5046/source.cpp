#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    int n, b, h, w;
    int mini = INT_MAX;
    cin >> n >> b >> h >> w;
    for(int i = 0; i < h; i++){
        int p;
        cin >> p;
        for(int j = 0; j < w; j++){
            int a;
            cin >> a;
            if(n <= a && b >= p * n){
                mini = min(mini, p * n);
            }
        }
    }
    if(mini == INT_MAX){
        cout << "stay home" << endl;
    }else{
        cout << mini << endl;
    }
    return 0;
}
