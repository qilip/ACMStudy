#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int s[10][2][4][4];
int wit[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
int ord[] = {0, 1, 2};
int rot[] = {3, 3, 3};
int stp[] = {3, 3, 3};

void cng(int cur[]){
    int pt = 0;
    while(1){
        if(cur[pt]<3){
            cur[pt]++; break;
        }else{
            if(pt==2){
                cur[0] = 0; cur[1] = 0; cur[2] = 0;
                break;
            }
            cur[pt++] = 0;
        }
    }
}

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int q=0;q<4;q++)
            for(int w=0;w<4;w++)
                scanf("%d", &s[i][0][q][w]);
        for(int q=0;q<4;q++)
            for(int w=0;w<4;w++)
                scanf(" %c", &s[i][1][q][w]);
    }
    sort(wit, wit+n);
    do{
        do{
            for(int q=0;q<4*4*4;q++){
                cng(rot);
                for(int w=0;w<4*4*4;w++){
                    cng(stp);
                    
                }
            } 
        }while(next_permutation(ord, ord+3));
    }while(next_permutation(wit, wit+n));
    return 0;
}
