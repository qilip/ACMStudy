#include <stdio.h>
#include <queue>

using namespace std;

int dot[100005];

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    if(n==k) { printf("0"); return 0; }
    queue<int> next;
    while(!dot[k]){
        if(n<=100000 && !dot[n+1]) { next.emplace(n+1); dot[n+1] = dot[n]+1; }
        if(n-1>=0 && !dot[n-1]) { next.emplace(n-1); dot[n-1] = dot[n]+1; }
        if(n<=50000 && !dot[n*2]) { next.emplace(n*2); dot[n*2] = dot[n]+1; }
        n = next.front();
        next.pop();
    }
    printf("%d", dot[k]);
    return 0;
}
