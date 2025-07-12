#include <bits/stdc++.h>
#include "bubblesort2.h"
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//--------------------------------------------//

int N,Q;
vi a; 

const int MX=5e5+10;
/*set<int>t[MX*4];

void build(int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos].insert(a[tl]);
		return; 
	}

	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);

	for(int x: t[pos*2]) t[pos].insert(x);
	for(int x: t[pos*2+1]) t[pos].insert(x);
}

void upd(int idx, int v, int vo, int pos=1, int tl=0, int tr=N-1){
	t[pos].erase(vo); 
	t[pos].insert(v); 

	if(tl==tr)
		return; 

	int tm=(tl+tr)/2;
	if(idx<=tl) upd(idx,v,vo,pos*2,tl,tm);
	else upd(idx,v,vo,pos*2+1,tm+1,tr);
}

int get(int ty, int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(tl==l && tr==r){
		int cnt=0;
		if(ty){
			for(int x: t[pos]){
				if(x<v) cnt++;
				else break;
			}
		}
		else{
			for(int x: t[pos]){
				if(x>v) cnt++;
			}
		}
		return cnt; 
	}

	int tm=(tl+tr)/2;
	return get(ty,l,min(r,tm),v,pos*2,tl,tm) 
		+ get(ty,max(l,tm+1),r,v,pos*2+1,tm+1,tr);
}*/

void ckmax(int &x, int y){x=max(x,y);}

vi countScans(vi A,vi X,vi V){
	N=sz(A); Q=sz(X);
	a.assign(all(A));

	vi ans(Q);
	FOR(idx,0,Q){
		a[X[i]]=V[i];

		vi st,vec(N);
		ROF(i,0,N){
			while(sz(st) && st[sz(st)-1]<a[i]) st.pop_back();
			if(!sz(st)){
				vec[i]=(i!=N-1);
			} 
			else{
				vec[i]=vec[st.back]+1;
			}
			st.pb(a[i]);
		}
		ans[idx]=0;
		FOR(i,0,N) ckmax(ans[idx],vec[i]);
	}
	return ans; 
}
