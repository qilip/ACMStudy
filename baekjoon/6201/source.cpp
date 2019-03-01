#include <stdio.h>
#include <vector>

using namespace std;

int n, st, ed;
bool in[30] = {false};
vector<char> v[16];
int cnt = 1;
vector<char> m;

void func(int depth){
    if(cnt>ed) return;
    if(depth==n){
        if(cnt>=st){
            for(auto s : m) printf("%c", s);
            printf("\n");
            cnt++;
        }else cnt++;
        return;
    }
    for(auto i : v[depth]){
        if(!in[i-'A']){
            in[i-'A'] = true;
            m.push_back(i);
            func(depth+1);
            m.pop_back();
            in[i-'A'] = false;
        }else continue;
    }
    return;
}

int main(void){
    scanf("%d %d %d", &n, &st, &ed);
    getchar();
    for(int i=0;i<n;i++){
        char s;
        s = getchar();
        while(s!='\n'){
            v[i].push_back(s);
            s = getchar();
        }
    }
    func(0);
    return 0;
}
