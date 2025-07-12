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
const int MX = 3e5 + 10;
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

int N,Q;
vi bit(MX,0);
int LOG;

int get(int i){
	int ans=0;
	while(i>0){
		ans+=bit[i];
		i-=i&-i;
	}
	return ans;
}

void update(int i, int v){
	while(i<MX){
		bit[i]+=v;
		i+=i&-i;
	}
}

void update_range(int l, int r){
	update(l,1);
	update(r+1,-1);
}


int main() {
	boost; IO();

	cin>>N>>Q; LOG=ceil(log2(N));
	vi a(N+1);
	FOR(i,1,N+1){
		cin>>a[i];
		a[i]=i-a[i];
	}

	//dbgv(a);

	vpi q[N+1];
	FOR(i,0,Q){
		int x,y; cin>>x>>y;
		q[N-y].pb({x+1,i});
	}

	int res[Q];
	int sum=0;
	FOR(i,1,N+1){
		if(a[i]>=0){
			int pos=0,x=sum;
			ROF(b,0,LOG+1) if(pos+((1)<<(b))<=i && x-bit[pos+((1)<<(b))]>=a[i]){
				pos+=((1)<<(b));
				x-=bit[pos];
			}
			sum++;
			for(int b=pos+1; b<=N; b+=b&-b) bit[b]++;
		}

		for(auto idx : q[i]){
			res[idx.se]=sum;
			for(int b=idx.fi; b>0; b-=b&-b){
				res[idx.se]-=bit[b];
			}
		}
	}

	FOR(i,0,Q) cout << res[i] << endl;






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
