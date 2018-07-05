#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    int N, cnt = 0;
    scanf("%d", &N);
    while(N--){
        char s[100010] = {0};
        scanf("%s", s);
        stack<char> st;
        for(auto i : s){
            if(i==0) break;
            if(!st.empty()){
                if(st.top()==i) st.pop();
                else st.push(i);
            }else{
                st.push(i);
            }
        }
        if(st.empty()) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
