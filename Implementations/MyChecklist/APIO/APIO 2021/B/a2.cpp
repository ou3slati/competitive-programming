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


//----------------------
void ckmin(int &x, int y){x=min(x,y);}


const ll INF=1e9;
const int MX=2e3+10;

int N; 
vi a(MX);

//----------

vector<vi>t(MX,vi(MX*4,INF));

void upd(int idx, int i, int v, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[idx][pos]=v;
		return; 
	}

	int tm=(tl+tr)/2;
	if(i<=tm) upd(idx,i,v,pos*2,tl,tm);
	else upd(idx,i,v,pos*2+1,tm+1,tr);

	t[idx][pos]=min(t[idx][pos*2],t[idx][pos*2+1]);
}

int get(int idx, int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return INF; 

	if(l==tl && r==tr){
		return t[idx][pos];
	}
	int tm=(tl+tr)/2;
	return min(get(idx,l,min(r,tm),pos*2,tl,tm),
		get(idx,max(l,tm+1),r,pos*2+1,tm+1,tr));
}

//-----------


bool cmp(int i, int j){
	return a[i]<a[j];
}
void init(int N, vi H){
	::N=N; 
	FOR(i,0,N) a[i]=H[i];

	vi order(N); iota(all(order),0);
	sort(all(order),cmp);

	vi prev(N,-1),nxt(N,-1);
	vi st; 
	FOR(i,0,N){	
		while(sz(st) && a[st.back()]<a[i]) st.pop_back();
		if(sz(st)) prev[i]=st.back();
		st.pb(i);
	}
	st.clear();
	ROF(i,0,N){	
		while(sz(st) && a[st.back()]<a[i]) st.pop_back();
		if(sz(st)) nxt[i]=st.back();
		st.pb(i);
	}

	FOR(i,0,N){
		vi dp(N,INF); 
		dp[i]=0;
		for(int j: order){
			if(prev[j]!=-1) ckmin(dp[prev[j]],dp[j]+1);
			if(nxt[j]!=-1) ckmin(dp[nxt[j]],dp[j]+1);
		}
		FOR(j,0,N) upd(i,j,dp[j]);
	}
}

int minimum_jumps(int A, int B, int C, int D){
	int ans=INF;
	FOR(i,A,B+1){
		ckmin(ans,get(i,C,D));
	}
	if(ans==INF) ans=-1;
	return ans;
}
