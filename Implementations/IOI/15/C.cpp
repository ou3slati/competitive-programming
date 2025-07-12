//Never stop trying
//#include "teams.h"
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

int N; 
int l[MX],r[MX];
multiset<pi> ss;

void init(int NN, int AA[], int BB[]){
	N=NN; FOR(i,0,N) l[i]=AA[i],r[i]=BB[i];
	FOR(i,0,N) ss.insert({l[i],r[i]});
}


int can(int M, int k[]){
	vi a;
	FOR(i,0,M) a.pb(k[i]);
	sort(all(a));

	/*ll S=0;
	for(auto x: a) S+=x; 
	if(x>N) return 0;*/

	multiset<pi> s,s1,s2;
	for(auto x: ss){
		s.insert({x.se,x.fi});
		s1.insert(x);
	}

	FOR(i,0,M){
		while(!s.empty() && (*s.begin()).fi<a[i]){
			pi p=(*s.begin());
			s.erase(s.begin());
			if(s1.count({p.se,p.fi})>0) s1.erase(s1.find({p.se,p.fi}));
			if(s2.count(p)>0) s2.erase(s2.find(p));
		}

		while(!s1.empty() && (*s1.begin()).fi<=a[i]){
			pi p=(*s1.begin());
			s1.erase(s1.begin());
			s2.insert({p.se,p.fi});
		}
		//cout << a[i] << ' ' << sz(s2) << endl;
		if(sz(s2)<a[i]) return 0;
		int X=a[i];
		while(X--){
			pi p=(*s2.begin());
			s2.erase(s2.begin());
			//s1.erase(s1.find({p.se,p.fi}));
			s.erase(s.find(p));
		}
	}

	return 1;
}

int32_t main() {
	boost; IO();

	int N; cin>>N;
	int l[N],r[N];
	FOR(i,0,N) cin>>l[i]>>r[i];
	init(N,l,r);
	int Q; cin>>Q;
	while(Q--){
		int M; cin>>M;
		int a[M]; FOR(i,0,M) cin>>a[i];
		if(can(M,a)) cout << 1 << endl;
		else cout << 0 << endl;
	}



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
