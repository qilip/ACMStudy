#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

// Trie

struct Node{
    bool endNode;
    int child[10];
    Node(){
        endNode = false;
        memset(child, 0, sizeof(child));
    }
};

char buf[13];
vector<Node> node;
int nodeEnd;

bool tring(void){
    bool flg = true;
    int nodePtr = 0;
    int len = strlen(buf);
    for(int i=0;i<len;i++){
        int cha = buf[i]-'0';
        if(node[nodePtr].endNode) return true;
        else if(!node[nodePtr].child[cha]){
            flg = false;
            node[nodePtr].child[cha] = nodeEnd;
            node.emplace_back();
            if(i==len-1) node[nodeEnd].endNode = true;
            nodePtr = nodeEnd;
            nodeEnd++;
        }
        else nodePtr = node[nodePtr].child[cha];
    }
    return flg;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, flag = 0;
        node.clear();
        node.emplace_back();
        nodeEnd = 1;
        scanf("%d", &n);
        while(n--){
            scanf("%s", buf);
            if(tring()) flag = 1;
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
