#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nn[110], nnc = 0;
    char t[110];
    scanf("%d", &n);
    scanf("%s", t);
    for(int i=n;i>1;i--){
        if(n%i==0) nn[nnc++] = i;
    }
    for(int i=nnc-1;i>=0;i--){
        for(int j=0;j<nn[i]/2;j++){
            swap(t[nn[i]-j-1], t[j]);
        }
    }
    printf("%s", t);
    return 0;
}
