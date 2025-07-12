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

int N; 
vi a; 

struct Tree {
	int N; 
	vi a,t;
	Tree(int N, vi vec){
		a=vec; N=sz(a); 
		t.resize(N*4); 
		build(0,N-1,1); 
	}


	void build(int l, int r, int pos){
		if(l==r){
			t[pos]=a[l];
			return; 
		}

		int m=(l+r)/2; 
		build(l,m,pos*2); 
		build(m+1,r,pos*2+1); 

		t[pos]=max(t[pos*2], t[pos*2+1]); 
	}

	int query(int l, int r, int tl, int tr, int pos){
		if(l>r) return 0; 

		if(l==tl && r==tr) return t[pos]; 

		int tm=(tl+tr)/2; 

		return max(query(l,min(r,tm),tl,tm,pos*2), query(max(l,tm+1),r,tm+1,tr,pos*2+1)); 
	}

}; 

int main() {
    boost; IO();

    cin>>N; a.resize(N); 
    FOR(i,0,N) cin>>a[i]; 

    Tree A(N,a); 
    
    int l,r; cin>>l>>r; 
    cout << A.query(l,r,0,N-1,1) << endl;  


    FOR(i,0,N) cin>>a[i]; 

    Tree B(N,a); 

    cout << B.query(l,r,0,N-1,1) << endl;  

    return 0;
}
//Change your approach 