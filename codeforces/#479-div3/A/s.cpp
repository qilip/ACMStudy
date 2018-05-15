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
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;i++){
        if(n%10){
            n--;
        }else{
            n/=10;
        }
    }
    printf("%d", n);
    return 0;
}
