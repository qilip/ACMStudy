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
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    double nn[20][20], answer = 0;
    scanf("%d", &n);
    if(n==1){
        printf("1");
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &nn[i][j]);
        }
    }
    for(int i=1;i<n;i++){
        double tmp = 1.0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            tmp *= nn[i][j];
        }
        answer += tmp;
    }
    printf("%lf", 1.0-answer);    
    return 0;
}
