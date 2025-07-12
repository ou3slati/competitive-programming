//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
 #define int ll
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


int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	while(TC--){
		int N; cin>>N;
		str s; cin>>s;
		
		set<pi> st;
		set<int> one;
		int cnt=0;

		FOR(i,0,N){
			if(i==0 || (i && s[i]==s[i-1])) cnt++;
			else{
				if(cnt==1) one.insert(i-1);
				else st.insert({i-cnt,cnt});
				cnt=1;
			}
		}
		if(cnt!=1) st.insert({N-cnt,cnt});
		else one.insert(N-1);
		/*for(auto x: st) cout << x.fi << ' ' << x.se << endl;
		for(auto x: one) cout << x << ' '; cout << endl;*/

		int ans=0;
		while(sz(st)||sz(one)){
			ans++;
			//Remove leftmost one
			int ss=0,mn=INF;
			if(!st.empty()){
				auto it=st.begin();
				ckmin(mn,(*it).fi);
			}
			if(!one.empty()){
				auto it=one.begin();
				if(ckmin(mn,(*it))) ss=1;
			}
			if(ss==0) st.erase(st.begin());
			else one.erase(one.begin());

			//Remove leftmost one containing >1 (if possible) if the removed 
			//previously is of sz 1

			if(ss==1){
				if(sz(st)){
					auto it=st.begin();
					pi nw=(*it);
					nw.se--;
					st.erase(it);
					if(nw.se==1) one.insert(nw.fi);
					else st.insert(nw);
				}
				else if(sz(one)) one.erase(one.begin());
			}
		}
		cout << ans << endl;
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

