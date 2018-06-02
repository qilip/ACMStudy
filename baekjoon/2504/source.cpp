#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main(void){
    char inp[40] = {0};
    stack<int> st;
    scanf("%s", inp);
    int len = strlen(inp);
    for(int i=0;i<len;i++){
        if(inp[i]=='(' || inp[i]=='['){
            st.push(inp[i]*-1);
            continue;
        }
        int tmp = 0;
        while( !( st.empty() || st.top()=='('*-1 || st.top()=='['*-1) ){  
            tmp += st.top();
            st.pop();
        }
        if(st.empty()){
            printf("0");
            return 0;
        }
        if(!tmp) tmp++;
        int t = st.top();
        st.pop();
        if(inp[i]==')'){
            tmp *= 2;
            if(t=='('*-1){
                st.push(tmp);
            }else{
                printf("0");
                return 0;
            }
        }else{
            tmp *= 3;
            if(t=='['*-1){
                st.push(tmp);
            }else{
                printf("0");
                return 0;
            }
        }
    }
    int ans = 0;
    while(!st.empty()){
        if(st.top()<=0){
            printf("0");
            return 0;
        }
        ans += st.top();
        st.pop();
    }
    printf("%d", ans);
    return 0;
}
