#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int k, n, in[10] = {0}, i2[10] = {0}, min_num[10], max_num[10], cnt = 0;
    scanf("%d", &k);
    n = k + 1;
    vector<int> v[10];
    priority_queue<int> pq;
    priority_queue<int> pq2;
    for(int i=1;i<=k;i++){
        char s;
        scanf(" %c", &s);
        if(s=='<'){
            v[i-1].push_back(i);
            in[i]++;
            i2[i]++;
        }else{
            v[i].push_back(i-1);
            in[i-1]++;
            i2[i-1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(!in[i]){
            pq.push(-i);
            pq2.push(i);
        }
    }
    while(!pq.empty()){
        int cur = -pq.top();
        int cu2 = pq2.top();
        pq.pop();
        pq2.pop();
        min_num[cur] = cnt;
        max_num[cu2] = cnt+9-k;
        cnt++;
        for(int i : v[cur]){
            in[i]--;
            if(!in[i]) pq.push(-i);
        }
        for(int i : v[cu2]){
            i2[i]--;
            if(!i2[i]) pq2.push(i);
        }
    }
    for(int i=0;i<n;i++){
        printf("%d", max_num[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d", min_num[i]);
    }
    return 0;
}
