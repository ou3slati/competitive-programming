#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

void ckmax(int &x, int y){x=max(x,y);}

//---------

const ll MX=1e18;

int f(ll x, ll L, ll R){
	ll l=0,r=MX/x;
	while(l<=r){
		ll m=(l+r)/2;
		if(m*x>=L && m*x<=R) return 1;

		if(m*x<L) l=m+1;
		else r=m-1;
	}
	return 0;
}

int main(){
	IO();

	ll a,b; cin>>a>>b;
		
	int x=0,y=0;

	int p=0; ll cur=1;
	while(cur*2<=b){
		cur*=2; p++;
		if(f(cur,a,b)) x=p;
	}

	p=0; cur=1;
	while(cur*5<=b){
		cur*=5; p++;
		if(f(cur,a,b)) y=p;
	}

	cout << min(x,y) << endl;
}
