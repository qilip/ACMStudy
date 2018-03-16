#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    char in[60];
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%s", in);
        int len = strlen(in);
        int cnt = 0, rt;
        for(int j=0;j<len;j++){
            if(in[j]=='(') cnt++;
            else if(in[j]==')') cnt--;
            if(cnt<0) { rt=-1; goto END; }
        }
        if(cnt==0) rt=0;
        else rt=-1;
        END:;
        if(rt==-1) printf("NO\n");
        else printf("YES\n");
    }
}
