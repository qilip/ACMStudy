#include <stdio.h>

int c, b;
int bb[22];
int max;

void func(int depth, int sum){
    if(depth==b){
        max = max<sum && c>=sum ? sum : max;
    }else{
        func(depth+1, sum+bb[depth]);
        func(depth+1, sum);
    }
}

int main(void){
    scanf("%d %d", &c, &b);
    for(int i=0;i<b;i++){
        scanf("%d", &bb[i]);
    }
    func(0, 0);
    printf("%d", max);
    return 0;    
}
