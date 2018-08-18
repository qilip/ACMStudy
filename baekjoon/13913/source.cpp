#include <stdio.h>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;

int main(void){
    int n, k;
    int arr[100010];
    queue<int> q;
    stack<int> s;
    memset(arr, -1, sizeof arr);
    scanf("%d %d", &n, &k);
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==k) break;
        if(cur-1>=0 && arr[cur-1]==-1) { q.push(cur-1); arr[cur-1] = cur; }
        if(cur+1<=100000 && arr[cur+1]==-1) { q.push(cur+1); arr[cur+1] = cur; }
        if(cur*2<=100000 && arr[cur*2]==-1) { q.push(cur*2); arr[cur*2] = cur; }
    }
    int cnt = 0, now = k;
    while(now != n){
        s.push(now);
        now = arr[now];
        cnt++;
    }
    s.push(n);
    printf("%d\n", cnt);
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    return 0;
}
