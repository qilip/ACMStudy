#include <stdio.h>
#include <string.h>

char s[210];
int arr[5] = {0, 1, 0, 0, 2};
int sm, lg;

void swap(int a, int b){
    int t = arr[b];
    arr[b] = arr[a];
    arr[a] = t;
    return;
}

int main(void){
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0;i<len;i++){
        switch(s[i]){
            case 'A':
                swap(1, 2);
                break;
            case 'B':
                swap(1, 3);
                break;
            case 'C':
                swap(1, 4);
                break;
            case 'D':
                swap(2, 3);
                break;
            case 'E':
                swap(2, 4);
                break;
            default:
                swap(3, 4);
                break;
        }
    }
    for(int i=1;i<=4;i++){
        if(arr[i]==1) sm = i;
        if(arr[i]==2) lg = i;
    }
    printf("%d\n%d", sm, lg);
    return 0;
}
