#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

char inp[1000010], boom[40];
int ilen, blen, ptr = 0;
vector <pair<int, int>> v;
int jmp[1000010];

bool close_find(void);

void open_find(void){
    if(inp[ptr++]!=boom[0]){
        if(ptr>=ilen) return;
        v.clear();
    }else{
        int flg = 0, str = ptr-1;
        for(int i=1;i<blen;i++){
            if(ptr>=ilen) return;
            if(inp[ptr++]!=boom[i]){
                ptr--;
                flg = i;
                break;
            }
        }
        if(flg){
            v.emplace_back(str, flg);
        }else{
            jmp[str] = ptr;
            while(close_find());
        }
    }
}

bool close_find(void){
    if(ptr>=ilen) return 0;
    if(v.size()==0) return 0;
    if(inp[ptr]==boom[0]){
        return 0;
    }else if(inp[ptr++]!=boom[v.back().second]){
        ptr--;
        v.clear();
        return 0;
    }else{
        int flg = 0, fnxt = 1;
        for(int i=v.back().second+1;i<blen;i++){
            if(ptr>=ilen) return 0;
            if(inp[ptr++]!=boom[i]){
                ptr--;
                flg = i;
                if(inp[ptr]==boom[0]){
                    v.back().second = i;
                    fnxt = 0;
                }
                break;
            }
        }
        if(flg){
            if(fnxt) v.clear();
            return 0;
        }else{
            jmp[v.back().first] = ptr;
            v.pop_back();
            return 1;
        }
    }
}

int main(void){
    scanf("%s %s", inp, boom);
    ilen = strlen(inp);
    blen = strlen(boom);
    while(ptr<ilen){
        open_find();
    }
    int flg = 1;
    for(int i=0;i<ilen;i++){
        if(jmp[i]) { i = jmp[i]-1; continue; }
        printf("%c", inp[i]);
        flg = 0;
    }
    if(flg) printf("FRULA");
    return 0;
}
