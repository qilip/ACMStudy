#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n, cnt = 0;
    char s[101][7];
    char q[] = {"ACFJMNRT"};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", s[i]);
    }
    do{
        // 전! 탐! 색!
    }while(next_permutation(q, q+8));
    printf("%d", cnt);
    return 0;
}
