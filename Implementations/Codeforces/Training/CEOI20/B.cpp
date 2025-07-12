//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
V<pair<pi,pi>> cord;

bool sub1(){
	for(int i=0; i<N; i++) if(cord[i].fi.fi!=cord[i].se.fi) return false;
	return true;
}

bool cmp(pair<ld,pair<pi,pi>> a, pair<ld,pair<pi,pi>> b){
	if(a.fi!=b.fi) return a.fi<b.fi;
	return a.se.fi.fi<b.se.fi.fi;
}

int main() {
	boost; IO();
	setprecision(20);
	cin>>N;
	
	FOR(i,0,N){
		int x,y,xx,yy; cin>>x>>y>>xx>>yy;

		if(y>yy){
			swap(y,yy); swap(x,xx);
		}
		cord.pb({{x,y},{xx,yy}});
	}

	if(sub1()){
		sort(all(cord));
		for(int i=0; i<N-1; i++){
			cout << cord[i].se.fi << ' ' << cord[i].se.se << ' ' << cord[i+1].fi.fi << ' ' << cord[i+1].fi.se << endl;
		}
	}
	else{
		vector<pair<ld,pair<pi,pi>>> vec;
		for(int i=0; i<N; i++){
			int x=cord[i].fi.fi,y=cord[i].fi.se,xx=cord[i].se.fi,yy=cord[i].se.se;
			//if(x==xx){return 0;}
			ld a=(yy-y)/(xx-x),c=(ld)yy-a*xx;
			
			/*if(x>xx){
				swap(x,xx); swap(y,yy);
			}*/
			
			vec.pb({c,{{x,y},{xx,yy}}});
		}
		sort(all(vec),cmp);	
		for(int i=0; i<N-1; i++){
			cout << vec[i].se.se.fi << ' ' << vec[i].se.se.se << ' ' << vec[i+1].se.fi.fi << ' ' << vec[i+1].se.fi.se << endl;
		}
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
