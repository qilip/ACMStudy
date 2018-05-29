#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, i;
    vector <string> inp;
    scanf("%d %d", &n, &i);
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        inp.push_back(tmp);
    }
    sort(inp.begin(), inp.end());
    cout << inp[i-1];
    return 0;
}
