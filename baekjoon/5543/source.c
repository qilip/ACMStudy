#include <stdio.h>

int main(void){
    int a[5], max=2000, may=2000;
    for(int i=0;i<5;i++) scanf("%d", &a[i]);
    for(int i=0;i<3;i++) {
        if(a[i]<max) max = a[i];
    }
    for(int i=3;i<5;i++) {
        if(a[i]<may) may = a[i];
    }
    printf("%d", max+may-50);
}
