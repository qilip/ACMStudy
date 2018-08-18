#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int card[22];
    for(int i=1;i<=20;i++){
        card[i] = i;
    }
    for(int i=0;i<10;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        while(a<b){
            swap(card[a], card[b]);
            a++;
            b--;
        }
    }
    for(int i=1;i<=20;i++){
        printf("%d ", card[i]);
    }
    return 0;
}
