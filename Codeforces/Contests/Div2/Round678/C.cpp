/*
CF 678C - Increase and Copy
https://codeforces.com/contest/1426/problem/C

Reach target using increment and copy operations
n ≤ 1e9

Key insights:
1. Balance increments and copies
2. Optimal solution near sqrt(n)
3. Try few values around sqrt
*/
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

int memo[5000][5000];

int C(int n, int p){
	if(p>n) return 0;
	if(p==0) return 1;
	if(memo[n][p]!=-1) return memo[n][p];

	return memo[n][p]=(C(n-1,p)+C(n-1,p-1))%MOD;
}

int32_t main() {
	boost; IO();

	
	int N,X,pos; cin>>N>>X>>pos;

	int comp[N]; FOR(i,0,N) comp[i]=-1;
	int l=0,r=N;
	while(l<r){
		int m=(l+r)/2;
		if(pos>m){
			comp[m]=0; //less or equal
			l=m+1;
		}
		else if(pos<m){
			comp[m]=1; //greater
			r=m;
		}
		else{
			l=m+1;
		}
	}

	int a=0,b=0;
	FOR(i,0,N){
		if(comp[i]==0) a++; 
		else if(comp[i]==1) b++;
	}

	memset(memo,-1,sizeof(memo));


	int permu[N+1]; permu[0]=1;
	FOR(i,1,N+1) permu[i]=permu[i-1]*i,permu[i]%=MOD;

	//dbgs(a,b);

	int ans=1;
	ans*=((C(X-1,a)*permu[a])%MOD); ans%=MOD;
	ans*=(C(N-X,b)*permu[b])%MOD; ans%=MOD;
	ans*=permu[N-a-b-1]; ans%=MOD;
	cout << ans << endl;



	return 0;
}

