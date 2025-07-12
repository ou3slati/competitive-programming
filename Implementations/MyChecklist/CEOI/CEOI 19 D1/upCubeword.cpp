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

const int MOD = 998244353;
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

int mp(char c){
	if(c>='a' && c<='z') return (c-'a');
	if(c>='A' && c<='Z') return (c-'A')+26; 
	return (c-'0') + 52;
}

int permu(int a, int b, int c, int d){
	if(a==b && b==c && c==d) return 1;
	if((a==b && b==c) || (a==b && b==d) || (a==c && c==d) || (b==c && c==d)) return 4;
	if((a==b && c==d) || (a==c && b==d) || (a==d && b==c)) return 6;
	if(a==b || a==c || a==d || b==c || b==d || c==d) return 12;
	return 24;
}

int main() {
	boost; IO();

	int N; cin>>N;
	vs vec[11];
	FOR(i,0,N){
		str s; cin>>s;
		vec[sz(s)].pb(s);
		reverse(all(s));
		vec[sz(s)].pb(s);
	}

	FOR(x,3,11){
		sort(all(vec[x]));
		vec[x].erase(unique(all(vec[x])),vec[x].end());
	}
	

	ll ans=0;
	FOR(x,3,11){
		if(vec[x].empty()) continue;

		int cnt[62][62]; FOR(i,0,62) FOR(j,0,62) cnt[i][j]=0;
		for(auto s: vec[x]) cnt[mp(s[0])][mp(s.back())]++;

		ll D[62][62][62];
		FOR(i,0,62) FOR(j,i,62) FOR(k,j,62){
			D[i][j][k]=0;
			FOR(l,0,62){
				D[i][j][k]+=(((cnt[l][i]*cnt[l][j])%MOD)*cnt[l][k])%MOD;
				D[i][j][k]%=MOD;
			}
		}
		FOR(i,0,62) FOR(j,i,62) FOR(k,j,62) FOR(l,k,62){
			ll val=(((D[i][j][k]*D[i][j][l])%MOD)*((D[i][k][l]*D[j][k][l])%MOD))%MOD;
			val*=permu(i,j,k,l); val%=MOD;
			ans+=val; ans%=MOD;
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
