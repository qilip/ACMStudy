#include <cstdio>
#include <queue>

using namespace std;

int main(void){
    int n, k;
    int arr[100010] = {0};
    int cur;
    scanf("%d %d", &n, &k);
    if(n==k){
        printf("0");
        return 0;
    }
    queue<int> q;
    q.push(n);
    while(!arr[k]){
        cur = q.front();
        q.pop();
        if(cur+1<=100001 && !arr[cur+1]){
            arr[cur+1] = arr[cur]+1;
            q.push(cur+1);
        }
        if(cur-1>=0 && !arr[cur-1]){
            arr[cur-1] = arr[cur]+1;
            q.push(cur-1);
        }
        if(cur*2<=100000 && !arr[cur*2]){
            arr[cur*2] = arr[cur]+1;
            q.push(cur*2);
        }
    }
    printf("%d", arr[k]);
    return 0;
}
