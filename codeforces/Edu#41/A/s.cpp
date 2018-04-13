#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    int n, m, mm[1010] = { 0 };
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d", &tmp);
        mm[tmp-1]++;
    }
    sort(mm, mm+n);
    printf("%d", mm[0]);
    return 0;
}
