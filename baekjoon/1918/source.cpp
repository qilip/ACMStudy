#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

int pri(char q){
    switch(q){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 0;
    }
    return -1;
}

int main(void){
    char s[110] = {0};
    vector<char> v;
    stack<char> st;
    scanf("%s", s);
    for(auto i : s){
        if(i==0) break;
        switch(i){
            case '+':
            case '-':
            case '*':
            case '/':
                while(!st.empty() && pri(st.top()) >= pri(i)){
                    v.push_back(st.top());
                    st.pop();
                }
                st.push(i);
                break;
            case '(':
                st.push(i);
                break;
            case ')':
                while(st.top()!='('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                break;
            default:
                v.push_back(i);
        }
    }
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    for(auto i : v){
        printf("%c", i);
    }
    return 0;
}
