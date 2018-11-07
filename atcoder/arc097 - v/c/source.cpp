#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    char s[5050];
    scanf("%s", s);
    int len = strlen(s);
    int k;
    scanf("%d", &k);
    vector<string> v;
    for(int i=0;i<len;i++){
        string q;
        for(int j=i, a = 0;j<len && a<5;j++, a++){
            q+=(s[j]);
            v.push_back(q);
        }
    }
    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());
    v.erase(end, v.end());
    printf("%s", v[k-1].c_str());
    return 0;
}
