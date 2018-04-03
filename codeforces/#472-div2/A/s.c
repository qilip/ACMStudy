#include <stdio.h>

int main(void){
    int n, cnt=0;
    char inp[110];
    scanf("%d", &n);
    scanf("%s", inp);
    if(n==1 && inp[0] == '?'){
        cnt = 2;
    }
    for(int i=1;i<n;i++){
        if(inp[i-1]==inp[i] && inp[i]!='?'){
            printf("No"); return 0;
        }else if(inp[i-1]=='?' && inp[i]=='?'){
            cnt=2;
        }else if(i==1 && inp[0]=='?'){
            cnt=2;
        }else if(i==n-1 && inp[i]=='?'){
            cnt=2;
        }else if(inp[i]=='?'){
            if(inp[i-1]==inp[i+1]){
                cnt=2;
            }
        }
    }
    if(cnt>=2) printf("Yes");
    else printf("No");
}
