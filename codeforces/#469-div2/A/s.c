#include <stdio.h>

int main(void){
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    while(a>0) {
        if(l>=r) {
            r++;
            a--;
        }else if(l<r) {
            l++;
            a--;
        }
    }
    while(l!=r) {
        if(l>r) {
            l--;
        }else if(l<r) {
            r--;
        }
    }
    printf("%d", l+r);
}
