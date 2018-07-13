#include <stdio.h>
#include <queue>

using namespace std;

int main(void){
    int n, cnt = 0;
    queue<int> q;
    scanf("%d", &n);
    int inp;
    scanf("%d", &inp);
    while(inp!=-1){
        if(inp==0){
            q.pop();
            cnt--;
        }else{
            if(cnt<n){
                q.push(inp);
                cnt++;
            }
        }
        scanf("%d", &inp);
    }
    if(q.empty()) printf("empty");
    while(!q.empty()){
        printf("%d ", q.front());
        q.pop();
    }
    return 0;
}
