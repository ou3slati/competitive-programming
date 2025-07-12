//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "mushrooms.h"
#endif
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
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

const int B=80;

str s;

#ifdef LOCAL
int use_machine(vi v){
	str ss;
	for(auto i: v) ss+=s[i];
	int ans=0;
	FOR(i,1,sz(ss)) if(ss[i]!=ss[i-1]) ans++;
	return ans;
}
#endif

int count_mushrooms(int N){
	vi a,b; //type A/type B
	a.pb(0);
	int i=1; //index of the first element I don't know

	//Preparing a block
	while(i<N && sz(a)<B && sz(b)<B){
		if((sz(a)<2 && sz(b)<2) || i==N-1){
			int x=use_machine({0,i});
			if(x==0) a.pb(i);
			else b.pb(i);
			i++;
		}else{
			if(sz(a)>=2){
				int x=use_machine({i,a[0],i+1,a[1]});
				if(x==0) a.pb(i),a.pb(i+1);
				else if(x==1) b.pb(i),a.pb(i+1);
				else if(x==2) a.pb(i),b.pb(i+1);
				else b.pb(i),b.pb(i+1);
			}
			else{
				int x=use_machine({i,b[0],i+1,b[1]});
				if(x==0) b.pb(i),b.pb(i+1);
				else if(x==1) a.pb(i),b.pb(i+1);
				else if(x==2) b.pb(i),a.pb(i+1);
				else a.pb(i),a.pb(i+1);
			}
			i+=2;
		}
	}

	//Using & expanding the block
	int ans=sz(a);
	while(i<N){
		vi v; FOR(idx,i,min(N,i+max(sz(a),sz(b)))) v.pb(idx);
		if(sz(a)>=sz(b)){
			vi query;
			FOR(i,0,sz(v)){
				query.pb(a[i]);
				query.pb(v[i]);
			}
			int x=use_machine(query); x++; //number of blocks
			ans+=sz(v)-x/2; //x/2==nb of type B

			if(x%2==0) b.pb(v.back());
			else a.pb(v.back());
		}
		else{
			vi query;
			FOR(i,0,sz(v)){
				query.pb(b[i]);
				query.pb(v[i]);
			}
			int x=use_machine(query); x++; //number of blocks
			ans+=x/2;

			if(x%2==0) a.pb(v.back());
			else b.pb(v.back());
		}
		i+=sz(v);
	}

	return ans;
}

#ifdef LOCAL
int main() {
    boost; IO();

    cin>>s;
    cout << count_mushrooms(sz(s)) << endl;
    
    return 0;
}
#endif

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/