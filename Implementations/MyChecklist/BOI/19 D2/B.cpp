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
const int MX = 3000 + 10;
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

int N,M;
str S,T; 
vi PS,SP;

int ans=-1,idx1,idx2;
void solve(int i){

	//Suf
	FOR(j,0,M){
		int len=min(N-i,M-j);
		int l=1,r=len,v=0;
		while(l<=r){
			int m=(l+r)/2;
			if(h(i,i+m-1)==h(j,j+m-1)){
				v=m;
				l=m+1;
			}
			else r=m-1;
		}
		if(v) ckmax(PS[j+v-1],v);
	}
	ROF(i,0,M-1) ckmax(PS[i],PS[i+1]-1);

	if(i){
		//pref
		FOR(j,0,M){
			int len=min(i,j+1);
			int l=1,r=len,v=0;
			while(l<=r){
				int m=(l+r)/2;
				if(h(i-m,i-1)==h(j-m+1,j)){
					v=m;
					l=m+1;
				}
				else r=m-1;
			}
			if(v) ckmax(SP[j-v+1],v);
		}
		FOR(i,1,M) ckmax(SP[i],SP[i-1]-1);
	}

	ans=-INF;
	FOR(j,0,M){
		if(ckmax(ans,PS[j]+SP[j]-1));
	}
}

int main() {
    boost; IO();

    cin>>S>>T;
    N=sz(S); M=sz(T);
    

    return 0;
}
//Change your approach 