#include <bits/stdc++.h>
#define F(I,N) for(int I=1;I<=N;I++)
#define EP(Q) {#Q, Q}
#define ITI(Q) it.insert(EP(Q))
#define ACI(Q) ac.insert(EP(Q))
#define MVI(Q,A,B) mv.insert({Q,{A,B}})
#define LV p[2]
#define MHP (15+LV*5)
#define LAD (LV*2)
using namespace std;
using po = pair<int,int>;
enum IT{W,A,O};
enum AC{HR,RE,CO,EX,DX,HU,CU};
map<string, int> it,ac;
map<char, po> mv;
int n,m,k=1,l,px,py,fx,fy,t,a,b,p[19]={0,20,1};
char g[102][102];
string s;
struct E{string s;int x[5];};
map<po, E*> em;
int main(void){
	ITI(W);ITI(A);ITI(O);
	ACI(HR);ACI(RE);ACI(CO);ACI(EX);ACI(DX);ACI(HU);ACI(CU);
	MVI('L',0,-1);MVI('R',0,1);MVI('U',-1,0);MVI('D',1,0);
	fill(g[0],g[102],'#');
	cin>>n>>m;
	F(i,n) F(j,m){
		char* c=&g[i][j];
		cin>>*c;
		if(*c=='@') *c='.',fx=px=i,fy=py=j;
		if(*c=='&') k++;
		if(*c=='B') l++;
	}
	cin>>s;
	F(i,k){
		int r,c;E* t=new E;
		cin>>r>>c>>t->s;
		F(i,4) cin>>t->x[i];
		em[{r,c}]=t;
	}
	F(i,l){
		int r,c;string q;E* t=new E;
		cin>>r>>c>>q;
		t->x[1]=it[q];
		if(q!="O") cin>>t->x[2];
		else {cin>>q;t->x[2]=ac[q];}
		em[{r,c}]=t;
	}
	for(char c:s){
		t++;
		auto [x,y]=mv[c];
		int nx=px+x,ny=py+y;
		if(g[nx][ny]!='#') px=nx,py=ny;
		char* w=&g[px][py];
		int* v;
		if(*w=='^') p[1]-=p[11]?1:5;
		if(*w=='B'){
			v=em[{px,py}]->x;
			if(v[1]!=2) p[4+v[1]]=v[2];
			else if(p[6]<4&&!p[7+v[2]]) p[6]++,p[7+v[2]]++;
		}
		if(*w=='M'||*w=='&'){
			if(*w=='M') p[0]=1,p[14]=p[12],p[1]=p[12]?MHP:p[1];
			v=em[{px,py}]->x;a=v[3];b=p[9]?p[9]+p[11]+1:1;
			while(p[1]>0&&a>0){
				a-=max(1,(LAD+p[4])*b-v[2]);b=1;
				if(a>0) p[1]-=p[14]?p[14]=0:max(1,v[1]-LAD-p[5]);
				else p[1]+=p[7]*3,p[3]+=v[4]*(5+p[10])/5;
			}
		}
		if(p[1]>MHP) p[1]=MHP;
		if(p[1]<1){
			if(p[8]){p[1]=MHP,p[0]=p[8]=0,p[6]--,px=fx,py=fy;continue;}
			p[1]=0;break;
		}
		if(*w!='^') *w='.';
		if(p[3]>=LV*5) p[2]++,p[3]=0,p[1]=MHP;
		if(p[0])break;
	}
	if(p[1]>0) g[px][py]='@';
	F(i,n) F(j,m) {cout<<g[i][j];if(j==m)cout<<'\n';}
	cout<<"Passed Turns : "<<t<<'\n'<<"LV : "<<LV<<'\n'<<"HP : "<<p[1]<<'/'<<MHP<<'\n'<<"ATT : "<<LAD<<'+'<<p[4]<<'\n'<<"DEF : "<<LAD<<'+'<<p[5]<<'\n'<<"EXP : "<<p[3]<<'/'<<LV*5<<'\n';
	if(p[1]>1) cout<<(p[0]?"YOU WIN!\n":"Press any key to continue.\n");
	else cout<<"YOU HAVE BEEN KILLED BY "<<(g[px][py]=='^'?"SPIKE TRAP":em[{px,py}]->s)<<"..\n";
	return 0;
}