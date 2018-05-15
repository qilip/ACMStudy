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
    
    int n;
    scanf("%d", &n);
    char nn[110];
    scanf("%s", nn);
    int ans[26][26] = {0};
    for(int i=0;i<n-1;i++){
        ans[nn[i]-'A'][nn[i+1]-'A']++;
    }
    int max = 0, maxi = 0, maxj = 0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(max<ans[i][j]){
                max = ans[i][j];
                maxi = i;
                maxj = j;
            }
        }
    }
    printf("%c%c", maxi+'A', maxj+'A');
    return 0;
}
