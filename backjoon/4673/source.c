#include <stdio.h>

int arr[10000];

int main(void){
    for(int i=1;i<9994;i++){
        arr[i + i%10 + i/10%10 + i/100%10 + i/1000%10] = 1;
        if(!arr[i]) printf("%d\n", i);
    }
    return 0;
}