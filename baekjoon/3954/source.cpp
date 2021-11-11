#include <bits/stdc++.h>

using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int sm = 0, sc = 0, si = 0;
		char mem[100'0010] = {0};
		char pro[5000] = {0};
		char inp[5000] = {0};
		int pp = 0, ptr = 0, ip = 0, pc = 0;
		stack<int> st;
		map<int, int> jml;
		map<int, int> jmr;
		int llop = 9999'9999;
		scanf("%d %d %d", &sm, &sc, &si);
		scanf(" %s", pro);
		scanf(" %s", inp);
		for(int i=0; i<sc; i++){
			if(pro[i] == '[') st.push(i);
			if(pro[i] == ']'){
				int a = st.top();
				st.pop();
				jml[a] = i;
				jmr[i] = a;
			}
		}
		for(pp=0; pp<sc; pp++){
			if(pc==1'0000'0001) break;
			if(pc==5000'0000) llop = 9999'9999;
			switch(pro[pp]){
				case '-': mem[ptr]--; break;
				case '+': mem[ptr]++; break;
				case '<': ptr = (ptr-1+sm)%sm; break;
				case '>': ptr = (ptr+1)%sm; break;
				case '[': if(!mem[ptr]) pp = jml[pp]; break;
				case ']': if(mem[ptr]){ pp = jmr[pp]; llop = llop>pp?pp:llop; } break;
				case ',': mem[ptr] = ip<si?inp[ip++]:255; break;
			}
			pc++;
		}
		if(pc<=5000'0000) printf("Terminates\n");
		else printf("Loops %d %d\n", llop, jml[llop]);
	}
	return 0;
}
