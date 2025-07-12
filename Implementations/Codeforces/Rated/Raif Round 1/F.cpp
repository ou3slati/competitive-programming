//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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



int32_t main() {
	boost; IO();

	int N; cin>>N;
	str s; cin>>s;

	int cnt=0;
	vpi vec; vec.pb({-INF,-1}); 
	FOR(i,0,N){
		if(s[i]=='1') cnt++;
		else if(cnt>0){
			vec.pb({i-cnt,i-1});
			cnt=0;
		}
	}
	if(cnt>0) vec.pb({N-cnt,N-1});
	vec.pb({N,INF}); 

	int szz[sz(vec)]; 
	FOR(i,0,sz(vec)) szz[i]=vec[i].se-vec[i].fi+1;

	//for(auto x: vec) cout << x.fi << ' '<<x.se << endl; 

	int left[sz(vec)],right[sz(vec)]; 
	vi stk;
	FOR(i,0,sz(vec)){
		while(!stk.empty() && szz[stk.back()]<szz[i]){
			stk.pop_back();
		}
		if(stk.empty()) left[i]=-1;
		else left[i]=stk.back();
		stk.pb(i);
	}
	stk.clear();
	ROF(i,0,sz(vec)){
		while(!stk.empty() && szz[stk.back()]<=szz[i]){
			stk.pop_back();
		}
		if(stk.empty()) right[i]=N;
		else right[i]=stk.back();
		stk.pb(i);
	}
	right[0]=sz(vec)-1;
	left[sz(vec)-1]=0;

	//FOR(i,0,sz(vec)) cout << left[i] << ' '; cout << endl;

	ll ans=0;
	FOR(i,1,sz(vec)-1){

		//taking all the segment
		int x=vec[i].fi-vec[left[i]].se 
			+ (left[i]!=0)*(szz[i]-1);
		int y=vec[right[i]].fi-vec[i].se 
			+ (right[i]!=sz(vec)-1)*(szz[i]); //break the ties on the right
		ans+=x*y*szz[i];

		//taking a part of the segment (without being out of it)
		FOR(n,1,szz[i]){
			ans+=n*(szz[i]-n+1);
		}

		//taking a part of the segment (right/left out of boundaries)
		//fixing left
		FOR(l,vec[i].fi+1,vec[i].se+1){
			int idx=-1;
			int rmv=(l-vec[i].fi);
			FOR(j,i+1,sz(vec)) if(vec[j].se-vec[j].fi+1>szz[i]-rmv){
				idx=j; break;
			}
			if(idx!=sz(vec)-1){
				idx=vec[idx].fi; idx+=(szz[i]-rmv)-1;
				ans+=(idx-vec[i].se)*(szz[i]-rmv);
			}
			else{
				idx=N-1;
				ans+=(idx-vec[i].se)*(szz[i]-rmv);
			}
		}
		

		FOR(r,vec[i].fi,vec[i].se){
			int idx=-1;
			int rmv=vec[i].se-r;
			FOR(j,1,i) if(vec[j].se-vec[j].fi+1>=szz[i]-rmv){
				idx=j; break;
			}
			if(idx!=-1){
				idx=vec[idx].se; idx-=(szz[i]-rmv)-2;
				ans+=(vec[i].fi-idx)*(szz[i]-rmv);
			}
			else{
				idx=0;
				ans+=(vec[i].fi-idx)*(szz[i]-rmv);
			}
		}
		
	}

	cout << ans << endl; 



	return 0;
}

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
