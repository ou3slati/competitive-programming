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
#include "messy.h"
#endif

int N;
vi p;

#ifdef LOCAL
V<str>vec;
void add_element(str s){
	vec.pb(s);
}

set<str>st;
void compile_set(){
	for(auto x: vec){
		str cur;
		FOR(i,0,N) cur.pb(x[p[i]]);
		st.insert(cur);
	}
}
bool check_element(str s){
	return st.count(s);
}
#endif


void precompute(int l, int r){
	if(l==r) return;

	int m=l+(r-l-1)/2;

	str s(N,'1');
	FOR(i,l,r+1) s[i]='0';
	FOR(i,l,m+1){
		s[i]='1';
		add_element(s);
		s[i]='0';
	}

	precompute(l,m);
	precompute(m+1,r);
}

void solve(int l, int r, vi vec){
	if(l==r){
		p[vec[0]]=l;
		return;
	}

	str s(N,'1');
	for(int i: vec) s[i]='0';
	vi lft,rgt;
	for(int i: vec){
		s[i]='1';
		if(check_element(s)) lft.pb(i);
		else rgt.pb(i);
		s[i]='0';
	}

	int m=l+(r-l-1)/2;
	solve(l,m,lft);
	solve(m+1,r,rgt);
}

vi restore_permutation(int n, int w, int r) {
	N=n; p.resize(N);
	
	vi v(N); iota(all(v),0);
	precompute(0,N-1);
	compile_set();
	solve(0,N-1,v);
	return p;
}	


#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    p.resize(N);
    iota(all(p),0);
    random_shuffle(all(p));
    dbgv(p)
    vi v=restore_permutation(N,0,0);
    dbgv(v)
    

    return 0;
}
#endif
//Change your approach 