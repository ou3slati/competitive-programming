//Never stop trying
//#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



/*ll solve(int d,int i){
	if(pos[i]==0) return 0;
	if(d==1){
		ll ans=0;
		
		while(i>=0){
			ll x=pos[i]; 
			x+=min(pos[i],L-pos[i]);
			ans+=x;
			i-=K;
		}
		
		return ans;
	}
	else{
		ll ans=0;
		while(i<sz(pos)){
			ll x=L-pos[i]; 
			x+=min(pos[i],L-pos[i]);
			ans+=x;
			i+=K;
		}
		return ans;
	}
}
*/

int N,K,L;
vi pos;

ll memo[1005][1005];

ll solve(int l, int r){
	if(l>r) return 0;
	if(memo[l][r]!=-1) return memo[l][r];
	ll ans=INF;

	int ll=1,rr=K;
	int k;
	//max k st l and l+k same side
	/*while(ll<=rr){
		int m=(ll+rr)/2;
		if(min( (L-pos[l])*2,pos[min(N-1,l+m)]*2 )<=L){
			k=m;
			ll=m+1;
		}
		else rr=m-1;
	}*/

	FOR(k,1,K+1){
		int nr=l+k-1; if(nr>r) break;
		ckmin(ans,solve(nr+1,r)+
			min(L,  min( (L-pos[l])*2,pos[nr]*2 )  ));

	/*ll=1,rr=K;
	//max k st r and r-k same side
	while(ll<=rr){
		int m=(ll+rr)/2;
		if(min( (L-pos[max(0,r-m)])*2,pos[r]*2 )<=L){
			k=m;
			ll=m+1;
		}
		else rr=m-1;
	}*/

	}

	FOR(k,1,K+1){
		int nl=r-k+1; if(nl<l) break;
		ckmin(ans,solve(l,nl-1)+
			min(L,  min( (L-pos[nl])*2,pos[r]*2 )  ));
	}

	return memo[l][r]=ans;

}

ll delivery(int NN, int KK, int LL, int positions[]){
	N=NN; K=KK; L=LL; FOR(i,0,N) pos.pb(positions[i]);
	
	pos.pb(0); N++; 
	sort(all(pos));

	if(K==1){
		ll ans=0;
		for(auto x: pos){ans+=(min(L-x,x))*2;}
		return ans;
	}
	if(K==N-1){
		ll ans=L;
		FOR(i,0,sz(pos)){
			ll x=pos[i]*2;
			if(i+1<sz(pos)) x+=(ll)(L-pos[i+1])*2;
			ckmin(ans,x);
		}
		return ans;
	}

	FOR(i,0,N) FOR(j,0,N) memo[i][j]=-1;
	return solve(0,N-1);
}


int main() {
	boost; IO();

	int N,K,L; cin>>N>>K>>L;
	int pos[N];
	FOR(i,0,N) cin>>pos[i];
	cout << delivery(N,K,L,pos) << endl;


	return 0;
}

/*
3 2 8
1 2 5
*/

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
