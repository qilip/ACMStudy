#include <bits/stdc++.h>

char q[300] = "01SE Z r8        A   3  HI   M O   2TUVWXY5       d b    i  lmnoqp7  uvwx  ";
char p[5050];

int main(void){
    scanf(" %s", p);
    int l = strlen(p);
    for(int i=0;i<l/2;i++){
        int flg = 0;
        for(auto qi : {32, 0, -32}){
            if(qi == -32 && p[i] <= 'Z') continue;
            if(qi == 32 && p[i] <= '9') continue;
            for(auto ip : {32, 0, -32}){
                if(flg) break;
                if(ip == -32 && p[l-i-1] <= 'Z') continue;
                if(ip == 32 && p[l-i-1] <= '9') continue;
                if(q[p[i]-'0'+qi] == p[l-i-1]+ip) p[i] += qi, p[l-i-1] += ip, flg = 1;
            }
        }
        if(!flg){
            printf("-1\n");
            return 0;
        }
    }
    if(l%2 && q[p[l/2]-'0'] != p[l/2]){
        if(q[p[l/2]-'0'+32] == p[l/2]+32) p[l/2] += 32;
        else if(q[p[l/2]-'0'-32] == p[l/2]-32) p[l/2] -= 32;
        else{
            printf("-1\n");
            return 0;
        }
    }
    printf("%s\n", p);
}
