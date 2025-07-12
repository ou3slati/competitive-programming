//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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

bool pal(str s){
	FOR(i,0,sz(s)/2) if(s[i]!=s[sz(s)-i-1]) return false;
	return true;
}

bool can(str a, int sd, str b){
	if(sd==0) reverse(all(b));
	else reverse(all(a));
	int x=min(sz(a),sz(b));
	b.resize(x); a.resize(x);
	return (a==b);
}

str combine(str a, int sd, str b){
	int x;
	if(sz(a)<=sz(b)){
		x=sz(a);
		while(x--) b.pop_back();
		return b;
	}
	else{
		x=sz(b);
		while(x--) a.pop_back();
		return a;
	}
}


int32_t main() {
	boost; IO();
	int N; cin>>N;
	vs a(N); vi c(N);
	FOR(i,0,N) cin>>a[i]>>c[i];


	map<pair<str,int>,int> dist;
	/*FOR(i,0,N){
		FOR(j,0,sz(a[i])){
			str cur;
			dist[{cur,1}]=dist[{cur,0}]=INF;
			FOR(k,j,sz(a[i])){
				cur+=a[i][k]; dist[{cur,1}]=dist[{cur,0}]=INF;
			}
		}
	}*/

	priority_queue<pair<int,pair<str,int>>,vector<pair<int,pair<str,int>>>,greater<pair<int,pair<str,int>>>> q;
	FOR(i,0,N){
		int x=INF;
		if(dist.count({a[i],0})) x=dist[{a[i],0}];
		dist[{a[i],0}]=dist[{a[i],1}]=min(x,c[i]);
		q.push({dist[{a[i],0}],{a[i],0}}); q.push({dist[{a[i],0}],{a[i],1}});
	}

	int ans=INF;
	while(!q.empty()){
		str s=q.top().se.fi; int side=q.top().se.se,d=q.top().fi;
		q.pop();
		int dd=INF; if(dist.count({s,side})) dd=dist[{s,side}];
		if(d>dd) continue;
		if(pal(s)){ans=min(ans,d);}

		FOR(i,0,N){
			if(!can(s,side,a[i])) continue;
			str ss=combine(s,side,a[i]);
			int sidep=(sz(s)>=sz(a[i]));
			dd=INF; if(dist.count({ss,sidep})) dd=dist[{ss,sidep}];
			if(dd>d+c[i]) {
				dist[{ss,sidep}]=d+c[i];
				q.push({d+c[i],{ss,sidep}});
			}
		}
	}

	if(ans==INF) cout << -1 << endl;
	else cout << ans << endl;




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
