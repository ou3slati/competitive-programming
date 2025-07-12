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
const int MX = 1e6 + 10;
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

int N; 
int arr[MX];

int query(int idx, int x){
	/*cout << "? " << i << ' ' << x << endl;
	cout.flush();
	int res; cin>>res;
	return res;*/
	vi vec;
	FOR(i,1,N+1){
		vec.pb(arr[i]);
	}
	idx--;

	vec.insert(vec.begin()+idx,x);
	int ans=0;
	FOR(i,0,sz(vec)) FOR(j,i+1,sz(vec)) if(vec[i]>vec[j]) ans++;
	return ans;
}

vi bit(MX,0);

void update(int i){
	for(;i<MX;i+=i&-i) bit[i]+=1;
}

int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}

int get_greater(int x){
	return get(1e6)-get(x);
}

int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	while(TC--){
		cin>>N;
		FOR(i,1,N+1) cin>>arr[i];

		int res[N+1];
		int X=query(N+1,1000000);
		//cout << X << endl;
		FOR(i,1,N+1){
			int l=1,r=1e6;
			int ans;
			while(l<=r){
				int m=(l+r)/2;
				//cout << query(i+1,m) << endl;
				if(query(i+1,m)-get_greater(m)>X){
					ans=m; l=m+1;
				}
				else r=m-1;
			}

			res[i]=ans+1;
			update(res[i]);
		}

		FOR(i,1,N+1) cout << res[i] << ' '; cout << endl;
		cout.flush();
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
