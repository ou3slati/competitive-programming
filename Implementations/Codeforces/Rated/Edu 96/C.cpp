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

		cout << 2 << endl;
		multiset <int> s;
		FOR(i,1,N+1) s.insert(i);

		if(N==2){
			cout << 1 << ' ' << 2 << endl;
			continue;
		}

		while(sz(s)>1){
			auto it=s.end();
			it--;
			int x=(*it); it--;
			while((*it)%2!=x%2){
				assert(it!=s.begin());
				it--;
			}
			s.insert((x+(*it)+1)/2);
			cout << x << ' ' << (*it) << endl;
			s.erase(it);
			s.erase(s.find(x));

		}

		/*multiset<int> odd,even;
		FOR(i,1,N+1){
			if(i%2) odd.insert(i);
			else even.insert(i);
		}*/

		//dbgv(even);

		/*while(!(sz(odd)<=1 && sz(even)<=1)){
			if(sz(even)>1){
				auto it=even.begin();
				int x=(*it);
				even.erase(it);

				auto itr=even.begin();
				int y=(*itr);
				even.erase(itr);

				x=(x+y)/2;
				if(x%2) odd.insert(x);
				else even.insert(x);
			}
			else{
				auto it=odd.begin();
				int x=(*it);
				odd.erase(it);

				auto itr=odd.begin();
				int y=(*itr);
				odd.erase(itr);

				x=(x+y)/2;
				if(x%2) odd.insert(x);
				else even.insert(x);
			}
		}


		auto it=even.begin();
		auto itr=odd.begin();
		//cout << *it << ' ' << *itr << endl;
		cout << (*it+*itr+1)/2 << endl;*/
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
