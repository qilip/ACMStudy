#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

queue<int> bq;
queue<int> rq;
vector<int> bb;
vector<int> rr;

int main(void){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    for(int i=0;i<n;i++){
        int t, m;
        char c;
        scanf("%d %c %d", &t, &c, &m);
        for(int i=0;i<m;i++){
            if(c=='B'){
                bq.push(t);
            }else{
                rq.push(t);
            }
        }
    }
    int cnt = 1;
    int btime = 0; // current job end time
    int bcnt = 0; // job cnt
    int rtime = 0; // current job
    int rcnt = 0; //job cnt
    for(int i=1;i<=90000;i++, btime--, rtime--){
           
        if(!btime){
            bb.push_back(bcnt);
        }

        S:;
        if(!bq.empty() && bq.front()<=i && btime <= 0){
            btime = a;
            bcnt = cnt;
            bq.pop();
            cnt++;
            if(a==0){
                bb.push_back(bcnt);
                goto S;
            }
        }
        if(!rtime){
            rr.push_back(rcnt);
        }

        D:;
        if(!rq.empty() && rq.front()<=i && rtime <= 0){
            rtime = b;
            rcnt = cnt;
            rq.pop();
            cnt++;
            if(b==0){
                rr.push_back(rcnt);
                goto D;
            }
        }

        //
        // while(!bq.empty() && bq.front()<=i && btime <= i){
        //     bb.push_back(cnt);
        //     btime = bq.front() + a;
        //     if(btime < i ) btime = i;
        //     bcnt = cnt;
        //     bq.pop();
        //     cnt++;
        // }
        // while(!rq.empty() && rq.front()<=i && rtime <= i){
        //     rr.push_back(cnt);
        //     rtime = rq.front() + b;
        //     if(rtime < i) rtime = i;
        //     rcnt = cnt;
        //     rq.pop();
        //     cnt++;
        // }
    }
    bb.erase(bb.begin());
    rr.erase(rr.begin());
    printf("%d\n", bb.size());
    for(auto c : bb){
        printf("%d ", c);
    }
    printf("\n%d\n", rr.size());
    for(auto c : rr){
        printf("%d ", c);
    }
    return 0;
}
