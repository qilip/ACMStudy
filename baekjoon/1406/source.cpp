#include <stdio.h>
#include <list>

using namespace std;

int main(void){
    list<char> l;
    char inp[100006];
    int n;
    scanf("%s", inp);
    for(int i=0;inp[i]!='\0';i++){
        l.push_back(inp[i]);
    }
    list<char>::iterator iter=l.end();
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char tmp;
        scanf(" %c", &tmp);
        switch(tmp){
            case 'L':{
                if(iter!=l.begin()) iter--;
                break;
            }case 'D':{
                if(iter!=l.end()) iter++;
                break;
            }case 'B':{
                if(iter!=l.begin()) iter = l.erase(--iter);
                break;
            }case 'P':{
                char s;
                scanf(" %c", &s);
                l.insert(iter, s);
                break;
            }
        }
    }
    for(auto i=l.begin(); i!=l.end();i++){
        printf("%c", *i);
    }
    return 0;
}
