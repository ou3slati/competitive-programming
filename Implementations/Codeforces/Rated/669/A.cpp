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


int main() {
	boost; IO();

	int TC=1; cin>>TC;
	while(TC--){
		int N; cin>>N;
		//int s=0;
		//vi a(N);
		int a=0,b=0;
		FOR(i,0,N){
			int x; cin>>x;
			if(x==1) a++;
			else b++;
		}
		int x=0;
		if(a>b) x=1;
		vi vec;
		FOR(i,0,N/2) vec.pb(x);
		if(x==1 && (N/2)%2==1){
			//	if(a-N/2>0) 
			vec.pb(1);
			//else vec.pop_back(),vec.pb(0);
		}	
		cout << sz(vec) << endl;
		for(auto it: vec) cout << it << ' '; cout << endl;
		/*for(int i=0; i<N; i+=2){
			s+=a[i]-a[i+1];
		}
		vi vec;
		for(int i=0; i<N; i+=2){
			if(s>0 && a[i]==1 && a[i+1]==0){
				s--;
				continue;
				
			}
			if(s<0 && a[i]==0 && a[i+1]==1){
				s++;
				continue;
			}
			vec.pb(a[i]); vec.pb(a[i+1]);

		}
		if(sz(vec)==0) vec.pb(0);
		cout << sz(vec) << endl;
		for(auto x: vec) cout << x << ' '; cout << endl;*/
		

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
