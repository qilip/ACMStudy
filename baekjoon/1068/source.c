#include <stdio.h>

int node[70], leaf[70];

int find(int a){
    if(node[a]==-1){
        return 1;
    }else if(node[a]==-2){
        return 0;
    }else{
        return find(node[a]);
    }
}

int main(void){
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &node[i]);
        if(node[i]!=-1) leaf[node[i]]++;
    }
    int del;
    scanf("%d", &del);
    leaf[node[del]]--;
    node[del] = -2;
    for(int i=0;i<n;i++){
        if(!leaf[i]) cnt += find(i);
    }
    printf("%d", cnt);
    return 0;
}
