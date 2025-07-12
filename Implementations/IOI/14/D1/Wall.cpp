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

#ifndef LOCAL
#include "wall.h"
#endif

void buildWall(int N, int Q, int op[], int L[], int R[], int H[], int fH[]){
	if(N<=10000 && Q<=5000){
		FOR(i,0,N) fH[i]=0;
		FOR(i,0,Q){
			int l=L[i],r=R[i],h=H[i];
			if(op[i]==1){
				FOR(j,l,r+1) ckmax(fH[j],h);
			}
			else{
				FOR(j,l,r+1) ckmin(fH[j],h);
			}

		}
		return;
	}

	vi add,rmv,ans(N,0);
	FOR(i,0,Q) 
		if(op[i]==1) add.pb(i);
		else rmv.pb(i);


	vpi vec[N+1];
	for(auto i: add){
		int l=L[i],r=R[i],h=H[i];
		vec[l].eb(1,h);
		vec[r+1].eb(-1,h);
	}
	multiset<int>s;
	FOR(i,0,N){
		for(auto it: vec[i]){
			if(it.fi==1) s.insert(it.se);
			else s.erase(s.find(it.se));
		}
		auto it=s.end();
		if(it!=s.begin()){
			it--;
			ans[i]=*it;
		}
	}

	//FOR(i,0,N) cout << ans[i] << ' '; cout << endl;

	FOR(i,0,N) vec[i].clear();
	s.clear();

	for(auto i: rmv){
		int l=L[i],r=R[i],h=H[i];
		vec[l].eb(1,h);
		vec[r+1].eb(-1,h);
	}
	FOR(i,0,N){
		for(auto it: vec[i]){
			if(it.fi==1) s.insert(it.se);
			else s.erase(s.find(it.se));
		}
		if(sz(s)){
			auto it=s.begin();
			ckmin(ans[i],*it);
		}
	}
	FOR(i,0,N) fH[i]=ans[i];

	//FOR(i,0,N) cout << fH[i] << ' '; cout << endl;

	return;
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N,Q; cin>>N>>Q;
    int op[Q],l[Q],r[Q],h[Q],fH[N];
    FOR(i,0,Q) cin>>op[i]>>l[i]>>r[i]>>h[i];
    buildWall(N,Q,op,l,r,h,fH);
    

    return 0;
}
#endif
//Change your approach 