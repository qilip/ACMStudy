#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int nn[10], arr[10], arc[10], acnt;
vector<int> v;

void bt(int dep){
    if(dep==m){
        for(auto i : v){
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<acnt;i++){
        if(arc[i]){
            arc[i]--;
            v.push_back(arr[i]);
            bt(dep+1);
            arc[i]++;
            v.pop_back();
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    sort(nn, nn+n);
    arr[acnt] = nn[0];
    arc[acnt]++;
    for(int i=1;i<n;i++){
        if(nn[i-1] == nn[i]){
            arc[acnt]++;
        }else{
            arr[++acnt] = nn[i];
            arc[acnt]++;
        }
    }
    acnt++;
    bt(0);
    return 0;
}
