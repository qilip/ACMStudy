#include <cstdio>
#include <queue>
using namespace std;

int main(void){
    int N;
    queue<int> q;
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    for(int i=0;i<N;i++){
        printf("%d ", q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
}
