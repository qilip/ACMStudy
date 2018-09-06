#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct point{
    int x, y;
    
    bool operator< (const point &o) const{
        if(y!=o.y) return y<o.y;
        return x<o.x;
    }
    point operator- (const point &o) const{
        return {x-o.x, y-o.y};
    }
};

int n;
vector<point> v;
vector<point> st;

ll ccw(point a, point b, point c){
    b = b - a;
    c = c - a;
    return (ll)b.x*c.y - (ll)c.x*b.y;
}

bool cmp(const point &a, const point &b){
    ll c = ccw(v[0], a, b);
    if(c) return c > 0;
    return a<b;
}

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    swap(v[0], v[min_element(v.begin(), v.end())-v.begin()]);
    sort(v.begin()+1, v.end(), cmp);
    st.push_back(v[0]);
    st.push_back(v[1]);
    for(int i=2;i<n;i++){
        st.push_back(v[i]);
        ll cw = ccw(st[st.size()-3], st[st.size()-2], st[st.size()-1]);
        if(cw<0){
            st.pop_back();
            st.pop_back();
            i--;
        }else if(cw==0){
            st.pop_back();
            st.pop_back();
            st.push_back(v[i]);
        }
    }
    printf("%d", st.size());
    return 0;
}
