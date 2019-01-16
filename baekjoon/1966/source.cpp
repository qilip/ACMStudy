#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d", &tmp);
            pq.push(tmp);
            if(i==m) q.emplace(tmp, 1);
            else q.emplace(tmp, 0);
        }
        int cnt = 0;
        while(!q.empty()){
            if(q.front().first == pq.top()){
                pq.pop();
                cnt++;
                if(q.front().second){
                    printf("%d\n", cnt);
                    break;
                }else{
                    q.pop();
                }
            }else{
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}
