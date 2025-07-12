//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N,K; 
vector<ll> p(MX,0);


//p[j]*p[i] + (dp[j][k-1]-p[j]*p[N]) + p[i]*(p[N]-p[i])
//increasing slope + increasing x

//ax+b=cx+d
//x(a-c)=d-b
//x=(d-b)/(a-c)

ld inter(ll a, ll b, ll c, ll d){
	return (ld)(d-b)/(a-c);
}

deque<pair<pair<ll,ll>,int>>st; 
void re(){
	st.clear();
}
void add(ll a, ll b, int i){
	while(sz(st)>1){
		ll a2,b2,a3,b3; int n=sz(st);
		tie(a2,b2)={st.back().fi.fi,st.back().fi.se};
		tie(a3,b3)={st[n-2].fi.fi,st[n-2].fi.se};
		ld x=inter(a,b,a2,b2),y=inter(a2,b2,a3,b3);

		if(x<y) st.pop_back();
		else break;
	}
	st.pb({{a,b},i});
}

pair<ll,int>get(ll x){
	while(sz(st)>1){
		ll a,b,a2,b2; int n=sz(st);
		tie(a,b)={st[0].fi.fi,st[0].fi.se};
		tie(a2,b2)={st[1].fi.fi,st[1].fi.se};

		ld y=inter(a,b,a2,b2);
		if(x>y) st.pop_front();
		else break;
	}
	ll a,b,idx=st[0].se; 
	tie(a,b)={st[0].fi.fi,st[0].fi.se};
	return {a*x+b,idx};
}

int main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,1,N+1) cin>>p[i];
   	//Removing zeros
   	vi nw; 
   	FOR(i,1,N+1) if(p[i]) nw.pb(p[i]);
   	p.assign(all(nw));
   	N=sz(p);
   	ckmin(K,N-1);
   	if(!N){
   		cout << 0 << endl;
   		return 0;
   	}
   	/////////////////////

    FOR(i,1,N+1) p[i]+=p[i-1];

    vector<vector<ll>>dp(N+1,vector<ll>(K+1,-INF));
    vector<vi>prev(N+1,vi(K+1,-1));

    FOR(k,1,K+1){
    	re();
    	add(p[0],dp[0][k-1]-p[0]*p[N],0);
    	FOR(i,1,N+1){
    		pi ans=get(p[i]);
    		ans.fi+=p[i]*(p[N]-p[i]);

    		dp[i][k]=ans.fi; 
    		prev[i][k]=ans.se;

    		add(p[i],dp[i][k-1]-p[i]*p[N],i);
    	}
    }
    
    int idx=N,k=K;
    FOR(i,1,N+1) if(dp[i][K]>dp[idx][K]) idx=i;

    cout << dp[idx][K] << endl;

    vi vec;
    while(1){
    	vec.pb(idx);
    	idx=prev[idx][k];
    	k--;
    	if(!idx) break;
    }
    reverse(all(vec));
    for(auto x: vec) cout << x << ' ';
    cout << endl;

    

    return 0;
}
//Change your approach 