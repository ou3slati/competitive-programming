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

int N;
vi a(MX);
int v[MX]; 

int XOR(int x, int y){
	#ifdef LOCAL
	return ((a[x])^(a[y]));
	#endif
	cout << "XOR " << x << ' ' << y << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}
int AND(int x, int y){
	#ifdef LOCAL
	return ((a[x])&(a[y]));
	#endif
	cout << "AND " << x << ' ' << y << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}
int OR(int x, int y){
	#ifdef LOCAL
	return ((a[x])|(a[y])); 
	#endif
	cout << "OR " << x << ' ' << y << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}

int find_XOR(int i, int j){
	return ((v[i])^(v[j]));
}

int32_t main() {
    boost; IO();

    cin>>N;

    #ifdef LOCAL
    FOR(i,1,N+1) cin>>a[i];
    #endif

    v[1]=0;
    vi h(N,-1);
    int j=-1,k;
    FOR(i,2,N+1){
    	v[i]=XOR(1,i);
    	if(v[i]==0){
    		j=1; k=i;
    	}
    	else if(h[v[i]]!=-1){
    		j=h[v[i]],k=i;
    	}
    	h[v[i]]=i;
	}

	vi ans(N+1);
	if(j!=-1){
		ans[j]=ans[k]=AND(j,k);
		FOR(i,1,N+1) if(i!=j && i!=k){
			ans[i]=(ans[j])^(find_XOR(i,j));
		}
	}
	else{
		int i,j,k; //j&k are equal

		vi h(N,-1);
		FOR(i,1,N+1){
			int idx=h[((v[i])^(N-1))];
			if(idx!=-1) j=idx,k=i;
			h[v[i]]=i;
		}
		i=1;
		if(j==1 || k==1){
			i=2;
			if(j==2 || k==2) i=3;
		}

		int ab=find_XOR(i,j) + 2*AND(i,j);
		int ac=find_XOR(i,k) + 2*AND(i,k);
		int bc=find_XOR(j,k);
		ans[i]=(ab+ac-bc)/2;

		FOR(ii,1,N+1) if(ii!=i){
			ans[ii]=(ans[i])^(find_XOR(ii,i));
		}

	}

	cout << '!' << ' ';
    FOR(i,1,N+1) cout << ans[i] << ' '; 
    cout << endl;
    cout.flush();

    

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