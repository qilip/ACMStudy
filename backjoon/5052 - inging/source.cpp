#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

// Trie

typedef struct node{
    bool endNode;
    int child;

    node(){
        endNode = false;
    }
}node;

char buf[13];

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        while(n--){
            memset(buf, 0, sizeof(buf));
            scanf("%s", buf);
        }
    }
    return 0;
}
