#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>

using namespace std;

int main(void){
    int n;
    char nn[110];
    scanf("%d", &n);
    scanf("%s", nn);
    while(1){
        int flg = 0;
        for(int i=1;i<n;i++){
            if( nn[i-1]=='0' && nn[i]=='1' ){
                nn[i-1] = '1'; nn[i] = '0';
                flg = 1;
            }
        }
        if(!flg) break;
    }
    int set = 0;
    if(nn[0]=='0'){ printf("0"); return 0; }
    for(int i=0;i<n-1;i++){
        if(nn[i]=='1' && nn[i+1]=='0') break;
        set++;
    }
    for(int i=set;i<n;i++) printf("%c", nn[i]);
    return 0;
}
