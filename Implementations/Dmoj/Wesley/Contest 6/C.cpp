//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

int N;
vi a;

vi t(MX*4,0);

void upd(int i, int v, int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]=v;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) upd(i,v,pos*2,l,m);
	else upd(i,v,pos*2+1,m+1,r);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr){
		return t[pos];
	}
	int tm=(tl+tr)/2;
	return max( get(l,min(r,tm),pos*2,tl,tm), 
		get(max(l,tm+1),r,pos*2+1,tm+1,tr) );
}

int solve(){
	vi s,cur; 
	s.assign(all(a)); sort(all(s));
	cur.assign(all(a));

	FOR(i,0,N-1) upd(i,s[i+1]-s[i]);

	int ans=0;
	FOR(i,0,N) if(cur[i]!=s[i]){
		int x=cur[i],y=s[i];
		if(x>y) swap(x,y);
		auto it=lower_bound(all(s),x)-s.begin();
		auto it2=lower_bound(all(s),y)-s.begin(); it2--;
		ckmax(ans,get(it,it2));
	}
	return ans;
}


int32_t main() {
    boost; IO();

    cin>>N;
    a.resize(N);
    FOR(i,0,N) cin>>a[i];

    cout << solve() << endl;
    

    return 0;
}
//Change your approach 