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
//#define endl "\n"

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

/*bool check(int x){
	cout << "? " << 1 << endl;
	std::cout << std::endl;
	int v; cin>>v;
	cout << "? " << 1+x << endl;
	std::cout << std::endl;
	cin>>v;
	return v;
	//return x>=4;
}

void init(){
	cout << "? " << 1 << endl;
	std::cout << std::endl;
	int x; cin>>x;
}*/


pi arr[MX];
int last=0;

int query(int x){
	last=x;
	cout << "? " << x << endl;
	std::cout << std::endl;
	int res; cin>>res;
	return res;

	//return x>=4;
	/*cout << x << endl;
	int res=abs(x-last)>=4;
	last=x;
	return res;*/
}

int check(int x){
	int a=arr[x].fi,b=arr[x].se;
	int v=query(a);
	v=query(b);
	//cout << x << ' ' << v << endl;
	return v;
}



int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	while(TC--){
		int N; cin>>N;
		if(N>1000) return 0;
		vi a(N); FOR(i,0,N) a[i]=i+1;
		vi vec;
		int i=0,j=N-1;
		while(i<=j){
			vec.pb(a[i]); 
			if(i!=j) vec.pb(a[j]);
			i++;
			j--;
		}

		//for(auto x: vec) cout << x << ' '; cout << endl;	
		FOR(i,0,N){
			/*int x;
			x=query(vec[i]);*/
			if(i) arr[abs(vec[i]-vec[i-1])]={vec[i-1],vec[i]};
		}

		//FOR(i,1,N+1) cout << arr[i].fi << ' ' << arr[i].se << endl;

		int l=1,r=N-1;
		int ans=N;
		int lst=0;
		while(r-l+1>6){
			int m=(l+r)/2;
			//cout << l << ' ' << r << endl;
			//if(m==last) m=(l+r+1)/2;
			if(check(m)){
				ans=m;
				r=m-1;
				lst=1;
			}
			else l=m+1,lst=0;
		}

		//cout << l << ' ' << r << endl;

		//for(int i=N; i>=1; i--) cout << arr[i].fi << ' ' << arr[i].se << endl;
		//int xx=query(arr[r].fi);
		for(int i=r; i>=l; i--){
			int x=query(arr[i].se);
			if(x==1) ans=i;
		}

		
		cout << "= " << ans << endl;
		std::cout << std::endl;
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
