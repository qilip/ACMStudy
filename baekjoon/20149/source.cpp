#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int ccw(pii a, pii b, pii c){
	ll p = a.first*b.second + b.first*c.second + c.first*a.second;
	p -= b.first*a.second + c.first*b.second + a.first*c.second;
	if(p>0) return 1;
	if(p<0) return -1;
	return 0;
}

int is_inter(pii a, pii b, pii c, pii d){
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
	
	if(ab == 0 && cd == 0){
		if(a > b) swap (a, b);
		if(c > d) swap (c, d);
		return c <= b && a<= d;
	}
	return ab <= 0 && cd <= 0;
}



int main(void){
    pii dot[4];
	for(int i=0;i<4;i++){
		scanf("%lld %lld", &dot[i].first, &dot[i].second);
	}
	int inter = is_inter(dot[0], dot[1], dot[2], dot[3]);
	if(inter) printf("1\n");
	else{
		printf("0\n");
		return 0;
	}
	double dx1 = dot[1].first - dot[0].first;
	double dx2 = dot[3].first - dot[2].first;
	double dy1 = dot[1].second - dot[0].second;
	double dy2 = dot[3].second - dot[2].second;
	pii a = dot[0];
	pii b = dot[1];
	pii c = dot[2];
	pii d = dot[3];
 	if(!dx1 && !dx2){
		if(a > b) swap (a, b);
		if(c > d) swap (c, d);
		if(c==b) printf("%lld %lld", c.first, c.second);
		if(a==d) printf("%lld %lld", a.first, a.second);
		return 0;
	}
	if(!dx1){
		double b2 = (double)d.second - d.first*(dy2/dx2);
		double y = (double)b.first*(dy2/dx2) + b2;
		printf("%.12lf %.12lf", (double)b.first, y);
		return 0;
	}
	if(!dx2){
		double b1 = (double)b.second - b.first*(dy1/dx1);
		double y = (double)d.first*(dy1/dx1) + b1;
		printf("%.12lf %.12lf", (double)d.first, y);
		return 0;
	}
	double m1 = dy1/dx1;
	double m2 = dy2/dx2;
	if(m1 == m2){
		if(a > b) swap (a, b);
		if(c > d) swap (c, d);
		if(c==b) printf("%lld %lld", c.first, c.second);
		if(a==d) printf("%lld %lld", a.first, a.second);
		return 0;
	}
	double b1 = (double)b.second - b.first*m1;
	double b2 = (double)d.second - d.first*m2;
	double x = (b2 - b1) / (m1 - m2);
	double y = (double)b1 + x*m1;
	printf("%.12lf %.12lf", x, y);
	return 0;	
}