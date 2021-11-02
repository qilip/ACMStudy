#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    int n, q, cap;
    int nc[2010] = {0};
    scanf("%d %d %d", &n, &q, &cap);
    for(int i=1;i<=n;i++){
        scanf("%d", &nc[i]);
    }
    deque<int> back;
    deque<int> front;
    int cash = 0;
    int cur = -1;
    for(int i=1;i<=q;i++){
        char c;
        scanf(" %c", &c);
        switch(c){
            case 'B':
                if(!back.empty()){
                    front.push_front(cur);
                    cur = back.front();
                    back.pop_front();
                }
                break;
            case 'F':
                if(!front.empty()){
                    back.push_front(cur);
                    cur = front.front();
                    front.pop_front();
                }
                break;
            case 'A':
                int page;
                scanf("%d", &page);
                cash += nc[page];
                for(int j : front) cash -= nc[j];
                front.clear();
                if(cur != -1)
                    back.push_front(cur);
                cur = page;
                while(cash > cap){
                    cash -= nc[back.back()];
                    back.pop_back();
                }
                break;
            case 'C':
                int bef = -1;
                for(int i=0;i<(int)back.size();i++){
                    if(bef == back[i]) cash -= nc[back[i]];
                    bef = back[i];
                }
                back.erase(unique(back.begin(), back.end()), back.end());
                break;
        }
    }
    printf("%d\n", cur);
    if(!back.empty())
        for(int x : back) printf("%d ", x);
    else printf("-1");
    printf("\n");
    if(!front.empty())
        for(int x : front) printf("%d ", x);
    else printf("-1");
    printf("\n");
    return 0;
}
