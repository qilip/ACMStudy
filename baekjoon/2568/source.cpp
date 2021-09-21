#include <stdio.h>
#include <algorithm>

using namespace std;

int n, b[500001], a[500001], lis[500002], lptr = 1;

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int ta, tb;
        scanf("%d %d", &ta, &tb);
        b[ta] = tb;
    }
    for(int i=1;i<500001;i++){
        if(!b[i]) continue;
        if(lis[lptr-1]<b[i]){
			a[i] = lptr;
            lis[lptr++] = b[i];
        }else{
            int pt = lower_bound(lis+1, lis+lptr, b[i]) - lis;
			a[i] = pt;
            lis[pt] = b[i];
        }
    }
    printf("%d\n", n-lptr+1);
    lptr--;
	int ai = 500000;
	while(lptr){
		if(a[ai]==lptr){
			a[ai] = 0;
			lptr--;
		}
		ai--;
	}
    for(int i=1;i<500001;i++){
        if(a[i]) printf("%d\n", i);
    }
    return 0;
}