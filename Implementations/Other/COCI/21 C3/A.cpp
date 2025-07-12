//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
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

V<pair<int,pi>> v;

void take(int side, int hand){
	v.pb({0,{side,hand}});
	
}

void put(int side, int hand){
	v.pb({1,{side,hand}});
}

int32_t main() {
    boost; IO();

  	int N; cin>>N;
  	vi a(N); multiset<int> s;

  	FOR(i,0,N){
  		cin>>a[i];
  		s.insert(a[i]);
	}
	reverse(all(a)); //a.back()==top();

	auto it=s.end(); it--;
	vi b;
	while(!a.empty()){
		take(0,0); put(1,0);
		b.pb(a.back());
		a.pop_back();
	}

	while(!s.empty()){
		auto it=s.end(); it--; 

		int taken=0;
		while(b.back()!=*it){
			take(1,0); put(0,0);
			a.pb(b.back());
			b.pop_back();
			taken++;
		}
		
		take(1,1); 
		int x=b.back();
		b.pop_back();
		while(taken--){
			take(0,0); put(1,0);
			b.pb(a.back());
			a.pop_back();
		}

		put(0,1);
		a.pb(x);
		s.erase(s.find(x));
	}

	cout << sz(v) << endl;
	for(auto x: v){
		int t=x.fi;
		int side=x.se.fi,hand=x.se.se;
		if(t==0){
			cout << "UZMI" << ' ';
			if(hand==0) cout << 'L' << ' ';
			else cout << 'D' << ' ';
			if(side==0) cout << 'L' << ' ';
			else cout << 'D' << ' ';
			cout << endl;
		}
		else{
			cout << "STAVI" << ' ';
			if(hand==0) cout << 'L' << ' ';
			else cout << 'D' << ' ';
			if(side==0) cout << 'L' << ' ';
			else cout << 'D' << ' ';
			cout << endl;
		}
	}



    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/