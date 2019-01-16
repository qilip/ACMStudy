#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    int n, nxt = 1;
    stack<int> st;
    st.push(0);
    vector<char> v;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int cur;
        scanf("%d", &cur);
        while(st.top()<cur){
            st.push(nxt++);
            v.push_back('+');
        }
        if(cur==st.top()){
            st.pop();
            v.push_back('-');
        }else{
            printf("NO");
            return 0;
        }
    }
    for(auto i : v){
        printf("%c\n", i);
    }
    return 0;
}
