#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main(void){
    char s[60];
    bool chk[30];
    stack<char> st;
    scanf("%s", s);
    int n = strlen(s);
    for(int i=0;i<n;i++){
        if(!st.empty() && st.top()==s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    int cnt = 0;
    int nu = 0;
    while(!st.empty()){
        printf("%c ", st.top());
        int cur = st.top() - 'A';
        st.pop();
        if(!chk[cur]){
            nu++;
            chk[cur] = true;
        }else{
            nu--;
            chk[cur] = false;
        }
        
    }
    printf("%d", cnt);
    return 0;
}
