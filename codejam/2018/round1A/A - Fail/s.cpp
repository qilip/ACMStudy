#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int R, C, H, V;
        char rc[120][120] {0} ;
        int cntr[120] = {0} , cntc[120] = {0} , choco = 0;
        scanf("%d %d %d %d", &R, &C, &H, &V);
        for(int i=0;i<R;i++){
            scanf("%s", rc[i]);
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(rc[i][j]=='@'){
                    cntr[i]++; cntc[j]++; choco++;
                }
            }
        }
        if(choco == 0){
            printf("Case #%d: POSSIBLE\n", t);
            continue;            
        }
        //R
        int rchoco = 0, rrchoco = choco/(H+1), rcnt = 0, lcnt = 0;
        int cntline[120], endline[120];
        memset(cntline, 50, sizeof(cntline));
        memset(endline, 50, sizeof(endline));
        for(int i=0;i<R;i++){
            rchoco += cntr[i];
            if(rchoco == rrchoco){
                rchoco = 0;
                rcnt++;
                //C
                int cchoco = 0, ccchoco = choco/((H+1)*(V+1)), ccnt = 0;

                if(cntline[119] == 1){
                    int flg = 0;
                    for(int j=0;j<C;j++){
                        for(int k=lcnt;k<=i;k++){
                            if(rc[k][j] == '@') cchoco++;
                        }
                        if(cntline[ccnt] <= j && endline[ccnt+1] >= j){
                            if(cchoco == ccchoco){
                                cchoco = 0;
                                ccnt++;
                            }
                        }
                    }
                    if(ccnt != V+1){
                        printf("Case #%d: IMPOSSIBLE\n", t);
                        goto SubEnd;
                    }
                }else{
                    for(int j=0;j<C;j++){
                        endline[ccnt] = j-1;
                        for(int k=lcnt; k<=i;k++){
                            if(rc[k][j] == '@'){
                                cchoco++;
                            }
                        }
                        if(cchoco == ccchoco){
                            cchoco = 0;
                            cntline[119] = 1;
                            cntline[ccnt] = j;
                            ccnt++;
                        }
                        else if(cchoco > ccchoco){
                            printf("Case #%d: IMPOSSIBLE\n", t);
                            goto SubEnd;
                        }
                        
                    }
                    if(ccnt != V+1){
                        printf("Case #%d: IMPOSSIBLE\n", t);
                        goto SubEnd;
                    }
                }

                lcnt = i+1;
                //C end
            }
            else if(rchoco > rrchoco){
                printf("Case #%d: IMPOSSIBLE\n", t);
                goto SubEnd;
            }
        }
        if(rcnt != H+1){
            printf("Case #%d: IMPOSSIBLE\n", t);
            goto SubEnd;            
        }

        printf("Case #%d: POSSIBLE\n", t);
        SubEnd:;
    }
    return 0;
}
