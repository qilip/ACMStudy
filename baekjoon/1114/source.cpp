#include <stdio.h>
#include <algorithm>

using namespace std;

int l, k, c, ku[10010], fcut;

bool find(int cut){
    int count = 0, len = 0, lcut = 0;
    if(len>cut) return false;
    for(int i=k;i>=0;i--){
        len += ku[i+1] - ku[i];
        if(len>cut){
            len = ku[i+1] - ku[i];
            if(len > cut) return false;
            count++;
            lcut = ku[i+1];
        }
    }
    if(count > c){
        return false;
    }else{
        if(count < c) lcut = ku[1];
        fcut = lcut;
        return true;
    }
}

int main(void){
    scanf("%d %d %d", &l, &k, &c);
    for(int i=1;i<=k;i++){
        scanf("%d", &ku[i]);
    }
    ku[k+1] = l;
    sort(ku+1, ku+1+k);
    int left = 0, right = l, mid, ans = l;
    while(left<=right){
        mid = (left+right)/2;
        if(find(mid)){
            right = mid-1;
            ans = mid;
        }else{
            left = mid+1;
        }
    }
    printf("%d %d", ans, fcut);
    return 0;
}
