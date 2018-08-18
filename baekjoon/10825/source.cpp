#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct student{
    string name;
    int a, b, c;
    bool operator< (const student &o) const{
        if(a != o.a) return a > o.a;
        if(b != o.b) return b < o.b;
        if(c != o.c) return c > o.c;
        return name < o.name;
    }
};

student st[100010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> st[i].name >> st[i].a >> st[i].b >> st[i].c;
    }
    sort(st, st+n);
    for(int i=0;i<n;i++){
        cout << st[i].name << "\n";
    }
    return 0;
}
