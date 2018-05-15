#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>

using namespace std;

struct Node{
    int child[30];
    Node(){
        memset(child, 0, sizeof(child));
    }
};

int N, L;
unsigned char buf[20];
int okay[20][30];
vector<Node> node;
int nodeEnd;

void insert(void){
    int nodePtr = 0;
    for(int i=0;i<L;i++){
        int cha = buf[i]-'A';
        if(!node[nodePtr].child[cha]){
            node[nodePtr].child[cha] = nodeEnd;
            node.emplace_back();
            nodePtr = nodeEnd;
            nodeEnd++;
        }else{
            nodePtr = node[nodePtr].child[cha];
        }
    }
}

string answer;

void trfind(int nodePtr, int lev, bool flg, string ans){
    if(flg){
        for(int i=0;i<26;i++){
            if(node[nodePtr].child[i]){
                ans += i+'A';
                nodePtr = node[nodePtr].child[i];
                lev++;
                if(lev == L){
                    if(flg){
                        answer = ans;
                        break;
                    }
                }
                else trfind(nodePtr, lev, flg, ans);
            }
        }
    }else{
        int lflg = 0;
        for(int i=0;i<26;i++){
            if(!node[nodePtr].child[i] && okay[lev][i]){
                ans += i+'A';
                for(int j=0;j<26;j++){
                    if(node[nodePtr].child[j]){
                        nodePtr = node[nodePtr].child[j];
                        flg = true;
                        lev++;
                        if(lev == L) { if(flg) answer = ans; break; }
                        else { lflg = 1; break; }
                    }
                }
                break;
            }else if(node[nodePtr].child[i]){
                string newans;
                newans += ans;
                newans += i+'A';
                int newnodePtr = node[nodePtr].child[i];
                int newlev = lev + 1;
                if(newlev == L) break;
                else trfind(newnodePtr, newlev, flg, newans);
            }
        }
        if(lflg) trfind(nodePtr, lev, flg, ans);
    }
}

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        node.clear();
        node.emplace_back();
        nodeEnd = 1;
        memset(okay, 0, sizeof(okay));
        scanf("%d %d", &N, &L);
        for(int i=0;i<N;i++){
            memset(buf, 0, sizeof(buf));
            scanf("%s", buf);
            for(int j=0;j<L;j++){
                okay[j][buf[j]-'A'] = 1;
            }
            insert();
        }
        string asdf = "";
        answer = "-";
        trfind(0, 0, false, asdf);
        cout << "Case #" << t <<": "<< answer <<"\n";
    }
    return 0;
}
