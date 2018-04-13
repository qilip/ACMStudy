#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int q=1;q<=T;q++){
        int D, cng = 0;
        char P[40];
        scanf("%d %s", &D, P);
        int len = strlen(P);
        int shtdmg = 1, dmgsum = 0, cntc = 0, cnts = 0;
        for(int i=0;i<len;i++){
            if(P[i]=='C') {
                shtdmg *=2; cntc++;
            }
            if(P[i]=='S') {
                dmgsum += shtdmg; cnts++;
            }
        }
        if(D>=dmgsum){
            printf("Case #%d: %d\n", q, cng);
            continue;
        }else if(!cntc || !cnts){
            printf("Case #%d: IMPOSSIBLE\n", q);
            continue;
        }
        //
        while(1){
            int newcng = 0;
            for(int i=len-1;i>0;i--){
                if(P[i]=='S' && P[i-1]=='C'){
                    P[i]='C';
                    P[i-1]='S';
                    cng++; newcng = 1;
                    break;
                }
            }
            if(newcng==0){
                printf("Case #%d: IMPOSSIBLE\n", q);
                break;
            }
            int shtdmg = 1, dmgsum = 0;
            for(int i=0;i<len;i++){
                if(P[i]=='C') shtdmg *=2;
                if(P[i]=='S') dmgsum += shtdmg;
            }
            if(D>=dmgsum){
                printf("Case #%d: %d\n", q, cng);
                break;
            }
        }

    }
}
