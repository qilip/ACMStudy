#include <stdio.h>
#include <string.h>

int stack[10010];
int size = 0;

void push(int a){
    stack[size] = a;
    size++;
}

int pop(void){
    if(size==0) return -1;
    else {
        size--;
        return stack[size];
    }
}

int siz(void){
    return size;
}

int empty(void){
    if(size==0) return 1;
    else return 0;
}

int top(void){
    if(size==0) return -1;
    return stack[size-1];
}

int main(void) {
    int N;
    char cmd[40];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%s", cmd);
        if(strcmp(cmd,"push")==0){
            int tmp;
            scanf("%d", &tmp);
            push(tmp);
        }else if(strcmp(cmd,"pop")==0){
            printf("%d\n", pop());
        }else if(strcmp(cmd,"size")==0){
            printf("%d\n", siz());
        }else if(strcmp(cmd,"empty")==0){
            printf("%d\n", empty());
        }else if(strcmp(cmd,"top")==0){
            printf("%d\n", top());
        }
    }
    return 0;
}
