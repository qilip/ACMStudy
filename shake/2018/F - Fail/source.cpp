#include <stdio.h>
#include <string.h>

int state = 0;
int fsm(char in){
    switch(state){
        case 0:
            state = in=='B' ? 1 : -1;
            break;
        case 1:
            state = in=='B' ? 1 : (in=='A' ? 2 : -1);
            break;
        case 2:
            state = in=='N' ? 3 : -1;
            break;
        case 3:
            state = in=='A' ? 4 : -1;
            break;
        case 4:
            state = in=='N' ? 5 : -1;
            break;
        case 5:
            state = in=='A' ? 6 : -1;
            break;
        case 6:
            state = in=='N' ? 5 : (in=='B' ? 1 : -1);
            break;
        default:
            return 1;
    }
    if(state==-1) return 1;
    else return 0;
}

int main(void){
    char s[100010];
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(fsm(s[i])){
            
        }
    }
    if(state!=6){

    }
    return 0;
}
