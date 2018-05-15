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
#include <map>

using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    int nn[200005];
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    sort(nn, nn+n);
    if(n==k){
        printf("%d", nn[k-1]);
    }
    else if(k==0){
        if(nn[0]!=1){
            printf("1");
        }else{
            printf("-1");
        }
    }else if(nn[k-1]==nn[k]){
        printf("-1");
    }else{
        printf("%d", nn[k-1]);
    }
    return 0;
}
