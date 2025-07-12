#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
typedef vector<pi>vpi;
#define fi first
#define se second
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void ckmin(int &x, int y){x=min(x,y);}
//----------------------
const ll INF=1e9;
const int MX=2e5+10;
const int LOG=25;

int N; 
vi a(MX,INF);

//----------

vi t(MX*4);	
int combine(int i, int j){
	if(i==-1) return j; 
	if(j==-1) return i; 
	if(a[i]>=a[j]) return i; 
	return j; 
}
void build(int pos=1, int tl=1, int tr=N){
	if(tl==tr){
		t[pos]=tl;
		return; 
	}

	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}
int get(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return -1;
	if(l==tl && r==tr) return t[pos]; 

	int tm=(tl+tr)/2;
	return combine(get(l,min(r,tm),pos*2,tl,tm),
		get(max(tm+1,l),r,pos*2+1,tm+1,tr));
}
//-----------


int jump[MX][LOG],jumpRight[MX][LOG];

bool cmp(int i, int j){
	return a[i]>a[j];
}

vi lft,rgt;
vi vec; 
void precompute(){
	lft.assign(N+2,0); rgt.assign(N+2,N+1);

	vi st; 
	FOR(i,1,N+1){
		while(sz(st) && a[st.back()]<a[i]) st.pop_back();
		if(sz(st)) lft[i]=st.back();

		st.pb(i);
	}
	st.clear();

	ROF(i,1,N+1){
		while(sz(st) && a[st.back()]<a[i]) st.pop_back();
		if(sz(st)) rgt[i]=st.back();

		st.pb(i);
	}

	vec.resize(N);
	iota(all(vec),1);
	sort(all(vec),cmp);

	FOR(i,0,LOG){
		jump[0][i]=0;
		jumpRight[0][i]=0;
		jump[N+1][i]=N+1;
		jumpRight[N+1][i]=N+1;
	}

	a[0]=a[N+1]=-1;
	for(int i: vec){
		jumpRight[i][0]=rgt[i];

		if(a[rgt[i]]>=a[lft[i]]) jump[i][0]=rgt[i];
		else jump[i][0]=lft[i];

		FOR(b,1,LOG){
			jump[i][b]=jump[jump[i][b-1]][b-1];
			jumpRight[i][b]=jumpRight[jumpRight[i][b-1]][b-1];
		}
	}
	a[0]=a[N+1]=INF; 

	reverse(all(vec));
}

void init(int N, vi H){
	::N=N; 
	FOR(i,0,N) a[i+1]=H[i];

	build();
	precompute();
}

int cnt=0;
int minimum_jumps(int A, int B, int C, int D){
	A++; B++; C++; D++;

	int e=get(C,D),s;

	int l=1,r=e; 
	while(l<=r){
		int m=(l+r)/2;
		if(a[get(m,e)]<=a[e]){
			s=m; 
			r=m-1;
		}
		else l=m+1;
	}
	if(s>B) return -1;
	if(C==B+1) return 1;	
	
	l=max(s,A); r=B; 
	s=get(l,r);

	int ee=get(B+1,C-1);
	if(a[ee]<a[s]) return 1;

	int ans=2;
	ROF(i,0,LOG) if(a[jump[s][i]]<a[ee]){
		s=jump[s][i];
		ans+=(1<<i);
	}
	if(a[jump[s][0]]<=a[e]) return ans; 

	ROF(i,0,LOG) if(a[jumpRight[s][i]]<a[ee]){
		s=jumpRight[s][i];
		ans+=(1<<i);
	}
	return ans; 
}
