#include <stdio.h>

int main(void){
    char now[9], str[9];
    int nowq[3], strq[3], nows, strs, s=0, as;
    scanf("%s %s", now, str);
    for(int i=0;i<7;i+=3){
        nowq[s]=( ((int)now[i]-'0')*10 + ((int)now[i+1]-'0') );
        strq[s]=( ((int)str[i]-'0')*10 + ((int)str[i+1]-'0') );
        s++;
    }
    nows = nowq[0]*3600+nowq[1]*60+nowq[2];
    strs = strq[0]*3600+strq[1]*60+strq[2];
    if(nows>strs) as = 86400-(nows-strs);
    else as = strs-nows;
    int ah = as/3600;
    as = as%3600;
    printf("%02d:%02d:%02d", ah, as/60, as%60);
}
