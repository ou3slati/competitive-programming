//Never stop trying
//#include "biscuits.h"
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

ll K,x; 
ll a[65];

ll S=0;

unordered_map<ll,ll> memo[61];

ll solve(int i, ll r){
	if(i==60) return 1ll;
	if(memo[i].count(r)) return memo[i][r];
	ll ans=solve(i+1,(r+a[i])/2);
	if(r+a[i]>=x) ans+=solve(i+1,(r+a[i]-x)/2);
	return memo[i][r]=ans;
}

ll count_tastiness(ll xx, V<ll>aa){
	FOR(i,0,60) memo[i].clear(); S=0;
	K=sz(aa); FOR(i,0,K) a[i]=aa[i]; 
	FOR(i,0,K) S+=(ll)((ll)pow(2,i)+0.5)*a[i];
	x=xx;  
	
	aa.resize(60); FOR(i,K,60) a[i]=0; 
	if(S<=1e6){
		int ans=0;
		for(ll y=0; y<=S; y++){
			FOR(i,0,60) aa[i]=a[i];
			bool p=true;
			bitset <60> bs(y);
			FOR(i,0,60){
				if(bs[i]){
					if(aa[i]>=x) aa[i]-=x;
					else{p=false;}
				}
				if(!p) break;
				if(i<59) aa[i+1]+=aa[i]/2;
			}
			if(p) ans++;
		}
		//cout << ans << endl;
		return ans;
	}
	
	return solve(0,0);

}


int main() {
	boost; IO();


	cin>>K;
	cin>>x;
	ll xxx=1e18;
	V<ll> aaa(K); 
	FOR(i,0,K){
		cin>>aaa[i];
	}

	cout << count_tastiness(x,aaa) << endl;

	return 0;
}

/*

1 1
1257943
1 1
134678868
1 1
347896327953278421
3 1
1 1 1
58 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
58 1
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

*/
/*
1257944
134678869
347896327953278422
8
288230376151711744
576460752303423487

*/


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
