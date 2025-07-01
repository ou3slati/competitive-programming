/*
CF 680C - TBD
https://codeforces.com/contest/1445/problem/C

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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


vpi vec;
int power(int x, int p){
	int ans=1;
	while(p--) ans*=x;
	return ans;
}

void f(int v){
	vec.clear();
	for(int i=2; i*i<=v; i++) if(v%i==0){
		int cnt=0;
		while(v%i==0){
			cnt++;
			v/=i;
		}
		vec.pb({i,cnt});
	}
	if(v>1) vec.pb({v,1});
}

int cnt(int x, int q){
	int ans=0;
	while(x%q==0){
		ans++; x/=q;
	}
	return ans;
}

int32_t main() {
    boost; IO();


    int TC; cin>>TC;
    while(TC--){
    	int p,q; cin>>p>>q;
    	if(p%q!=0){
    		cout << p << endl;
    		continue;
    	}
    	vpi a;
    	f(q); a.assign(all(vec));

    	int ans=0;
    	for(auto x: a){
    		assert(cnt(p,x.fi)>=x.se);
    		ckmax(ans,p/(power(x.fi,cnt(p,x.fi)-x.se+1)));
    	}
    	cout << ans << endl;
    }
    

    return 0;
}

