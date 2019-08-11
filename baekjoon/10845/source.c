#include <stdio.h>

int queue[10010];
int fr, ed;

void push(int a){
    queue[ed++] = a;
}
int pop(void){
    if(fr==ed) return -1;
    return queue[fr++];
}
int size(void){
    return ed-fr;
}
int empty(void){
    if(fr==ed) return 1;
    return 0;
}
int front(void){
    if(fr==ed) return -1;
    return queue[fr];
}
int back(void){
    if(fr==ed) return -1;
    return queue[ed-1];
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char inp[9];
        scanf(" %s", inp);
        switch(inp[0]){
            case 'p':
            if(inp[1]=='u'){
                int a;
                scanf("%d", &a);
                push(a);
            }else{
                printf("%d\n", pop());
            }
            break;
            case 's':
            printf("%d\n", size());
            break;
            case 'e':
            printf("%d\n", empty());
            break;
            case 'f':
            printf("%d\n", front());
            break;
            case 'b':
            printf("%d\n", back());
            break;
        }
    }
    return 0;
}
