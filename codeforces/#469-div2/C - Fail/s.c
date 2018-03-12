#include <stdio.h>
#include <string.h>

int main(void){
    char inpts[200001];
    int inpt[200001] = {2};
    int ptr = 0, outnum = 0, outnums=0;
    int oindex[200001][4] = {0};
    scanf("%s", inpts);
    int leng = strlen(inpts);
    for(int i=0;i<leng;i++){
        inpt[i]=(int)inpts[i]-48;
        printf("%d", inpt[i]);
    }
    while(ptr<=leng) {
        A:;
        outnum++;
        if(inpt[ptr]==0) {
            oindex[outnum][1] = ptr+1;
            inpt[ptr]=2;
            ptr++;
            while(ptr<=leng) {
                if(inpt[ptr]==1) {
                    oindex[outnum][2] = ptr+1;
                    inpt[ptr]=2;
                    ptr++;
                    while(ptr<=leng) {
                        if(inpt[ptr]==0) {
                            oindex[outnum][3] = ptr+1;
                            oindex[outnum][0] = 3;
                            inpt[ptr]=2;
                            ptr=0;
                            outnums++;
                            goto A;
                        }else ptr++;
                    }
                }else ptr++;
            }
        }else ptr++;
    }
    ptr=0;
    while(ptr<=leng) {
        outnum++;
        if(inpt[ptr]==0) {
            oindex[outnum][1] = ptr+1;
            oindex[outnum][0] = 1;
            outnums++;
            ptr++;
        }else ptr++;
    }
    if(outnums){
        printf("%d\n", outnums);
    }else {
        printf("-1");
        return 0;
    }
    for(int i=1;i<outnum;i++){
        int tt = oindex[i][0];
        if(tt==0) goto B;
        else {
            for(int j=0;j<=tt;j++){
            printf("%d ", oindex[i][j]);
            }
        printf("\n");
        }
        B:;
    }
    return 0;
}
