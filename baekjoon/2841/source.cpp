#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    int n, p, cnt = 0;
    stack<int> s[7];
    scanf("%d %d", &n, &p);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        L:;
        if(s[a].empty() || s[a].top() < b){
            s[a].push(b);
            cnt++;
        }else if(s[a].top() > b){
            s[a].pop();
            cnt++;
            goto L;
        }
    }
    printf("%d", cnt);
    return 0;
}
