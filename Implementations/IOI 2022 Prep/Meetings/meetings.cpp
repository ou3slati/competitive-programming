#include "meetings.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<pi>vpi; 
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void ckmax(ll &x, ll y){x=max(x,y);}
void ckmin(ll &x, ll y){x=min(x,y);}
//--------------------

const int MX=1e5+10; 

int N,Q; 
vi H; 

struct node{
	int x,l,r,len; 
}; 

node combine(node a, node b){
	node c; 
	c.x=max(max(a.x,b.x),a.r+b.l); 
	c.l=a.l + (a.x==a.len)*b.l;
	c.r=b.r + (b.x==b.len)*a.r; 
	c.len=a.len+b.len;
	return c; 
}

vector<node>t(MX*4); 

void build(int l=0, int r=N-1, int pos=1){
	if(l==r){
		int x=(H[l]==1); 
		t[pos]={x,x,x,1}; 
		return; 
	}

	int m=(l+r)/2;
	build(l,m,pos*2); 
	build(m+1,r,pos*2+1); 

	t[pos]=combine(t[pos*2],t[pos*2+1]); 
}

node query(int l, int r, int tl=0, int tr=N-1, int pos=1){
	if(l>r) return node{0,0,0,0}; 

	if(l==tl && r==tr) return t[pos]; 

	int tm=(tl+tr)/2; 

	return combine( query(l,min(r,tm),tl,tm,pos*2), query(max(l,tm+1),r,tm+1,tr,pos*2+1) );

}




vector<ll> minimum_costs(vi H, vi L, vi R) {
	N=sz(H); Q=sz(L); 
	::H=H; 

	if(N<=5000 && Q<=5000){
		vector<vector<ll>>c(N,vector<ll>(N,0ll));
		FOR(i,0,N){
			FOR(j,i,N){
				c[i][j]=H[j]; 
				if(j>i) ckmax(c[i][j],c[i][j-1]); 
			}

			ROF(j,0,i){
				c[i][j]=H[j]; 
				ckmax(c[i][j],c[i][j+1]); 
			}

			FOR(j,1,N) c[i][j]+=c[i][j-1]; 
		}

		vector<ll>ans; 
		FOR(i,0,Q){
			int l=L[i], r=R[i]; 

			ll mn=1e18; 

			FOR(m,l,r+1){
				ll x=c[m][m]; if(l) x-=c[m][l-1]; 
				ll y=c[m][r]-c[m][m]; 
				ckmin(mn,x+y); 
			}

			ans.pb(mn); 
		}
		return ans; 
	}


	build(); 

	vector<ll>ans; 
	FOR(i,0,Q){
		int l=L[i], r=R[i]; 
		int len=query(l,r).x; 
		ll x=len + (r-l+1-len)*2; 
		ans.pb(x); 
	}
	return ans; 

	

	
}

/*

3 3
2 1 2
0 0
0 1
0 2



*/