#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    char s[100010] = {0};
    stack<char> st;
    int ans = 0;
    scanf(" %s", s);
    for(int i=0;s[i]!=0;i++){
        if(s[i] == '(' && s[i+1] == ')'){
            ans += st.size();
            i++;
        }else if(s[i] == '('){
            st.push(1);
        }else if(s[i] == ')'){
            st.pop();
            ans++;
        }
    }
    ans += st.size();
    printf("%d", ans);
    return 0;
}
