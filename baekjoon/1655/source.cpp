#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int main(void){
    priority_queue<int> mxhp;
    priority_queue<int, vector<int>, greater<int>> mnhp;
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d", &tmp);
        if(!mxhp.size()) mxhp.push(tmp);
        else if(tmp>mxhp.top()){
            mnhp.push(tmp);
        }else{
            mxhp.push(tmp);
        }
        if(mxhp.size() > mnhp.size()+1){
            mnhp.push(mxhp.top());
            mxhp.pop();
        }else if(mnhp.size() > mxhp.size()){
            mxhp.push(mnhp.top());
            mnhp.pop();
        }
        printf("%d\n", mxhp.top());
    }
    return 0;
}
