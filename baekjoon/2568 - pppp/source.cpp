#include <stdio.h>
#include <algorithm>

using namespace std;

int n, b[500001], a[500001], lis[500002], lptr = 1;

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int ta, tb;
        scanf("%d %d", &ta, &tb);
        b[tb] = ta;
        a[ta] = 1;
    }
    for(int i=1;i<500001;i++){
        if(!b[i]) continue;
        if(lis[lptr-1]<b[i]){
            lis[lptr++] = b[i];
        }else{
            int pt = lower_bound(lis+1, lis+lptr, b[i]) - (lis+1);
            lis[pt] = b[i];
        }
    }
    // TEST
    for(int i=1;i<lptr;i++){
        printf("%d ", lis[i]);
    }
    printf("\n");
    // TEST
    printf("%d\n", n-lptr+1);
    for(int i=1;i<lptr;i++){
        a[lis[i]] = 0;
    }
    for(int i=1;i<500001;i++){
        if(a[i]) printf("%d\n", i);
    }
    return 0;
}
