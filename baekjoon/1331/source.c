#include <stdio.h>
#include <stdlib.h>

int main(void){
    int board[6][6] = { 0 };
    char stt[3] = { 0 };
    char bef[3] = { 0 };
    int sucess = 1;
    for(int i=0;i<36;i++){
        char s[3];
        scanf(" %s", s);
        if(s[0] < 'A' || 'F' < s[0] || s[1] < '1' || '6' < s[1]){
            sucess = 0;
            break;
        }
        if(i == 0){
            stt[0] = s[0], stt[1] = s[1];
        }else{
            int x = abs(bef[0] - s[0]);
            int y = abs(bef[1] - s[1]);
            if(x>y) x = x ^ y, y = x ^ y, x = x ^ y;
            if(!(x == 1 && y == 2)){
                sucess = 0;
                break;
            }
            if(i == 35){
                x = abs(stt[0] - s[0]);
                y = abs(stt[1] - s[1]);
                if(x>y) x = x ^ y, y = x ^ y, x = x ^ y;
                if(!(x == 1 && y == 2)){
                    sucess = 0;
                    break;
                }
            }
        }
        if(board[s[0]-'A'][s[1]-'1']){
            sucess = 0;
            break;
        }
        board[s[0]-'A'][s[1]-'1'] = 1;
        bef[0] = s[0], bef[1] = s[1];
    }
    if(sucess) printf("Valid");
    else printf("Invalid");
    return 0;
}
