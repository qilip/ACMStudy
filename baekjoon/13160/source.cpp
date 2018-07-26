#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

int main(void){
    int n, cnt = 0, max_cnt = 0, max_i = 0;
    bool i_b[300010] = {false};
    vector<tuple<int, int, int>>v; //지점, 시작(0)OR끝(1), 번호
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, 0, i); //시작이 앞에 정렬되어야 시작,끝 지점 같을때 잘 나올듯
        v.emplace_back(b, 1, i);
    }
    sort(v.begin(), v.end());
    int iend = v.size();
    for(int i=0;i<iend;i++){
        int dot, sd, no;
        tie(dot, sd, no) = v[i];
        if(!sd) cnt++;
        else cnt--;
        if(cnt>max_cnt){
            max_cnt = cnt;
            max_i = i;
        }
    }
    printf("%d\n", max_cnt);
    for(int i=max_i;i>=0;i--){
        int dot, sd, no;
        tie(dot, sd, no) = v[i];
        if(sd) i_b[no] = true;
        else{
            if(!i_b[no]) printf("%d ", no);
        }
    }
    return 0;
}
