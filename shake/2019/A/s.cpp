#include <stdio.h>

int main(void){
    int l;
    scanf("%d", &l);
    int a[10] = {0};
    int used[10] = {0};
    int no = 0;
    for(int i=0;i<l;i++){
        scanf("%d", &a[i]);
    }
    used[a[0]] = 1;
    for(int i=1;i<l;i++){
        switch(a[i]){
            case 1:
            if(used[1]) no = 1;
            if((a[i-1] != 3 || used[2]) && (a[i-1] != 7 || used[4]) && (a[i-1] != 9 || used[5])){
                used[1] = 1;
            }else{
                no = 1;
            }
            break;
            case 2:
            if(used[2]) no = 1;
            if(a[i-1] != 8 || used[5]){
                used[2] = 1;
            }else{
                no = 1;
            }
            break;
            case 3:
            if(used[3]) no = 1;
            if((a[i-1] != 1 || used[2]) && (a[i-1] != 7 || used[5]) && (a[i-1] != 9 || used[6])){
                used[3] = 1;
            }else{
                no = 1;
            }
            break;
            case 4:
            if(used[4]) no = 1;
            if(a[i-1] != 6 || used[5]){
                used[4] = 1;
            }else{
                no = 1;
            }
            break;
            case 5:
            if(used[5]) no = 1;
            used[5] = 1;
            break;
            case 6:
            if(used[6]) no = 1;
            if(a[i-1] != 4 || used[5]){
                used[6] = 1;
            }else{
                no = 1;
            }
            break;
            case 7:
            if(used[7]) no = 1;
            if((a[i-1] != 1 || used[4]) && (a[i-1] != 3 || used[5]) && (a[i-1] != 9 || used[8])){
                used[7] = 1;
            }else{
                no = 1;
            }
            break;
            case 8:
            if(used[8]) no = 1;
            if(a[i-1] != 2 || used[5]){
                used[8] = 1;
            }else{
                no = 1;
            }
            break;
            case 9:
            if(used[9]) no = 1;
            if((a[i-1] != 1 || used[5]) && (a[i-1] != 7 || used[8]) && (a[i-1] != 3 || used[6])){
                used[9] = 1;
            }else{
                no = 1;
            }
            break;
        }
    }
    if(no==0){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
